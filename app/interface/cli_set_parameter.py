#!/usr/bin/env python3

# command line program
import argparse
# util
import math
# lib param
import libset


def run(args):
    libset.set_parameter(args.file, args.parameter, args.value)

def main():
    parser = argparse.ArgumentParser(description='Set a simulation parameter.')
    parser.add_argument('file', type=str, help='parameter file')
    parser.add_argument('parameter', type=str, help='parameter name')
    parser.add_argument('value', type=str, help='new value of that parameter')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
