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
    objects_j_0_1 = libpost.get_objects_properties(["j_0_1"], object_names)
    objects_j_0_2 = libpost.get_objects_properties(["j_0_2"], object_names)
    objects_j_1_0 = libpost.get_objects_properties(["j_1_0"], object_names)
    objects_j_1_1 = libpost.get_objects_properties(["j_1_1"], object_names)
    objects_j_1_2 = libpost.get_objects_properties(["j_1_2"], object_names)
    objects_j_2_0 = libpost.get_objects_properties(["j_2_0"], object_names)
    objects_j_2_1 = libpost.get_objects_properties(["j_2_1"], object_names)
    objects_j_2_2 = libpost.get_objects_properties(["j_2_2"], object_names)
    print("INFO: Done.")
    # compute gradients error
    objects_init_gradients = {}
    for object_name in objects_j_0_0:
        objects_init_gradients[object_name] = [np.empty((3, 3))] * objects_j_0_0[object_name]["value"].shape[1]
        for j in range(0, objects_j_0_0[object_name]["value"].shape[1]):
            objects_init_gradients[object_name][j][0, 0] = objects_j_0_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][0, 1] = objects_j_0_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][0, 2] = objects_j_0_2[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 0] = objects_j_1_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 1] = objects_j_1_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 2] = objects_j_1_2[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 0] = objects_j_2_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 1] = objects_j_2_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 2] = objects_j_2_2[object_name]["value"][0, j]
    objects_gradients_error = copy.deepcopy(objects_j_0_0)
    print("INFO: Computing gradients error...")
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
                # error
                objects_gradients_error[object_name]["value"][i, j] = np.linalg.norm(gradients - objects_init_gradients[object_name][j])
        # info
        objects_gradients_error[object_name]["info"] = [info.replace("j_0_0", "|J_(t) - J_0|") for info in objects_gradients_error[object_name]["info"]]
    print("INFO: Done.")
    # clean
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
    
    # average
    print("INFO: Averaging...")
    objects_gradients_error_average = {object_name:{} for object_name in objects_gradients_error}
    for object_name in objects_gradients_error_average:
        # value
        objects_gradients_error_average[object_name]["value"] = np.column_stack([np.average(objects_gradients_error[object_name]["value"], axis=1), 1.96 * np.std(objects_gradients_error[object_name]["value"], axis=1) / np.sqrt(objects_gradients_error[object_name]["value"].shape[1])])
        # info
        objects_gradients_error_average[object_name]["info"] = ["average_|J_(t) - J_0|", "95CLI"]
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    libpost.savet(time, objects_gradients_error_average, "average_|J_(t) - J_0|")
    print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
