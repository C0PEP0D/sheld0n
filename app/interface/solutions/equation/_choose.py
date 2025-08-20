#!/usr/bin/env python3

import os

choices_dir = "solutions/passive_particles"
choices_exceptions = []

# find lib
script_dir = os.path.dirname(os.path.realpath(os.path.dirname(__file__) + "/._choose"))
lib_filename = script_dir[:script_dir.find("interface") + len("interface")] + "/libchoose.py"
# load lib
exec(open(lib_filename).read())

def main():
    choose_file(choices_dir, choices_exceptions)

if __name__ == '__main__':
    main()
