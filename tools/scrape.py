#!/usr/bin/env python3

import os
import sys

def main(argv):
    print("""
#################################
# Gathering Arsenal Access Data #
#################################
""")

    inpath = os.path.abspath(argv[1])
    if os.path.exists(inpath):
        print("Scraping in: {}".format(inpath))

    outpath = os.path.join(inpath, "ArsenalAccess.txt")
    if os.path.exists(outpath):
        os.remove(outpath)
    out = open(outpath, "w")

    for file in os.listdir(inpath):
        if file.endswith(".rpt"):
            with open(os.path.join(inpath, file), encoding="utf8") as openfile:
                try:
                    for line in openfile:
                        if "opened Arsenal on" in line:
                            out.write(file)
                            out.write("{}\n".format(line))
                            print(file)
                            print("{}\n".format(line))
                except UnicodeDecodeError:
                    pass

    out.close()
    print("Scrape complete")


if __name__ == "__main__":
    sys.exit(main(sys.argv))
