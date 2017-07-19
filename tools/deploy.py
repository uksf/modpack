#!/usr/bin/env python3
import os
import sys
import shutil
import subprocess
import getpass
import zipfile
import ftplib
import rpyc

# Copyright (c) André Burgaud
# http://www.burgaud.com/bring-colors-to-the-windows-console-with-python/
if sys.platform == "win32":
    from ctypes import windll, Structure, c_short, c_ushort, byref

    SHORT = c_short
    WORD = c_ushort

    class COORD(Structure):
      """struct in wincon.h."""
      _fields_ = [
        ("X", SHORT),
        ("Y", SHORT)]

    class SMALL_RECT(Structure):
      """struct in wincon.h."""
      _fields_ = [
        ("Left", SHORT),
        ("Top", SHORT),
        ("Right", SHORT),
        ("Bottom", SHORT)]

    class CONSOLE_SCREEN_BUFFER_INFO(Structure):
      """struct in wincon.h."""
      _fields_ = [
        ("dwSize", COORD),
        ("dwCursorPosition", COORD),
        ("wAttributes", WORD),
        ("srWindow", SMALL_RECT),
        ("dwMaximumWindowSize", COORD)]

    # winbase.h
    STD_INPUT_HANDLE = -10
    STD_OUTPUT_HANDLE = -11
    STD_ERROR_HANDLE = -12

    # wincon.h
    FOREGROUND_BLACK     = 0x0000
    FOREGROUND_BLUE      = 0x0001
    FOREGROUND_GREEN     = 0x0002
    FOREGROUND_CYAN      = 0x0003
    FOREGROUND_RED       = 0x0004
    FOREGROUND_MAGENTA   = 0x0005
    FOREGROUND_YELLOW    = 0x0006
    FOREGROUND_GREY      = 0x0007
    FOREGROUND_INTENSITY = 0x0008 # foreground color is intensified.

    BACKGROUND_BLACK     = 0x0000
    BACKGROUND_BLUE      = 0x0010
    BACKGROUND_GREEN     = 0x0020
    BACKGROUND_CYAN      = 0x0030
    BACKGROUND_RED       = 0x0040
    BACKGROUND_MAGENTA   = 0x0050
    BACKGROUND_YELLOW    = 0x0060
    BACKGROUND_GREY      = 0x0070
    BACKGROUND_INTENSITY = 0x0080 # background color is intensified.

    stdout_handle = windll.kernel32.GetStdHandle(STD_OUTPUT_HANDLE)
    SetConsoleTextAttribute = windll.kernel32.SetConsoleTextAttribute
    GetConsoleScreenBufferInfo = windll.kernel32.GetConsoleScreenBufferInfo

    def get_text_attr():
        """Returns the character attributes (colors) of the console screen
        buffer."""
        csbi = CONSOLE_SCREEN_BUFFER_INFO()
        GetConsoleScreenBufferInfo(stdout_handle, byref(csbi))
        return csbi.wAttributes

    def set_text_attr(color):
        """Sets the character attributes (colors) of the console screen
        buffer. Color is a combination of foreground and background color,
        foreground and background intensity."""
        SetConsoleTextAttribute(stdout_handle, color)
###############################################################################

def color(color):
    """Set the color. Works on Win32 and normal terminals."""
    if sys.platform == "win32":
        if color == "green":
            set_text_attr(FOREGROUND_GREEN | get_text_attr() & 0x0070 | FOREGROUND_INTENSITY)
        elif color == "yellow":
            set_text_attr(FOREGROUND_YELLOW | get_text_attr() & 0x0070 | FOREGROUND_INTENSITY)
        elif color == "red":
            set_text_attr(FOREGROUND_RED | get_text_attr() & 0x0070 | FOREGROUND_INTENSITY)
        elif color == "blue":
            set_text_attr(FOREGROUND_BLUE | get_text_attr() & 0x0070 | FOREGROUND_INTENSITY)
        elif color == "reset":
            set_text_attr(FOREGROUND_GREY | get_text_attr() & 0x0070)
        elif color == "grey":
            set_text_attr(FOREGROUND_GREY | get_text_attr() & 0x0070)
    else:
        if color == "green":
            sys.stdout.write('\033[92m')
        elif color == "red":
            sys.stdout.write('\033[91m')
        elif color == "blue":
            sys.stdout.write('\033[94m')
        elif color == "reset":
            sys.stdout.write('\033[0m')

def print_error(msg):
    color("red")
    print("ERROR: {}".format(msg))
    color("reset")

def print_red(msg):
    color("red")
    print(msg)
    color("reset")

def print_green(msg):
    color("green")
    print(msg)
    color("reset")

def print_blue(msg):
    color("blue")
    print(msg)
    color("reset")

def print_yellow(msg):
    color("yellow")
    print(msg)
    color("reset")

file_zip = ""
AUTH_ERROR = "1".encode()
AUTH_SUCCESS = "0".encode()
upload_total = 0
upload_progress = 0

def upload_callback(data):
    global upload_progress

    upload_progress += len(data)
    percent = float(upload_progress) / upload_total
    print("\r{}%".format(int(round(percent * 100))), end='', flush=True)

def upload_zip():
    global upload_total

    try:
        password = getpass.getpass("FTP password:")
        print("Connecting...")
        session = ftplib.FTP("uk-sf.com", "main", password)
        print("Connected to FTP")

        print("Switching to deploy directory...")
        session.cwd("/Users/root/Desktop/Deploy")
        print("Switched to: {}".format(session.pwd()))

        print_blue("\nUploading {}".format(file_zip))
        upload_total = os.path.getsize(file_zip)
        file_send = open(os.path.abspath(file_zip), "rb")
        session.storbinary("STOR {}".format(file_zip), file_send, 1024, upload_callback)
        file_send.close()
        print("\n")
        session.quit()
    except ftplib.all_errors as e:
        print_error(e)
        raise Exception

class CallbackService(rpyc.Service):
    def exposed_print(self, message):
        print(message)

    def exposed_print_blue(self, message):
        print_blue(message)

deploy_all = False
deploy_update = False
deploy_build = False
deploy_sync = False
deploy_cleanup = False

def remote_deploy():
    print_blue("\nStarting remote deploy")
    try:
        password = getpass.getpass("Connection password:")
        print("Connecting...")
        channel = rpyc.Channel(rpyc.SocketStream.connect("uk-sf.com", 18812))
        channel.send(password.encode())
        response = channel.recv()
        if response == AUTH_ERROR:
            raise ValueError("Incorrect password")
        client = rpyc.utils.factory.connect_channel(channel, service=CallbackService)
        print("Connected to uk-sf.com")

        if deploy_all:
            print_blue("\nExtracting remote {}".format(file_zip))
            client.root.extract_zip(file_zip)

        if deploy_all or deploy_update:
            print_blue("\nUpdating repo")
            client.root.update_repo(file_zip)

        if deploy_all or deploy_build:
            print_blue("\nBuilding repo")
            client.root.build_repo()

        if deploy_all or deploy_sync:
            print_blue("\nUpdating server")
            client.root.update_server()

        if deploy_all or deploy_cleanup:
            print_blue("\nCleaning up")
            client.root.cleanup(file_zip)

        client.close()

    except Exception as e:
        client.close()
        print_error(e)
        raise Exception

def deploy_to_server(argv):
    global deploy_all
    global deploy_update
    global deploy_build
    global deploy_sync
    global deploy_cleanup
    global file_zip

    print("""
###############
# UKSF Deploy #
###############
""")
    if len(argv) == 0:
        deploy_all = True
    else:
        if "update" in argv:
            argv.remove("update")
            deploy_update = True
        if "build" in argv:
            argv.remove("build")
            deploy_build = True
        if "sync" in argv:
            argv.remove("sync")
            deploy_sync = True
        if "cleanup" in argv:
            argv.remove("cleanup")
            deploy_cleanup = True

    try:
        # Find the zip file (there should only be one when make is run)
        os.chdir(os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), "release"))
        for file in os.listdir():
            if file.endswith(".zip"):
                file_zip = file
                break

        if file_zip != "":
            print_blue("Using {}".format(file_zip))
        else:
            print_error("No zip found")
            raise Exception

        if deploy_all:
            upload_zip()

        remote_deploy()
        print_green("\n# Deploy Complete")
    except:
        print_red("\n# Deploy Failed")

if __name__ == "__main__":
    sys.exit(deploy_to_server(sys.argv))
