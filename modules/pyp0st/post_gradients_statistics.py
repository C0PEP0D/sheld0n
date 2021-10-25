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
    # compute gradients invariant
    objects_tr_2 = copy.deepcopy(objects_j_0_0)
    objects_invariant = copy.deepcopy(objects_j_0_0)
    objects_invariant_mmean = copy.deepcopy(objects_j_0_0)
    objects_invariant_x = copy.deepcopy(objects_j_0_0)
    objects_invariant_y = copy.deepcopy(objects_j_0_0)
    objects_invariant_z = copy.deepcopy(objects_j_0_0)
    for object_name in objects_invariant:
        # value
        for i in range(0, objects_invariant[object_name]["value"].shape[0]):
            for j in range(0, objects_invariant[object_name]["value"].shape[1]):
                # set J
                J = np.empty((3, 3))
                J[0, 0] = objects_j_0_0[object_name]["value"][i, j]
                J[0, 1] = objects_j_0_1[object_name]["value"][i, j]
                J[0, 2] = objects_j_0_2[object_name]["value"][i, j]
                J[1, 0] = objects_j_1_0[object_name]["value"][i, j]
                J[1, 1] = objects_j_1_1[object_name]["value"][i, j]
                J[1, 2] = objects_j_1_2[object_name]["value"][i, j]
                J[2, 0] = objects_j_2_0[object_name]["value"][i, j]
                J[2, 1] = objects_j_2_1[object_name]["value"][i, j]
                J[2, 2] = objects_j_2_2[object_name]["value"][i, j]
                # compute
                objects_tr_2[object_name]["value"][i, j] = np.trace(np.matmul(J, J))
                tr_2_name = "tr(J^2)"
                invariant = np.dot(J, DIRECTION)
                objects_invariant[object_name]["value"][i, j] = np.linalg.norm(invariant)
                invariant_name = "||J.z||"
                objects_invariant_mmean[object_name]["value"][i, j] = np.linalg.norm(invariant)
                objects_invariant_x[object_name]["value"][i, j] = invariant[0]
                objects_invariant_y[object_name]["value"][i, j] = invariant[1]
                objects_invariant_z[object_name]["value"][i, j] = invariant[2]
        # info
        objects_tr_2[object_name]["info"] = [info.replace("j_0_0", tr_2_name) for info in objects_tr_2[object_name]["info"]]
        objects_invariant[object_name]["info"] = [info.replace("j_0_0", invariant_name) for info in objects_invariant[object_name]["info"]]
        objects_invariant_mmean[object_name]["info"] = [info.replace("j_0_0", invariant_name + "-mean") for info in objects_invariant_mmean[object_name]["info"]]
        objects_invariant_x[object_name]["info"] = [info.replace("j_0_0", "J.z_x") for info in objects_invariant_x[object_name]["info"]]
        objects_invariant_y[object_name]["info"] = [info.replace("j_0_0", "J.z_y") for info in objects_invariant_y[object_name]["info"]]
        objects_invariant_z[object_name]["info"] = [info.replace("j_0_0", "J.z_z") for info in objects_invariant_z[object_name]["info"]]
    # compute fft
    objects_fft_tr_2 = copy.deepcopy(objects_tr_2)
    objects_fft_invariant = copy.deepcopy(objects_invariant)
    objects_fft_invariant_mmean = copy.deepcopy(objects_invariant_mmean)
    objects_fft_invariant_x = copy.deepcopy(objects_invariant_x)
    objects_fft_invariant_y = copy.deepcopy(objects_invariant_y)
    objects_fft_invariant_z = copy.deepcopy(objects_invariant_z)
    for object_name in objects_fft_invariant:
        # value
        objects_fft_tr_2[object_name]["value"] = np.abs(np.fft.rfft(objects_tr_2[object_name]["value"], axis=0))/objects_tr_2[object_name]["value"].shape[0]
        objects_fft_invariant[object_name]["value"] = np.abs(np.fft.rfft(objects_invariant[object_name]["value"], axis=0))/objects_invariant[object_name]["value"].shape[0]
        objects_fft_invariant_mmean[object_name]["value"] = np.abs(np.fft.rfft(objects_invariant_mmean[object_name]["value"] - np.average(objects_invariant_mmean[object_name]["value"], axis=0), axis=0))/objects_invariant_mmean[object_name]["value"].shape[0]
        objects_fft_invariant_x[object_name]["value"] = np.abs(np.fft.rfft(objects_invariant_x[object_name]["value"], axis=0))/objects_invariant_x[object_name]["value"].shape[0]
        objects_fft_invariant_y[object_name]["value"] = np.abs(np.fft.rfft(objects_invariant_y[object_name]["value"], axis=0))/objects_invariant_y[object_name]["value"].shape[0]
        objects_fft_invariant_z[object_name]["value"] = np.abs(np.fft.rfft(objects_invariant_z[object_name]["value"], axis=0))/objects_invariant_z[object_name]["value"].shape[0]
        # info
        objects_fft_tr_2[object_name]["info"] = [info.replace(invariant_name, "fft_" + tr_2_name) for info in objects_tr_2[object_name]["info"]]
        objects_fft_invariant[object_name]["info"] = [info.replace(invariant_name, "fft_" + invariant_name) for info in objects_invariant[object_name]["info"]]
        objects_fft_invariant_mmean[object_name]["info"] = [info.replace(invariant_name, "fft_" + invariant_name + "-mean") for info in objects_invariant_mmean[object_name]["info"]]
        objects_fft_invariant_x[object_name]["info"] = [info.replace("J.z_x", "fft_J.z_x") for info in objects_invariant_x[object_name]["info"]]
        objects_fft_invariant_y[object_name]["info"] = [info.replace("J.z_y", "fft_J.z_y") for info in objects_invariant_y[object_name]["info"]]
        objects_fft_invariant_z[object_name]["info"] = [info.replace("J.z_z", "fft_J.z_z") for info in objects_invariant_z[object_name]["info"]]
    # average fft and 95CLI
    objects_average_fft_tr_2 = copy.deepcopy(objects_fft_tr_2)
    objects_average_fft_invariant = copy.deepcopy(objects_fft_invariant)
    objects_average_fft_invariant_mmean = copy.deepcopy(objects_fft_invariant_mmean)
    objects_average_fft_invariant_x = copy.deepcopy(objects_fft_invariant_x)
    objects_average_fft_invariant_y = copy.deepcopy(objects_fft_invariant_y)
    objects_average_fft_invariant_z = copy.deepcopy(objects_fft_invariant_z)
    for object_name in objects_average_fft_invariant:
        # value
        objects_average_fft_tr_2[object_name]["value"] = np.column_stack([np.average(objects_fft_tr_2[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_tr_2[object_name]["value"], axis=1) / np.sqrt(objects_fft_tr_2[object_name]["value"].shape[1])])
        objects_average_fft_invariant[object_name]["value"] = np.column_stack([np.average(objects_fft_invariant[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariant[object_name]["value"], axis=1) / np.sqrt(objects_fft_invariant[object_name]["value"].shape[1])])
        objects_average_fft_invariant_mmean[object_name]["value"] = np.column_stack([np.average(objects_fft_invariant_mmean[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariant_mmean[object_name]["value"], axis=1) / np.sqrt(objects_fft_invariant_mmean[object_name]["value"].shape[1])])
        objects_average_fft_invariant_x[object_name]["value"] = np.column_stack([np.average(objects_fft_invariant_x[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariant_x[object_name]["value"], axis=1) / np.sqrt(objects_fft_invariant_x[object_name]["value"].shape[1])])
        objects_average_fft_invariant_y[object_name]["value"] = np.column_stack([np.average(objects_fft_invariant_y[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariant_y[object_name]["value"], axis=1) / np.sqrt(objects_fft_invariant_y[object_name]["value"].shape[1])])
        objects_average_fft_invariant_z[object_name]["value"] = np.column_stack([np.average(objects_fft_invariant_z[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_invariant_z[object_name]["value"], axis=1) / np.sqrt(objects_fft_invariant_z[object_name]["value"].shape[1])])
        # info
        objects_average_fft_tr_2[object_name]["info"] = ["average_fft_" + tr_2_name, "95CLI"]
        objects_average_fft_invariant[object_name]["info"] = ["average_fft_" + invariant_name, "95CLI"]
        objects_average_fft_invariant_mmean[object_name]["info"] = ["average_fft_" + invariant_name + "-mean", "95CLI"]
        objects_average_fft_invariant_x[object_name]["info"] = ["average_fft_J.z_x", "95CLI"]
        objects_average_fft_invariant_y[object_name]["info"] = ["average_fft_J.z_y", "95CLI"]
        objects_average_fft_invariant_z[object_name]["info"] = ["average_fft_J.z_z", "95CLI"]
    # save
    angular_frequency = 2 * np.pi / (time[-1] - time[0]) * np.linspace(1, len(time)//2+2, num=len(time)//2+1)
    libpost.saveaf(angular_frequency, objects_average_fft_tr_2, "average_fft_" + tr_2_name)
    libpost.saveaf(angular_frequency, objects_average_fft_invariant, "average_fft_" + invariant_name)
    libpost.saveaf(angular_frequency, objects_average_fft_invariant_mmean, "average_fft_" + invariant_name + "-mean")
    libpost.saveaf(angular_frequency, objects_average_fft_invariant_x, "average_fft_J.z_x")
    libpost.saveaf(angular_frequency, objects_average_fft_invariant_y, "average_fft_J.z_y")
    libpost.saveaf(angular_frequency, objects_average_fft_invariant_z, "average_fft_J.z_z")

    # compute time estimate
    objects_time_estimate_tr_2 = {}
    objects_time_estimate_sq_tr_2 = {}
    objects_time_estimate = {}
    objects_time_estimate_mmean = {}
    objects_time_estimate_x = {}
    objects_time_estimate_y = {}
    objects_time_estimate_z = {}
    for object_name in objects_average_fft_invariant:
        reduced_object_name = object_name.split("__")[0]
        if not reduced_object_name in objects_time_estimate:
            objects_time_estimate_tr_2[reduced_object_name] = {}
            objects_time_estimate_tr_2[reduced_object_name]["value"] = []
            objects_time_estimate_tr_2[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate_sq_tr_2[reduced_object_name] = {}
            objects_time_estimate_sq_tr_2[reduced_object_name]["value"] = []
            objects_time_estimate_sq_tr_2[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate[reduced_object_name] = {}
            objects_time_estimate[reduced_object_name]["value"] = []
            objects_time_estimate[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate_mmean[reduced_object_name] = {}
            objects_time_estimate_mmean[reduced_object_name]["value"] = []
            objects_time_estimate_mmean[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate_x[reduced_object_name] = {}
            objects_time_estimate_x[reduced_object_name]["value"] = []
            objects_time_estimate_x[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate_y[reduced_object_name] = {}
            objects_time_estimate_y[reduced_object_name]["value"] = []
            objects_time_estimate_y[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
            objects_time_estimate_z[reduced_object_name] = {}
            objects_time_estimate_z[reduced_object_name]["value"] = []
            objects_time_estimate_z[reduced_object_name]["info"] = ["us/u_eta", "time_estimate"]
        # value
        objects_time_estimate_tr_2[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_tr_2[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_tr_2[object_name]["value"][:, 0], x=angular_frequency)]))
        objects_time_estimate_sq_tr_2[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(np.sqrt(objects_average_fft_tr_2[object_name]["value"][:, 0]) * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(np.sqrt(objects_average_fft_tr_2[object_name]["value"][:, 0]), x=angular_frequency)]))
        objects_time_estimate[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_invariant[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariant[object_name]["value"][:, 0], x=angular_frequency)]))
        objects_time_estimate_mmean[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_invariant_mmean[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariant_mmean[object_name]["value"][:, 0], x=angular_frequency)]))
        objects_time_estimate_x[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_invariant_x[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariant_x[object_name]["value"][:, 0], x=angular_frequency)]))
        objects_time_estimate_y[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_invariant_y[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariant_y[object_name]["value"][:, 0], x=angular_frequency)]))
        objects_time_estimate_z[reduced_object_name]["value"].append(np.array([libpost.get_property_from_object_name(object_name, "us"), np.trapz(objects_average_fft_invariant_z[object_name]["value"][:, 0] * 2 * np.pi / angular_frequency, x=angular_frequency) / np.trapz(objects_average_fft_invariant_z[object_name]["value"][:, 0], x=angular_frequency)]))
    for reduced_object_name in objects_time_estimate:
        objects_time_estimate_tr_2[reduced_object_name]["value"] = np.stack(objects_time_estimate[reduced_object_name]["value"])
        objects_time_estimate_sq_tr_2[reduced_object_name]["value"] = np.stack(objects_time_estimate_sq_tr_2[reduced_object_name]["value"])
        objects_time_estimate[reduced_object_name]["value"] = np.stack(objects_time_estimate[reduced_object_name]["value"])
        objects_time_estimate_mmean[reduced_object_name]["value"] = np.stack(objects_time_estimate_mmean[reduced_object_name]["value"])
        objects_time_estimate_x[reduced_object_name]["value"] = np.stack(objects_time_estimate_x[reduced_object_name]["value"])
        objects_time_estimate_y[reduced_object_name]["value"] = np.stack(objects_time_estimate_y[reduced_object_name]["value"])
        objects_time_estimate_z[reduced_object_name]["value"] = np.stack(objects_time_estimate_z[reduced_object_name]["value"])
    libpost.save(objects_time_estimate_tr_2, "time_estimate_tr_2")
    libpost.save(objects_time_estimate_sq_tr_2, "time_estimate_sq_tr_2")
    libpost.save(objects_time_estimate, "time_estimate")
    libpost.save(objects_time_estimate_mmean, "time_estimate_mmean")
    libpost.save(objects_time_estimate_x, "time_estimate_x")
    libpost.save(objects_time_estimate_y, "time_estimate_y")
    libpost.save(objects_time_estimate_z, "time_estimate_z")

if __name__ == '__main__':
    args = parse()
    main()
