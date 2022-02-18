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
    print("INFO: Post processing flow velocity gradients statistics sampled by lagrangian objects.")
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names))
    # get gradient matrix
    print("INFO: Reading objects properties...")
    time = libpost.get_time();
    objects_j_0_0 = libpost.get_objects_properties(["j_0_0"], object_names)
    print("INFO: Done.")
    print("INFO: Computing f(t) using pdfs...")
    f = {object_name:{"value":np.empty((objects_j_0_0[object_name]["value"].shape[0], 1)), "info":["f"]} for object_name in object_names}
    for object_name in objects_j_0_0:
        print("INFO:    Processing " + object_name + "...")
        f[object_name]["value"][0, 0] = 1.0
        for k in range(1, objects_j_0_0[object_name]["value"].shape[0]):
            pdf, edges = np.histogramdd((
                objects_j_0_0[object_name]["value"][:-k, :].flatten(),
                objects_j_0_0[object_name]["value"][k:, :].flatten(),
            ), density=True)
            f[object_name]["value"][k, 0] = np.average(np.sum(0.5 * (edges[1][1:] + edges[1][:-1]) * pdf * np.diff(edges[1]), axis=1) / np.sum(pdf * np.diff(edges[1]), axis=1) / (0.5 * (edges[0][1:] + edges[0][:-1])))
        print("INFO:    " + object_name + " done.")
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    libpost.savet(time, f, "f_0_0")
    print("INFO: Done.")

def main_save():
    print("INFO: Post processing flow velocity gradients statistics sampled by lagrangian objects.")
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names)[:-1])
    # get gradient matrix
    print("INFO: Reading objects properties...")
    time = libpost.get_time();
    objects_j_0_0 = libpost.get_objects_properties(["j_0_0"], object_names)
    objects_j_0_1 = libpost.get_objects_properties(["j_0_1"], object_names)
    objects_j_0_2 = libpost.get_objects_properties(["j_0_2"], object_names)
    objects_j_1_0 = libpost.get_objects_properties(["j_1_0"], object_names)
    objects_j_1_1 = libpost.get_objects_properties(["j_1_1"], object_names)
    objects_j_1_2 = libpost.get_objects_properties(["j_1_2"], object_names)
    objects_j_2_0 = libpost.get_objects_properties(["j_2_0"], object_names)
    objects_j_2_1 = libpost.get_objects_properties(["j_2_1"], object_names)
    objects_j_2_2 = libpost.get_objects_properties(["j_2_2"], object_names)
    print("INFO: Done.")
    print("INFO: Gradients reconstruction...")
    gradients_value = {}
    sym_gradients_value = {}
    skew_gradients_value = {}
    for object_name in objects_j_0_0:
        gradients_value[object_name] = np.empty((objects_j_0_0[object_name]["value"].shape[0], objects_j_0_0[object_name]["value"].shape[1], 3, 3))
        gradients_value[object_name][:, :, 0, 0] = objects_j_0_0[object_name]["value"]
        gradients_value[object_name][:, :, 0, 1] = objects_j_0_1[object_name]["value"]
        gradients_value[object_name][:, :, 0, 2] = objects_j_0_2[object_name]["value"]
        gradients_value[object_name][:, :, 1, 0] = objects_j_1_0[object_name]["value"]
        gradients_value[object_name][:, :, 1, 1] = objects_j_1_1[object_name]["value"]
        gradients_value[object_name][:, :, 1, 2] = objects_j_1_2[object_name]["value"]
        gradients_value[object_name][:, :, 2, 0] = objects_j_2_0[object_name]["value"]
        gradients_value[object_name][:, :, 2, 1] = objects_j_2_1[object_name]["value"]
        gradients_value[object_name][:, :, 2, 2] = objects_j_2_2[object_name]["value"]
        sym_gradients_value[object_name] = 0.5 * (gradients_value[object_name] + gradients_value[object_name].transpose(0, 1, 3, 2))
        skew_gradients_value[object_name] = 0.5 * (gradients_value[object_name] - gradients_value[object_name].transpose(0, 1, 3, 2))
    print("INFO: Done.")
    print("INFO: Cleaning...")
    del objects_j_0_0
    del objects_j_0_1
    del objects_j_0_2
    del objects_j_1_0
    del objects_j_1_1
    del objects_j_1_2
    del objects_j_2_0
    del objects_j_2_1
    del objects_j_2_2
    print("INFO: Done.")
    print("INFO: Saving flow gradients statistics...")
    statistics = {}
    for object_name in gradients_value:
        gradients_norm = np.linalg.norm(gradients_value[object_name], axis=(2, 3))
        skew_gradients_norm = np.linalg.norm(skew_gradients_value[object_name], axis=(2, 3))
        sym_gradients_norm = np.linalg.norm(sym_gradients_value[object_name], axis=(2, 3))
        statistics[object_name] = np.array([
            # gradients
            np.average(gradients_norm),
            1.96 * np.std(gradients_norm) / np.sqrt(gradients_value[object_name].shape[0] * gradients_value[object_name].shape[1]),
            # sym gradients
            np.average(sym_gradients_norm),
            1.96 * np.std(sym_gradients_norm) / np.sqrt(sym_gradients_value[object_name].shape[0] * sym_gradients_value[object_name].shape[1]),
            # skew gradients
            np.average(skew_gradients_norm),
            1.96 * np.std(skew_gradients_norm) / np.sqrt(skew_gradients_value[object_name].shape[0] * skew_gradients_value[object_name].shape[1]),
        ]).reshape(1, 6)
        np.savetxt("flow_gradients_statistics__"+object_name+".csv", statistics[object_name], header="E[|A|], 95CLI, E[|S|], 95CLI, E[|O|], 95CLI", delimiter=",")
    print("INFO: Done.")
    print("INFO: Computing gradients error...")
    objects_gradients_error_2 = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 3)), "info":["E[|A_t - A_0|^2]", "sum_V[a_t - a_0]", "f"]} for object_name in gradients_value}
    objects_skew_gradients_error_2 = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 3)), "info":["E[|S_t - S_0|^2]", "sum_V[s_t - s_0]", "f"]} for object_name in gradients_value}
    objects_sym_gradients_error_2 = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 3)), "info":["E[|O_t - O_0|^2]", "sum_V[o_t - o_0]", "f"]} for object_name in gradients_value}
    for object_name in gradients_value:
        print("INFO:    Processing " + object_name + "...")
        # value
        objects_gradients_error_2[object_name]["value"][0, 0] = 0.0
        objects_gradients_error_2[object_name]["value"][0, 1] = 0.0
        objects_gradients_error_2[object_name]["value"][0, 2] = 1.0
        objects_skew_gradients_error_2[object_name]["value"][0, 0] = 0.0
        objects_skew_gradients_error_2[object_name]["value"][0, 1] = 0.0
        objects_skew_gradients_error_2[object_name]["value"][0, 2] = 1.0
        objects_sym_gradients_error_2[object_name]["value"][0, 0] = 0.0
        objects_sym_gradients_error_2[object_name]["value"][0, 1] = 0.0
        objects_sym_gradients_error_2[object_name]["value"][0, 2] = 1.0
        for k in range(1, gradients_value[object_name].shape[0]):
            # gradients error
            norm = np.array([
                np.linalg.norm(gradients_value[object_name][:-k, :, :, :] - gradients_value[object_name][k:, :, :, :], axis=(2, 3))**2,
                np.linalg.norm(gradients_value[object_name][k:, :, :, :] - gradients_value[object_name][:-k, :, :, :], axis=(2, 3))**2
            ])
            trace = np.sum(np.var(np.concatenate(
                (gradients_value[object_name][:-k, :, :, :] - gradients_value[object_name][k:, :, :, :],
                gradients_value[object_name][k:, :, :, :] - gradients_value[object_name][:-k, :, :, :]),
                axis=1
            ), axis=(0, 1)))
            objects_gradients_error_2[object_name]["value"][k, 0] = np.average(norm)
            objects_gradients_error_2[object_name]["value"][k, 1] = trace
            objects_gradients_error_2[object_name]["value"][k, 2] = 1 - np.sqrt((objects_gradients_error_2[object_name]["value"][k, 0] - objects_gradients_error_2[object_name]["value"][k, 1]) / statistics[object_name][0, 2])
            # skew gradients error
            norm = np.array([
                np.linalg.norm(skew_gradients_value[object_name][:-k, :, :, :] - skew_gradients_value[object_name][k:, :, :, :], axis=(2, 3))**2,
                np.linalg.norm(skew_gradients_value[object_name][k:, :, :, :] - skew_gradients_value[object_name][:-k, :, :, :], axis=(2, 3))**2
            ])
            trace = np.sum(np.var(np.concatenate(
                (skew_gradients_value[object_name][:-k, :, :, :] - skew_gradients_value[object_name][k:, :, :, :],
                skew_gradients_value[object_name][k:, :, :, :] - skew_gradients_value[object_name][:-k, :, :, :]),
                axis=1
            ), axis=(0, 1)))
            objects_skew_gradients_error_2[object_name]["value"][k, 0] = np.average(norm)
            objects_skew_gradients_error_2[object_name]["value"][k, 1] = trace
            objects_skew_gradients_error_2[object_name]["value"][k, 2] = 1 - np.sqrt((objects_skew_gradients_error_2[object_name]["value"][k, 0] - objects_skew_gradients_error_2[object_name]["value"][k, 1]) / statistics[object_name][0, 10])
            # sym gradients error
            norm = np.array([
                np.linalg.norm(sym_gradients_value[object_name][:-k, :, :, :] - sym_gradients_value[object_name][k:, :, :, :], axis=(2, 3))**2,
                np.linalg.norm(sym_gradients_value[object_name][k:, :, :, :] - sym_gradients_value[object_name][:-k, :, :, :], axis=(2, 3))**2
            ])
            trace = np.sum(np.var(np.concatenate(
                (sym_gradients_value[object_name][:-k, :, :, :] - sym_gradients_value[object_name][k:, :, :, :],
                sym_gradients_value[object_name][k:, :, :, :] - sym_gradients_value[object_name][:-k, :, :, :]),
                axis=1
            ), axis=(0, 1)))
            objects_sym_gradients_error_2[object_name]["value"][k, 0] = np.average(norm)
            objects_sym_gradients_error_2[object_name]["value"][k, 1] = trace
            objects_sym_gradients_error_2[object_name]["value"][k, 2] = 1 - np.sqrt((objects_sym_gradients_error_2[object_name]["value"][k, 0] - objects_sym_gradients_error_2[object_name]["value"][k, 1]) / statistics[object_name][0, 6])
        print("INFO:    " + object_name + " done.")
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    libpost.savet(time, objects_gradients_error_2, "average_gradients_error_2")
    libpost.savet(time, objects_skew_gradients_error_2, "average_skew_gradients_error_2")
    libpost.savet(time, objects_sym_gradients_error_2, "average_sym_gradients_error_2")
    print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
