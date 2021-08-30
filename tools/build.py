#!/usr/bin/env python3

import os
import sys
import subprocess

######## GLOBALS #########
MAINPREFIX = "u"
PREFIX = "uksf_"
##########################

def tryHemttBuild(projectpath):
    hemttExe = os.path.join(projectpath, "hemtt.exe")
    if os.path.isfile(hemttExe):
        os.chdir(projectpath)
        ret = subprocess.call([hemttExe, "pack"], stderr=subprocess.STDOUT)
        return True
    else:
        print("hemtt not installed");
    return False

def mod_time(path):
    if not os.path.isdir(path):
        return os.path.getmtime(path)
    maxi = os.path.getmtime(path)
    for p in os.listdir(path):
        maxi = max(mod_time(os.path.join(path, p)), maxi)
    return maxi


def check_for_changes(addonspath, module):
    if not os.path.exists(os.path.join(addonspath, "{}{}.pbo".format(PREFIX,module))):
        return True
    return mod_time(os.path.join(addonspath, module)) > mod_time(os.path.join(addonspath, "{}{}.pbo".format(PREFIX,module)))

def check_for_obsolete_pbos(addonspath, file):
    module = file[len(PREFIX):-4]
    if not os.path.exists(os.path.join(addonspath, module)):
        return True
    return False

def main(argv):
    print("""
#####################
# UKSF Debug Build #
#####################
""")
    compile_extensions = False
    if "compile" in argv:
        argv.remove("compile")
        compile_extensions = True

    scriptpath = os.path.realpath(__file__)
    projectpath = os.path.dirname(os.path.dirname(scriptpath))
    addonspath = os.path.join(projectpath, "addons")
    extensionspath = os.path.join(projectpath, "extensions")

    if (not tryHemttBuild(projectpath)):
        os.chdir(addonspath)

        made = 0
        failed = 0
        skipped = 0
        removed = 0

        for file in os.listdir(addonspath):
            if os.path.isfile(file):
                if check_for_obsolete_pbos(addonspath, file):
                    removed += 1
                    print("  Removing obsolete file => " + file)
                    os.remove(file)
        print("")

        for p in os.listdir(addonspath):
            path = os.path.join(addonspath, p)
            if not os.path.isdir(path):
                continue
            if p[0] == ".":
                continue
            if not check_for_changes(addonspath, p):
                skipped += 1
                print("  Skipping {}.".format(p))
                continue

            print("# Making {} ...".format(p))

            try:
                subprocess.check_output([
                    "makepbo",
                    "-NUP",
                    "-@={}\\{}\\addons\\{}".format(MAINPREFIX,PREFIX.rstrip("_"),p),
                    p,
                    "{}{}.pbo".format(PREFIX,p)
                ], stderr=subprocess.STDOUT)
            except:
                failed += 1
                print("  Failed to make {}.".format(p))
            else:
                made += 1
                print("  Successfully made {}.".format(p))

        print("\n# Done.")
        print("  Made {}, skipped {}, removed {}, failed to make {}.".format(made, skipped, removed, failed))

    if (compile_extensions):
        try:
            print("\nCompiling extensions in {}".format(extensionspath))
            os.chdir(extensionspath)

            # Prepare 64bit build dirs
            ret = subprocess.call(["msbuild", "uksf.sln", "/m", "/p:Configuration=Release", "/p:Platform=x64"])
            if ret == 1:
                return 1
        except:
            print("Failed to compile extension")
            raise


if __name__ == "__main__":
    sys.exit(main(sys.argv))
