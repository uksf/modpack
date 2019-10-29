import os
import shutil
import subprocess

DEPLOYMENT_DIRECTORY = "D:\\Dev"
REPO_DIRECTORY = "C:\\Server\\Modpack"
SERVER_DIRECTORY = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Arma 3 Server"
ace_optionals = ["ace_compat_rksl_pm_ii", "nouniformrestrictions"]

if __name__ == '__main__':
    os.chdir(REPO_DIRECTORY)
    repo_folder_uksf = os.path.join(REPO_DIRECTORY, "@uksf")
    repo_folder_uksf_ace = os.path.join(REPO_DIRECTORY, "@uksf_ace")
    repo_folder_acre = os.path.join(REPO_DIRECTORY, "@acre2")
    repo_folder_uksf_dependencies = os.path.join(REPO_DIRECTORY, "@uksf_dependencies")
    repo_folder_intercept = os.path.join(REPO_DIRECTORY, "@intercept")
    deployment_folder_uksf = os.path.join(DEPLOYMENT_DIRECTORY, "modpack\\release\\@uksf")
    deployment_folder_uksf_ace = os.path.join(DEPLOYMENT_DIRECTORY, "ACE3\\release\\@ace")
    deployment_folder_acre = os.path.join(DEPLOYMENT_DIRECTORY, "acre2\\release\\@acre2")
    deployment_folder_uksf_dependencies = os.path.join(DEPLOYMENT_DIRECTORY, "modpack\\release\\@uksf_dependencies")
    deployment_folder_intercept = os.path.join(DEPLOYMENT_DIRECTORY, "modpack\\@intercept")    
    keys_folder = os.path.join(SERVER_DIRECTORY, "Keys")
    signtool = "C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.17763.0\\x64\\signtool.exe"

    # Delete uksf and uksf_ace.
    print("Deleting old @uksf")
    shutil.rmtree(repo_folder_uksf, True)
    print("Deleting old @uksf_ace")
    shutil.rmtree(repo_folder_uksf_ace, True)
    print("Deleting old @acre2")
    shutil.rmtree(repo_folder_acre, True)
    print("Deleting old @intercept")
    shutil.rmtree(repo_folder_intercept, True)

    # Move uksf, uksf_ace, and intercept.
    print("Moving new @uksf")
    shutil.copytree(deployment_folder_uksf, repo_folder_uksf)
    print("Moving new @uksf_ace")
    shutil.copytree(deployment_folder_uksf_ace, repo_folder_uksf_ace)
    print("Moving new @acre2")
    shutil.copytree(deployment_folder_acre, repo_folder_acre)
    print("Moving new @intercept")
    shutil.copytree(deployment_folder_intercept, repo_folder_intercept)

    # Find dlls
    dlls = []
    for file in os.listdir(repo_folder_intercept):
        if (file.endswith(".dll")):
            dlls.append(os.path.join(repo_folder_intercept, file))
    for file in os.listdir(os.path.join(repo_folder_intercept, "intercept")):
        if (file.endswith(".dll")):
            dlls.append(os.path.join(repo_folder_intercept, "intercept", file))
    for file in os.listdir(os.path.join(repo_folder_uksf, "intercept")):
        if (file.endswith(".dll")):
            dlls.append(os.path.join(repo_folder_uksf, "intercept", file))

    # Sign intercept dlls
    for file in dlls:
        try:
            print("\nSigning {}".format(file))
            print()
            ret = subprocess.call([signtool, "verify", "/pa", file])
            if ret == 1:
                ret = subprocess.call([signtool, "sign", "/f", "D:\\Dev\\certs\\UKSFCert.pfx", "/t", "http://timestamp.comodoca.com/authenticode", file])
                if ret == 1:
                    raise Exception()
        except:
            print("\nFailed to sign {}".format(file))
            raise

    # Move whitelisted ace optionals
    for folder in os.listdir(os.path.join(repo_folder_uksf_ace, "optionals")):
        if ("userconfig" in folder):
            continue
        for file in os.listdir(os.path.join(repo_folder_uksf_ace, "optionals", folder, "addons")):
            for compat in ace_optionals:
                if ((compat in file) and not(os.path.isfile(os.path.join(repo_folder_uksf_ace, "addons", file)))):
                    shutil.copyfile(os.path.join(repo_folder_uksf_ace, "optionals", folder, "addons", file), os.path.join(repo_folder_uksf_ace, "addons", file))


    # Updated any matching PBOs in dependencies.
    print("\nUpdating dependencies files")
    print("Moving new PBOs and deleting marked PBOs")
    for file in os.listdir(os.path.join(deployment_folder_uksf_dependencies, "addons")):
        if (file.endswith(".pbo")
                and os.path.isfile(os.path.join(deployment_folder_uksf_dependencies, "addons", file))):
            print("    Found PBO to update: {}".format(file))
            shutil.copy(os.path.join(deployment_folder_uksf_dependencies, "addons", file), os.path.join(repo_folder_uksf_dependencies, "addons", file))
            print("    Updated: {}".format(os.path.join(repo_folder_uksf_dependencies, "addons", file)))
        elif (file.endswith(".delete")
                and os.path.isfile(os.path.join(deployment_folder_uksf_dependencies, "addons", file))
                and os.path.isfile(os.path.join(repo_folder_uksf_dependencies, "addons", "{}".format(os.path.splitext(os.path.basename(file))[0])))):
            file_delete = "{}".format(os.path.splitext(os.path.basename(file))[0])
            file_zsync_delete = "{}.zsync".format(file_delete)
            print("    Found PBO to delete: {}".format(file_delete))
            os.remove(os.path.join(repo_folder_uksf_dependencies, "addons", file_delete))
            os.remove(os.path.join(repo_folder_uksf_dependencies, "addons", file_zsync_delete))
            print("    Deleted: {}".format(os.path.join(repo_folder_uksf_dependencies, "addons", file_delete)))

    # Delete bisigns in dependencies.
    print("Deleting old bisigns")
    for file in os.listdir(os.path.join(repo_folder_uksf_dependencies, "addons")):
        if ((file.endswith(".bisign") or file.endswith(".bisign.zsync")) and os.path.isfile(os.path.join(repo_folder_uksf_dependencies, "addons", file))):
            if (
                    file.endswith(".bisign.zsync") or 
                    (
                        not os.path.isfile(os.path.join(deployment_folder_uksf_dependencies, "addons", file)) or
                        not os.path.basename(file).replace(".bisign", "").split(".", 2)[2] == os.path.basename(os.path.join(deployment_folder_uksf_dependencies, "addons", file)).replace(".bisign", "").split(".", 2)[2] or
                        not os.path.getmtime(os.path.join(repo_folder_uksf_dependencies, "addons", file)) == os.path.getmtime(os.path.join(deployment_folder_uksf_dependencies, "addons", file))
                    )
                ):
                os.remove(os.path.join(repo_folder_uksf_dependencies, "addons", file))

    # Move bisigns for dependencies.
    print("Moving new bisigns")
    for file in os.listdir(os.path.join(deployment_folder_uksf_dependencies, "addons")):
        if (file.endswith(".bisign") and os.path.isfile(os.path.join(deployment_folder_uksf_dependencies, "addons", file))):
            if (
                    not os.path.isfile(os.path.join(repo_folder_uksf_dependencies, "addons", file)) or
                    not os.path.basename(file).replace(".bisign", "").split(".", 2)[2] == os.path.basename(os.path.join(repo_folder_uksf_dependencies, "addons", file)).replace(".bisign", "").split(".", 2)[2] or
                    not os.path.getmtime(os.path.join(deployment_folder_uksf_dependencies, "addons", file)) == os.path.getmtime(os.path.join(repo_folder_uksf_dependencies, "addons", file))
                ):
                shutil.copy(os.path.join(deployment_folder_uksf_dependencies, "addons", file), os.path.join(repo_folder_uksf_dependencies, "addons", file))

    # Delete old keys
    print("\nUpdating keys")
    print("Deleting old keys")
    for file in os.listdir(keys_folder):
        name = os.path.splitext(file)[0]
        if (file.endswith(".bikey") and (("uksf" in name and not ("gcam" in name)) or ("ace_3" in name) or ("acre_" in name))
                and os.path.isfile(os.path.join(keys_folder, file))):
            print("    Deleting: {}".format(file))
            os.remove(os.path.join(keys_folder, file))

    # Move new keys
    print("Moving new keys")
    for file in os.listdir(os.path.join(deployment_folder_uksf, "keys")):
        if file.endswith(".bikey") and os.path.isfile(os.path.join(deployment_folder_uksf, "keys", file)):
            print("    Moving: {}".format(file))
            shutil.copy(os.path.join(deployment_folder_uksf, "keys", file), os.path.join(keys_folder, file))
    for file in os.listdir(os.path.join(deployment_folder_uksf_ace, "keys")):
        if file.endswith(".bikey") and os.path.isfile(os.path.join(deployment_folder_uksf_ace, "keys", file)):
            print("    Moving: {}".format(file))
            shutil.copy(os.path.join(deployment_folder_uksf_ace, "keys", file), os.path.join(keys_folder, file))
    for file in os.listdir(os.path.join(deployment_folder_acre, "keys")):
        if file.endswith(".bikey") and os.path.isfile(os.path.join(deployment_folder_acre, "keys", file)):
            print("    Moving: {}".format(file))
            shutil.copy(os.path.join(deployment_folder_acre, "keys", file), os.path.join(keys_folder, file))

    # Move cba_settings.sqf
    if (os.path.isfile(os.path.join(SERVER_DIRECTORY, "userconfig", "cba_settings.sqf"))):
        os.remove(os.path.join(SERVER_DIRECTORY, "userconfig", "cba_settings.sqf"))
        shutil.copy(os.path.join(deployment_folder_uksf, "cba_settings.sqf"), os.path.join(SERVER_DIRECTORY, "userconfig", "cba_settings.sqf"))
