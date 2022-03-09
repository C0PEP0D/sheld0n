#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
import scipy as sp
import scipy.optimize
# internal modules
import libpost

BIN_RANGE = (-1.0, 1.0)
BIN_NB = 'auto'

def parse():
    parser = argparse.ArgumentParser(description='Computes particle concentration along an axis')
    parser.add_argument('axis', nargs='?', type=int, default=1, help='specify the axis')
    return parser.parse_args()

def fit_func(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def main(axis):
    print("INFO: Post processing the effective velocity of lagrangian objects along the axis {axis}.".format(axis=axis), flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    time = libpost.get_time()
    print("INFO: Done.", flush=True)
    print("INFO: Reading objects properties...", flush=True)
    objects_pos_axis = libpost.get_objects_properties(["pos_{baxis}".format(baxis=baxis)], object_names)
    print("INFO: Done.", flush=True)
    print("INFO: Computing concentration pdfs...", flush=True)
    objects_concentration_pdfs = {object_name:{"value":np.empty((time.size, 2)), "info":["concentration".format(axis=axis), "pdf"]} for object_name in objects_pos}
    for object_name in objects_concentration_pdfs:
        hist, bin_edges = np.histogram(objects_pos_axis["value"], bins=np.histogram_bin_edges(objects_pos_axis["value"], bins=BIN_NB, range=BIN_RANGE), range=BIN_RANGE, density=True)
        bins = (bin_edges[1:] + bin_edges[:-1])/2
        # info
        objects_concentration_pdfs[object_name]["value"][:, 0] = bins
        objects_concentration_pdfs[object_name]["value"][:, 1] = hist
    print("INFO: Done.", flush=True)
    # save
    print("INFO: Saving...", flush=True)
    libpost.savet(time, objects_concentration_pdfs, "concentration_axis_{axis}".format(axis=axis))
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.axis)
