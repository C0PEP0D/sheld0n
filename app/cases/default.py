#!/usr/bin/env python3

import os

def main():
    # input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/.."
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
