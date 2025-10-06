#!/usr/bin/env python3

import argparse
import glob
import os
import sys

def parse():
    # get choices
    choices = glob.glob("*.py")
    choices.remove("libpost.py")
    # parser
    parser = argparse.ArgumentParser(description='Run post processing.')
    parser.add_argument('script', choices=choices, default=choices[0], help='specify the name of the script to run')
    return parser.parse_args()

def main():
    args = parse()

    # exec(open(args.script).read())
    # main()

    os.system("./{script} {argv}".format(script=args.script, argv=" ".join(sys.argv[3:])))
    # os.system("./.gui_run_post_process_aux {script} {argv}".format(script=args.script, argv=" ".join(sys.argv[3:])))

if __name__ == '__main__':
    main()
