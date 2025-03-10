#!/usr/bin/env python3

# Command line program
import argparse
# Folder edit
import os
import shutil


def parse():
    parser = argparse.ArgumentParser(description='Clean the case directory. Deletes the time directory.')
    return parser.parse_args()

def main():
    args = parse()
    if os.path.exists('time'):
        shutil.rmtree('time')

if __name__ == '__main__':
    main()
