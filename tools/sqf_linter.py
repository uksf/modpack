#!/usr/bin/env python3

# Requires: https://github.com/LordGolias/sqf

import fnmatch
import os
import sys
import argparse
from sqf.parser import parse
import sqf.analyzer
from sqf.exceptions import SQFParserError


def analyze(filename, out, writer=sys.stdout):
    with open(filename, 'r') as file:
        code = file.read()
        try:
            result = parse(code)
        except SQFParserError as ex:
            out.write("{}:".format(filename))
            print("{}:".format(filename))
            out.write('    [%d,%d]:%s\n' % (ex.position[0], ex.position[1] - 1, ex.message))
            writer.write('    [%d,%d]:%s\n' % (ex.position[0], ex.position[1] - 1, ex.message))
            return -1

        exceptions = sqf.analyzer.analyze(result).exceptions
        if exceptions:
            out.write("{}:".format(filename))
            print("{}:".format(filename))
            for ex in exceptions:
                out.write('    [%d,%d]:%s\n' % (ex.position[0], ex.position[1] - 1, ex.message))
                writer.write('    [%d,%d]:%s\n' % (ex.position[0], ex.position[1] - 1, ex.message))
            return len(exceptions)

    return 0

def main():
    print("#########################")
    print("# Lint Check #")
    print("#########################")

    sqf_list = []
    all_warnings = 0
    all_errors = 0
    out = open("output.txt", "w")

    parser = argparse.ArgumentParser()
    parser.add_argument('-m', '--module', help='only search specified module folder', required=False, default=".")
    args = parser.parse_args()

    for root, dirnames, filenames in os.walk('addons' + '\\' + args.module):
        for filename in fnmatch.filter(filenames, '*.sqf'):
            sqf_list.append(os.path.join(root, filename))

    for filename in sqf_list:
        ret = analyze(filename, out)
        if ret < 0:
            all_errors = all_errors + 1
        else:
            all_warnings = all_warnings + ret

    print("Parse Errors {0} - Warnings {1}".format(all_errors, all_warnings))
    out.close()

    # return (all_errors + all_warnings)
    return all_errors

if __name__ == "__main__":
    main()
