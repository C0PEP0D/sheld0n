#!/usr/bin/env python3

# command line program
import argparse
import copy
import numpy as np
import scipy as sp
# internal modules
import libpost

DIRECTION = np.array([[1.0, 0.0, 0.0]]).T
TAU = 1.0

def parse():
    parser = argparse.ArgumentParser(description='Computes particles axis statistics.')
    return parser.parse_args()

def main():
    # get gradient matrix
    time = libpost.get_time();
    objects_j_0_0 = libpost.get_objects_properties(["j_0_0"])
    objects_j_0_1 = libpost.get_objects_properties(["j_0_1"])
    objects_j_0_2 = libpost.get_objects_properties(["j_0_2"])
    objects_j_1_0 = libpost.get_objects_properties(["j_1_0"])
    objects_j_1_1 = libpost.get_objects_properties(["j_1_1"])
    objects_j_1_2 = libpost.get_objects_properties(["j_1_2"])
    objects_j_2_0 = libpost.get_objects_properties(["j_2_0"])
    objects_j_2_1 = libpost.get_objects_properties(["j_2_1"])
    objects_j_2_2 = libpost.get_objects_properties(["j_2_2"])
    # get axis
    objects_axis_0 = libpost.get_objects_properties(["axis_0"])
    objects_axis_1 = libpost.get_objects_properties(["axis_1"])
    objects_axis_2 = libpost.get_objects_properties(["axis_2"])
    # reduce axis to a scalar
    objects_axis_dot_surf = copy.deepcopy(objects_axis_0)
    for object_name in objects_axis_dot_surf:
        # value
        for i in range(0, objects_axis_dot_surf[object_name]["value"].shape[0]):
            for j in range(0, objects_axis_dot_surf[object_name]["value"].shape[1]):
                # set gradients
                gradients = np.empty((3, 3))
                gradients[0, 0] = objects_j_0_0[object_name]["value"][i, j]
                gradients[0, 1] = objects_j_0_1[object_name]["value"][i, j]
                gradients[0, 2] = objects_j_0_2[object_name]["value"][i, j]
                gradients[1, 0] = objects_j_1_0[object_name]["value"][i, j]
                gradients[1, 1] = objects_j_1_1[object_name]["value"][i, j]
                gradients[1, 2] = objects_j_1_2[object_name]["value"][i, j]
                gradients[2, 0] = objects_j_2_0[object_name]["value"][i, j]
                gradients[2, 1] = objects_j_2_1[object_name]["value"][i, j]
                gradients[2, 2] = objects_j_2_2[object_name]["value"][i, j]
                # set axis
                axis = np.empty((3,1))
                axis[0] = objects_axis_0[object_name]["value"][i, j]
                axis[1] = objects_axis_1[object_name]["value"][i, j]
                axis[2] = objects_axis_2[object_name]["value"][i, j]
                # compute
                surf = np.dot(scipy.linalg.expm(gradients * TAU).T, DIRECTION)
                objects_axis_dot_surf[object_name]["value"][i, j] = np.dot(surf / np.linalg.norm(surf), axis)
        # info
        objects_axis_dot_surf[object_name]["info"] = [info.replace("axis_0", "axis_dot_surf") for info in objects_axis_reduction[object_name]["info"]]
    # compute fft
    objects_fft_axis_0 = copy.deepcopy(objects_axis_0)
    objects_fft_axis_1 = copy.deepcopy(objects_axis_1)
    objects_fft_axis_2 = copy.deepcopy(objects_axis_2)
    objects_fft_axis_dot_surf = copy.deepcopy(objects_axis_dot_surf)
    for object_name in objects_fft_invariant:
        # value
        objects_fft_axis_0[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_axis_0[object_name]["value"], axis=0))/objects_fft_axis_0[object_name]["value"].shape[0]
        objects_fft_axis_1[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_axis_1[object_name]["value"], axis=0))/objects_fft_axis_1[object_name]["value"].shape[0]
        objects_fft_axis_2[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_axis_2[object_name]["value"], axis=0))/objects_fft_axis_2[object_name]["value"].shape[0]
        objects_fft_axis_dot_surf[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_axis_dot_surf[object_name]["value"], axis=0))/objects_fft_axis_dot_surf[object_name]["value"].shape[0]
        # info
        objects_fft_axis_0[object_name]["info"] = [info.replace("axis_0", "fft_axis_0") for info in objects_axis_0[object_name]["info"]]
        objects_fft_axis_1[object_name]["info"] = [info.replace("axis_1", "fft_axis_1") for info in objects_axis_0[object_name]["info"]]
        objects_fft_axis_2[object_name]["info"] = [info.replace("axis_2", "fft_axis_2") for info in objects_axis_0[object_name]["info"]]
        objects_fft_axis_dot_surf[object_name]["info"] = [info.replace("axis_dot_surf", "fft_axis_dot_surf") for info in objects_axis_0[object_name]["info"]]
    # average fft and 95CLI
    objects_average_fft_axis_0 = copy.deepcopy(objects_fft_axis_0)
    objects_average_fft_axis_1 = copy.deepcopy(objects_fft_axis_1)
    objects_average_fft_axis_2 = copy.deepcopy(objects_fft_axis_2)
    objects_average_fft_axis_dot_surf = copy.deepcopy(objects_fft_axis_dot_surf)
    for object_name in objects_average_fft_axis_0:
        # value
        objects_average_fft_axis_0[object_name]["value"] = np.column_stack([np.average(objects_fft_axis_0[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_axis_0[object_name]["value"], axis=1) / np.sqrt(objects_fft_axis_0[object_name]["value"].shape[1])])
        objects_average_fft_axis_1[object_name]["value"] = np.column_stack([np.average(objects_fft_axis_1[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_axis_1[object_name]["value"], axis=1) / np.sqrt(objects_fft_axis_1[object_name]["value"].shape[1])])
        objects_average_fft_axis_2[object_name]["value"] = np.column_stack([np.average(objects_fft_axis_2[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_axis_2[object_name]["value"], axis=1) / np.sqrt(objects_fft_axis_2[object_name]["value"].shape[1])])
        objects_average_fft_axis_dot_surf[object_name]["value"] = np.column_stack([np.average(objects_fft_axis_dot_surf[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_axis_dot_surf[object_name]["value"], axis=1) / np.sqrt(objects_fft_axis_dot_surf[object_name]["value"].shape[1])])
        # info
        objects_average_fft_axis_0[object_name]["info"] = ["average_fft_axis_0", "95CLI"]
        objects_average_fft_axis_1[object_name]["info"] = ["average_fft_axis_1", "95CLI"]
        objects_average_fft_axis_2[object_name]["info"] = ["average_fft_axis_2", "95CLI"]
        objects_average_fft_axis_dot_surf[object_name]["info"] = ["average_fft_axis_dot_surf", "95CLI"]
    # save
    angular_frequency = 2 * np.pi / (time[-1] - time[0]) * np.linspace(1, len(time)//2+2, num=len(time)//2+1)
    libpost.saveaf(angular_frequency, objects_average_fft_axis_0, "average_fft_axis_0")
    libpost.saveaf(angular_frequency, objects_average_fft_axis_1, "average_fft_axis_1")
    libpost.saveaf(angular_frequency, objects_average_fft_axis_2, "average_fft_axis_2")
    libpost.saveaf(angular_frequency, objects_average_fft_axis_dot_surf, "average_fft_axis_dot_surf")

if __name__ == '__main__':
    args = parse()
    main()
