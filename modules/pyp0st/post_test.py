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

def test(j00, j01, j02, j10, j11, j12, j20, j21, j22, init_gradients, init_skew_gradients, init_sym_gradients):
    gradients = np.empty((3, 3))
    gradients[0, 0] = j00
    gradients[0, 1] = j01
    gradients[0, 2] = j02
    gradients[1, 0] = j10
    gradients[1, 1] = j11
    gradients[1, 2] = j12
    gradients[2, 0] = j20
    gradients[2, 1] = j21
    gradients[2, 2] = j22
    skew_gradients = 0.5 * (gradients - gradients.transpose())
    sym_gradients = 0.5 * (gradients + gradients.transpose())
    # error
    gradients_error = np.linalg.norm(gradients - init_gradients)
    skew_gradients_error = np.linalg.norm(skew_gradients - init_skew_gradients)
    sym_gradients_error = np.linalg.norm(sym_gradients - init_sym_gradients)
    return gradients_error, skew_gradients_error, sym_gradients_error

vtest = np.vectorize(test)

def main():
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
    gradients_norm_average = {}
    sym_gradients_norm_average = {}
    skew_gradients_norm_average = {}
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
        # average
        gradients_norm_average[object_name] = np.average(np.linalg.norm(gradients_value[object_name], axis=(2, 3)))
        sym_gradients_norm_average[object_name] = np.average(np.linalg.norm(sym_gradients_value[object_name], axis=(2, 3)))
        skew_gradients_norm_average[object_name] = np.average(np.linalg.norm(skew_gradients_value[object_name], axis=(2, 3)))
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
    print("INFO: Computing gradients error...")
    objects_gradients_error = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 2)), "info":["1-<|A_t - A_0|>/<|A_inf - A_0|>", "95CLI"]} for object_name in gradients_value}
    objects_skew_gradients_error = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 2)), "info":["1-<|S_t - S_0|>/<|S_inf - S_0|>", "95CLI"]} for object_name in gradients_value}
    objects_sym_gradients_error = {object_name:{"value":np.empty((gradients_value[object_name].shape[0], 2)), "info":["1-<|O_t - O_0|>/<|O_inf - O_0|>", "95CLI"]} for object_name in gradients_value}
    for object_name in gradients_value:
        print("INFO:    Processing " + object_name + "...")
        # value
        objects_gradients_error[object_name]["value"][0, 0] = 0.0
        objects_gradients_error[object_name]["value"][0, 1] = 0.0
        for k in range(1, gradients_value[object_name].shape[0]):
            # gradients error
            tmp = np.array([
                np.linalg.norm(gradients_value[object_name][:-k, :, :, :] - gradients_value[object_name][k:, :, :, :], axis=(2, 3)),
                np.linalg.norm(gradients_value[object_name][k:, :, :, :] - gradients_value[object_name][:-k, :, :, :], axis=(2, 3))
            ])
            objects_gradients_error[object_name]["value"][k, 0] = np.average(tmp)
            objects_gradients_error[object_name]["value"][k, 1] = 1.96 * np.std(tmp) / np.sqrt(tmp.size)
            # skew gradients error
            tmp = np.array([
                np.linalg.norm(skew_gradients_value[object_name][:-k, :, :, :] - skew_gradients_value[object_name][k:, :, :, :], axis=(2, 3)),
                np.linalg.norm(skew_gradients_value[object_name][k:, :, :, :] - skew_gradients_value[object_name][:-k, :, :, :], axis=(2, 3))
            ])
            objects_skew_gradients_error[object_name]["value"][k, 0] = np.average(tmp)
            objects_skew_gradients_error[object_name]["value"][k, 1] = 1.96 * np.std(tmp) / np.sqrt(tmp.size)
            # sym gradients error
            tmp = np.array([
                np.linalg.norm(sym_gradients_value[object_name][:-k, :, :, :] - sym_gradients_value[object_name][k:, :, :, :], axis=(2, 3)),
                np.linalg.norm(sym_gradients_value[object_name][k:, :, :, :] - sym_gradients_value[object_name][:-k, :, :, :], axis=(2, 3))
            ])
            objects_sym_gradients_error[object_name]["value"][k, 0] = np.average(tmp)
            objects_sym_gradients_error[object_name]["value"][k, 1] = 1.96 * np.std(tmp) / np.sqrt(tmp.size)
        objects_gradients_error[object_name]["value"] /= np.average(objects_gradients_error[object_name]["value"][len(objects_gradients_error[object_name]["value"][:, 0]) // 2:, 0])
        objects_gradients_error[object_name]["value"][:, 0] = 1.0 - objects_gradients_error[object_name]["value"][:, 0]
        objects_sym_gradients_error[object_name]["value"] /= np.average(objects_sym_gradients_error[object_name]["value"][len(objects_sym_gradients_error[object_name]["value"][:, 0]) // 2:, 0])
        objects_sym_gradients_error[object_name]["value"][:, 0] = 1.0 - objects_sym_gradients_error[object_name]["value"][:, 0]
        objects_skew_gradients_error[object_name]["value"] /= np.average(objects_skew_gradients_error[object_name]["value"][len(objects_skew_gradients_error[object_name]["value"][:, 0]) // 2:, 0])
        objects_skew_gradients_error[object_name]["value"][:, 0] = 1.0 - objects_skew_gradients_error[object_name]["value"][:, 0]
        print("INFO:    " + object_name + " done.")
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    libpost.savet(time, objects_gradients_error, "average_gradients_error")
    libpost.savet(time, objects_skew_gradients_error, "average_skew_gradients_error")
    libpost.savet(time, objects_sym_gradients_error, "average_sym_gradients_error")
    print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
