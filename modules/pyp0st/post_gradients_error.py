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

def exp_transform(time, f_time):
    n = len(time)
    tr_f_time = np.zeros(n-1)
    for i,t in enumerate(time[1:]):
        tr_f_time[i] = np.trapz(f_time * np.exp(-time/t), x=time)
    return tr_f_time

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
    # compute gradients error
    objects_init_gradients = {}
    objects_init_skew_gradients = {}
    objects_init_sym_gradients = {}
    for object_name in objects_j_0_0:
        objects_init_gradients[object_name] = []#[np.empty((3, 3))] * objects_j_0_0[object_name]["value"].shape[1]
        objects_init_skew_gradients[object_name] = []
        objects_init_sym_gradients[object_name] = []
        for j in range(0, objects_j_0_0[object_name]["value"].shape[1]):
            objects_init_gradients[object_name].append(np.empty((3, 3)))
            objects_init_gradients[object_name][j][0, 0] = objects_j_0_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][0, 1] = objects_j_0_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][0, 2] = objects_j_0_2[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 0] = objects_j_1_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 1] = objects_j_1_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][1, 2] = objects_j_1_2[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 0] = objects_j_2_0[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 1] = objects_j_2_1[object_name]["value"][0, j]
            objects_init_gradients[object_name][j][2, 2] = objects_j_2_2[object_name]["value"][0, j]
            objects_init_skew_gradients[object_name].append(0.5 * (objects_init_gradients[object_name][j] - objects_init_gradients[object_name][j].transpose()))
            objects_init_sym_gradients[object_name].append(0.5 * (objects_init_gradients[object_name][j] + objects_init_gradients[object_name][j].transpose()))
    objects_gradients_error = copy.deepcopy(objects_j_0_0)
    objects_skew_gradients_error = copy.deepcopy(objects_j_0_0)
    objects_sym_gradients_error = copy.deepcopy(objects_j_0_0)
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
                skew_gradients = 0.5 * (gradients - gradients.transpose())
                sym_gradients = 0.5 * (gradients + gradients.transpose())
                # error
                objects_gradients_error[object_name]["value"][i, j] = np.linalg.norm(gradients - objects_init_gradients[object_name][j])
                objects_skew_gradients_error[object_name]["value"][i, j] = np.linalg.norm(skew_gradients - objects_init_skew_gradients[object_name][j])
                objects_sym_gradients_error[object_name]["value"][i, j] = np.linalg.norm(sym_gradients - objects_init_sym_gradients[object_name][j])
        # info
        objects_gradients_error[object_name]["info"] = [info.replace("j_0_0", "|J_t - J_0|") for info in objects_gradients_error[object_name]["info"]]
        objects_skew_gradients_error[object_name]["info"] = [info.replace("j_0_0", "|O_t - O_0|") for info in objects_skew_gradients_error[object_name]["info"]]
        objects_sym_gradients_error[object_name]["info"] = [info.replace("j_0_0", "|E_t - E_0|") for info in objects_sym_gradients_error[object_name]["info"]]
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
    objects_skew_gradients_error_average = {object_name:{} for object_name in objects_gradients_error}
    objects_sym_gradients_error_average = {object_name:{} for object_name in objects_gradients_error}
    for object_name in objects_gradients_error_average:
        # value
        objects_gradients_error_average[object_name]["value"] = np.column_stack([np.average(objects_gradients_error[object_name]["value"], axis=1), 1.96 * np.std(objects_gradients_error[object_name]["value"], axis=1) / np.sqrt(objects_gradients_error[object_name]["value"].shape[1])])
        value_inf = np.average(objects_gradients_error_average[object_name]["value"][len(time)//2:,0])
        objects_gradients_error_average[object_name]["value"][:, 0] =  1.0 - objects_gradients_error_average[object_name]["value"][:, 0]/value_inf
        objects_gradients_error_average[object_name]["value"][:, 1] = objects_gradients_error_average[object_name]["value"][:, 1]/value_inf
        # info
        objects_gradients_error_average[object_name]["info"] = ["1-<|J_t - J_0|>/<|J_inf - J_0|>", "95CLI"]

        # value
        objects_skew_gradients_error_average[object_name]["value"] = np.column_stack([np.average(objects_skew_gradients_error[object_name]["value"], axis=1), 1.96 * np.std(objects_skew_gradients_error[object_name]["value"], axis=1) / np.sqrt(objects_skew_gradients_error[object_name]["value"].shape[1])])
        value_inf = np.average(objects_skew_gradients_error_average[object_name]["value"][len(time)//2:,0])
        objects_skew_gradients_error_average[object_name]["value"][:, 0] =  1.0 - objects_skew_gradients_error_average[object_name]["value"][:, 0]/value_inf
        objects_skew_gradients_error_average[object_name]["value"][:, 1] = objects_skew_gradients_error_average[object_name]["value"][:, 1]/value_inf
        # info
        objects_skew_gradients_error_average[object_name]["info"] = ["1-<|O_t - O_0|>/<|O_inf - O_0|>", "95CLI"]

        # value
        objects_sym_gradients_error_average[object_name]["value"] = np.column_stack([np.average(objects_sym_gradients_error[object_name]["value"], axis=1), 1.96 * np.std(objects_sym_gradients_error[object_name]["value"], axis=1) / np.sqrt(objects_sym_gradients_error[object_name]["value"].shape[1])])
        value_inf = np.average(objects_sym_gradients_error_average[object_name]["value"][len(time)//2:,0])
        objects_sym_gradients_error_average[object_name]["value"][:, 0] =  1.0 - objects_sym_gradients_error_average[object_name]["value"][:, 0]/value_inf
        objects_sym_gradients_error_average[object_name]["value"][:, 1] = objects_sym_gradients_error_average[object_name]["value"][:, 1]/value_inf
        # info
        objects_sym_gradients_error_average[object_name]["info"] = ["1-<|E_t - E_0|>/<|E_inf - E_0|>", "95CLI"]
    print("INFO: Done.")
    # save
    print("INFO: Saving...")
    libpost.savet(time, objects_gradients_error_average, "average_gradients_error")
    libpost.savet(time, objects_skew_gradients_error_average, "average_skew_gradients_error")
    libpost.savet(time, objects_sym_gradients_error_average, "average_sym_gradients_error")
    print("INFO: Done.")

    ##exp transform
    #print("INFO: Computing exponential transform...")
    #objects_gradients_error_average_exp_tr = {object_name:{} for object_name in objects_gradients_error_average}
    #for object_name in objects_gradients_error_average_exp_tr:
    #    # value
    #    objects_gradients_error_average_exp_tr[object_name]["value"] = exp_transform(time, objects_gradients_error_average[object_name]["value"][:,0])
    #    # info
    #    objects_gradients_error_average_exp_tr[object_name]["info"] = ["exp_tr_1-<|J_t - J_0|>/<|J_inf - J_0|>"]
    #print("INFO: Done.")
    ## save
    #print("INFO: Saving...")
    #libpost.savet(time[1:], objects_gradients_error_average_exp_tr, "exp_tr_gradients_error")
    #print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
