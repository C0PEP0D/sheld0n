#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
import scipy as sp
import scipy.integrate
import scipy.linalg
# internal modules
import libpost

DIRECTION = np.array([[1.0, 0.0, 0.0]]).T

def parse():
    parser = argparse.ArgumentParser(description='Computes statistics of the lagrangian gradients matrix (computed along particle trajectories)')
    return parser.parse_args()

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
    print("INFO: Computing L...")
    l_value = {}
    for object_name in gradients_value:
        print("INFO:    Processing " + object_name + "...")
        # value
        l_value[object_name] = sp.integrate.cumtrapz(gradients_value[object_name], time, axis=0)
        print("INFO:    " + object_name + " done.")
    print("INFO: Done.")
    print("INFO: Computing lambda matrix...")
    lambda_value = copy.deepcopy(l_value)
    for object_name in l_value:
        print("INFO:    Processing " + object_name + "...")
        # value
        for i in range(l_value[object_name].shape[0]):
            print("INFO:        "+str(i)+"/"+str(l_value[object_name].shape[0])+" ...")
            for j in range(l_value[object_name].shape[1]):
                lambda_value[object_name][i, j, :, :] = 1/(2.0 * time[1+i]) * sp.linalg.logm(np.matmul(l_value[object_name][i, j, :, :],l_value[object_name][i, j, :, :].transpose()))
        print("INFO:    " + object_name + " done.")
    print("INFO: Done.")
    print("INFO: Computing eigen values...")
    print(np.linalg.eig(np.average(lambda_value["pagent"], axis=0)[:, :, 0]))
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    #libpost.savet(time, objects_gradients_error, "average_gradients_error")
    print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
