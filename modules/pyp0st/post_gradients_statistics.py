#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
# internal modules
import libpost

DIRECTION = np.array([[1.0, 0.0, 0.0]]).T

def parse():
    parser = argparse.ArgumentParser(description='Computes statistics of the lagrangian gradients matrix (computed along particle trajectories)')
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
    # compute gradients invariant
    objects_invariants = {
        "z.(J.z)":copy.deepcopy(objects_j_0_0),
        "p.(J.p)":copy.deepcopy(objects_j_0_0),
        "p.(J.z)":copy.deepcopy(objects_j_0_0),
        "z.(J.p)":copy.deepcopy(objects_j_0_0)
    }
    for object_name in objects_j_0_0:
        # value
        for i in range(0, objects_j_0_0[object_name]["value"].shape[0]):
            for j in range(0, objects_j_0_0[object_name]["value"].shape[1]):
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
                vorticity = 0.5 * (gradients - gradients.transpose())
                strain_rate = 0.5 * (gradients + gradients.transpose())
                # set axis
                axis = np.empty((3, 1))
                axis[0, 0] = objects_axis_0[object_name]["value"][i, j]
                axis[1, 0] = objects_axis_1[object_name]["value"][i, j]
                axis[2, 0] = objects_axis_2[object_name]["value"][i, j]
                # compute
                objects_invariants["z.(J.z)"][object_name]["value"][i, j] = np.dot(DIRECTION.T, np.dot(gradients, DIRECTION))
                objects_invariants["p.(J.p)"][object_name]["value"][i, j] = np.dot(axis.T, np.dot(gradients, axis))
                objects_invariants["p.(J.z)"][object_name]["value"][i, j] = np.dot(axis.T, np.dot(gradients, DIRECTION))
                objects_invariants["z.(J.p)"][object_name]["value"][i, j] = np.dot(DIRECTION.T, np.dot(gradients, axis))
        # info
        for key in objects_invariants:
            objects_invariants[key][object_name]["info"] = [info.replace("j_0_0", key) for info in objects_invariants[key][object_name]["info"]]
    # clean
    del objects_j_0_0
    del objects_j_0_1
    del objects_j_0_2
    del objects_j_1_0
    del objects_j_1_1
    del objects_j_1_2
    del objects_j_2_0
    del objects_j_2_1
    del objects_j_2_2
    del objects_axis_0
    del objects_axis_1
    del objects_axis_2
    
    # compute fft
    objects_fft_invariants = {key:{object_name:{} for object_name in objects_invariants[key]} for key in objects_invariants}
    for key in objects_fft_invariants:
        for object_name in objects_fft_invariants[key]:
            # value
            objects_fft_invariants[key][object_name]["value"] = np.abs(np.fft.rfft(objects_invariants[key][object_name]["value"], axis=0))/objects_invariants[key][object_name]["value"].shape[0]
            # info
            objects_fft_invariants[key][object_name]["info"] = [info.replace(key, "fft_" + key) for info in objects_invariants[key][object_name]["info"]]
    # average fft and 95CLI
    objects_average_fft_invariants = {key:{object_name:{} for object_name in objects_invariants[key]} for key in objects_invariants}
    for key in objects_average_fft_invariants:
        for object_name in objects_average_fft_invariants[key]:
            # value
            objects_average_fft_invariants[key][object_name]["value"] = np.column_stack([np.average(objects_fft_invariants[key][object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariants[key][object_name]["value"], axis=1) / np.sqrt(objects_fft_invariants[key][object_name]["value"].shape[1])])
            # info
            objects_average_fft_invariants[key][object_name]["info"] = ["average_fft_" + key, "95CLI"]
    # save
    angular_frequency = 2 * np.pi / (time[-1] - time[0]) * np.linspace(1, len(time)//2+2, num=len(time)//2+1)
    for key in objects_fft_invariants:
        libpost.saveaf(angular_frequency, objects_average_fft_invariants[key], "average_fft_" + key)

    # compute time estimates
    objects_time_estimates = {}
    for key in objects_average_fft_invariants:
        objects_time_estimates[key] = {}
        for object_name in objects_average_fft_invariants[key]:
            reduced_object_name = object_name.split("__")[0]
            if not reduced_object_name in objects_time_estimate[key]:
                objects_time_estimates[key][reduced_object_name] = {"value":[], "info":["us/u_eta", "reorientationtime/tau_eta", "time_estimate"]}
            # value
            objects_time_estimates[key][reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), libpost.get_property_from_object_name(object_name, "reorientationtime"), np.trapz(objects_average_fft_invariants[key][object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariants[key][object_name]["value"][:, 0], x=angular_frequency)]))
        # stack
        for reduced_object_name in objects_time_estimate[key]:
            objects_time_estimates[key][reduced_object_name]["value"] = np.stack(objects_time_estimate[key][reduced_object_name]["value"])
    # save
    for key in objects_time_estimates:
        libpost.save(objects_time_estimates[key], "time_estimate_" + key)

if __name__ == '__main__':
    args = parse()
    main()
