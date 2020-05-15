#!/usr/bin/env python3

import sys
import os
import os.path
import subprocess

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
    FOREGROUND_BLACK = 0x0000
    FOREGROUND_BLUE = 0x0001
    FOREGROUND_GREEN = 0x0002
    FOREGROUND_CYAN = 0x0003
    FOREGROUND_RED = 0x0004
    FOREGROUND_MAGENTA = 0x0005
    FOREGROUND_YELLOW = 0x0006
    FOREGROUND_GREY = 0x0007
    FOREGROUND_INTENSITY = 0x0008  # foreground color is intensified.

    BACKGROUND_BLACK = 0x0000
    BACKGROUND_BLUE = 0x0010
    BACKGROUND_GREEN = 0x0020
    BACKGROUND_CYAN = 0x0030
    BACKGROUND_RED = 0x0040
    BACKGROUND_MAGENTA = 0x0050
    BACKGROUND_YELLOW = 0x0060
    BACKGROUND_GREY = 0x0070
    BACKGROUND_INTENSITY = 0x0080  # background color is intensified.

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


def sign_dependencies():
    print_blue("\nSigning dependencies")

    intercept_path = os.path.join(module_root_parent, "@intercept\\addons")
    signatures_path = os.path.join(release_dir, "@uksf_dependencies\\addons")
    if not os.path.isdir(signatures_path):
        try:
            os.makedirs(signatures_path)
        except:
            print_error("Cannot create dependencies directory")
            raise

    for file in os.listdir(signatures_path):
        if (file.endswith(".bisign") and os.path.isfile(os.path.join(signatures_path, file))):
            if (os.path.splitext(os.path.basename(key))[0] not in file):
                os.remove(os.path.join(signatures_path, file))

    temp_path = os.path.join(release_dir, "signatures")
    if not os.path.isdir(temp_path):
        try:
            os.makedirs(temp_path)
        except:
            print_error("Cannot create temp directory")
            raise

    for file in os.listdir(dependencies_path):
        if (file.endswith(".bisign") and os.path.isfile(os.path.join(dependencies_path, file))):
            shutil.move(os.path.join(dependencies_path, file), os.path.join(temp_path, file))

    for file in os.listdir(dependencies_path):
        if (file.endswith(".pbo") and os.path.isfile(os.path.join(dependencies_path, file))
            and not os.path.isfile(os.path.join(signatures_path, file))
                and not os.path.isfile(os.path.join(signatures_path, "{}.delete".format(os.path.basename(file))))):
            if (key):
                if (not os.path.isfile(os.path.join(signatures_path, "{}.{}.bisign".format(file, os.path.splitext(os.path.basename(key))[0])))):
                    print("Signing {} with {}.".format(file, key))
                    ret = subprocess.call([dssignfile, key, os.path.join(dependencies_path, "{}".format(file))])
                    if ret == 1:
                        return 1

    for file in os.listdir(dependencies_path):
        if (file.endswith(".bisign") and os.path.isfile(os.path.join(dependencies_path, file))):
            shutil.move(os.path.join(dependencies_path, file), os.path.join(signatures_path, file))

    for file in os.listdir(temp_path):
        shutil.move(os.path.join(temp_path, file), os.path.join(dependencies_path, file))

    print_blue("\nSigning intercept")
    for file in os.listdir(intercept_path):
        if (file.endswith(".bisign") and os.path.isfile(os.path.join(intercept_path, file))):
            os.remove(os.path.join(intercept_path, file))
    for file in os.listdir(intercept_path):
        if (file.endswith(".pbo") and os.path.isfile(os.path.join(intercept_path, file))):
            print("Found: {}.".format(file))
            if (os.path.isfile(os.path.join(intercept_path, "{}.{}.bisign".format(file, os.path.splitext(os.path.basename(key))[0])))):
                os.remove(os.path.join(intercept_path, "{}.{}.bisign".format(file, os.path.splitext(os.path.basename(key))[0])))
            if (key):
                print("Signing with: {}.".format(key))
                ret = subprocess.call([dssignfile, key, os.path.join(intercept_path, "{}".format(file))])
                if ret == 1:
                    return 1

    deployment_folder_f35 = os.path.join("D:\\Dev\\f35\\release\\@uksf_f35")
    print_blue("\nCopy F-35")
    for file in os.listdir(os.path.join(deployment_folder_f35, "addons")):
        if (file.endswith(".pbo")):
            print("     Found PBO to update: {}".format(file))
            shutil.copy(os.path.join(deployment_folder_f35, "addons", file), os.path.join(signatures_path, file))
            print("     Updated: {}".format(os.path.join(signatures_path, file)))

    print_blue("\nSigning updated dependencies")
    for file in os.listdir(signatures_path):
        if (file.endswith(".pbo") and os.path.isfile(os.path.join(signatures_path, file))):
            print("Found: {}.".format(file))
            if (os.path.isfile(os.path.join(signatures_path, "{}.{}.bisign".format(file, os.path.splitext(os.path.basename(key))[0])))):
                os.remove(os.path.join(signatures_path, "{}.{}.bisign".format(file, os.path.splitext(os.path.basename(key))[0])))
            if (key):
                print("Signing with: {}.".format(key))
                ret = subprocess.call([dssignfile, key, os.path.join(signatures_path, "{}".format(file))])
                if ret == 1:
                    return 1

    shutil.rmtree(temp_path)

    return 0


def main(argv):
    global dependencies_path

    if "path" in argv:
        dependencies_path = argv[argv.index("path") + 1]
        argv.remove("path")
        argv.remove(dependencies_path)
    else:
        sys.exit(0)

    ret = sign_dependencies()
    if ret == 0:
        print_blue("\nDependencies signed")
    else:
        print_error("Could not sign dependencies")


if __name__ == "__main__":
    main(sys.argv)
