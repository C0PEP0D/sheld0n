#!/usr/bin/env python3

# Command line program
import argparse
# Folder edit
import os
import shutil
import glob

def parse():
    parser = argparse.ArgumentParser(description='Clean the post_process directory. Deletes mp4 and pdf files.')
    return parser.parse_args()

def main():
    args = parse()
    for mp4_file in glob.glob("*.mp4"):
        os.remove(mp4_file)
    for pdf_file in glob.glob("*.pdf"):
        os.remove(pdf_file)

if __name__ == '__main__':
    main()
