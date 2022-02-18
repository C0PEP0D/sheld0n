#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# file
import os.path
# numpy
import numpy as np
import scipy as sp
import scipy.integrate
import scipy.linalg
import scipy.interpolate
# internal modules
import libpost
# tmp plot
import matplotlib.pyplot as plt

D = 1e-4
s0 = 1.0
dS0 = 1.0
nc = 100
dc = 1.0 / (nc - 1.0)
nC = nc
dC = 1.0 / (nC - 1.0)

def parse():
    parser = argparse.ArgumentParser(description='Computes statistics of the lagrangian gradients matrix (computed along particle trajectories)')
    return parser.parse_args()

def dL_dt(foperator, object_name, j, L, t):
    return np.matmul(foperator(min(t, 10.0)), L.reshape((3,3), order='C')).flatten(order='C')

def F(a):
    return np.log((4.0/a + 1) + np.sqrt((4.0/a + 1)**2 - 1.0)) - 1.6/np.sqrt(a + 1.4)

def Q(C, eta, etap, etapp):
    if C**(-2.0) > etap:
        if eta > C**(-2.0):
            return dS0 * s0 / (np.pi * C**4 * np.sqrt(eta - C**(-2.0)) * np.sqrt(etap - etapp)) * F(2.0 * (C**(-2.0) - etap) * (eta - etapp) / ((eta - C**(-2.0)) * (etap - etapp)))
        else:
            return 0.0
    elif C**(-2.0) < etap:
        if C**(-2.0) > etapp:
            return dS0 * s0 / (np.pi * C**4 * np.sqrt(eta - etap) * np.sqrt(C**(-2.0) - etapp)) * F(2.0 * (etap - C**(-2.0)) * (eta - etapp) / ((C**(-2.0) - etapp) * (eta - etap)))
        else:
            return 0.0

def main():
    print("INFO: Post processing flow velocity gradients statistics sampled by lagrangian objects.", flush=True)
    object_names = libpost.get_object_names()
    print("INFO: Object names are:", " ".join(object_names), flush=True)
    print("INFO: Reading time...", flush=True)
    if os.path.isfile("time.npy"):
        time = np.load("time.npy")
    else:
        time = libpost.get_time();
        np.save("time", time)
    print("INFO: Done.", flush=True)
    print("INFO: Reading int L^t L...", flush=True)
    int_Lt_L_to_process = []
    int_Lt_L_value = {}
    for object_name in object_names:
        if os.path.isfile(object_name + "_int_Lt_L.npy"):
            int_Lt_L_value[object_name] = np.load(object_name + "_int_Lt_L.npy")
        else:
            int_Lt_L_to_process.append(object_name)
    print("INFO: Done.", flush=True)
    if int_Lt_L_to_process:
        print("INFO: Reading L...", flush=True)
        L_to_process = []
        L_value = {}
        for object_name in int_Lt_L_to_process:
            if os.path.isfile(object_name + "_L.npy"):
                L_value[object_name] = np.load(object_name + "_L.npy")
            else:
                L_to_process.append(object_name)
        print("INFO: Done.", flush=True)
        if L_to_process:
            # get gradient matrix
            print("INFO: Reading objects properties...", flush=True)
            objects_j_0_0 = libpost.get_objects_properties(["j_0_0"], L_to_process)
            objects_j_0_1 = libpost.get_objects_properties(["j_0_1"], L_to_process)
            objects_j_0_2 = libpost.get_objects_properties(["j_0_2"], L_to_process)
            objects_j_1_0 = libpost.get_objects_properties(["j_1_0"], L_to_process)
            objects_j_1_1 = libpost.get_objects_properties(["j_1_1"], L_to_process)
            objects_j_1_2 = libpost.get_objects_properties(["j_1_2"], L_to_process)
            objects_j_2_0 = libpost.get_objects_properties(["j_2_0"], L_to_process)
            objects_j_2_1 = libpost.get_objects_properties(["j_2_1"], L_to_process)
            objects_j_2_2 = libpost.get_objects_properties(["j_2_2"], L_to_process)
            print("INFO: Done.", flush=True)
            print("INFO: Gradients reconstruction...", flush=True)
            gradients_value = {}
            operator_value = {}
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
                operator_value[object_name] = -gradients_value[object_name].transpose(0, 1, 3, 2)
            print("INFO: Done.", flush=True)
            print("INFO: Cleaning...", flush=True)
            del objects_j_0_0
            del objects_j_0_1
            del objects_j_0_2
            del objects_j_1_0
            del objects_j_1_1
            del objects_j_1_2
            del objects_j_2_0
            del objects_j_2_1
            del objects_j_2_2
            print("INFO: Done.", flush=True)
            print("INFO: Computing L...", flush=True)
            for object_name in gradients_value:
                L_value[object_name] = copy.deepcopy(gradients_value[object_name])
            for object_name in gradients_value:
                print("INFO:    Processing " + object_name + "...", flush=True)
                # value
                for j in range(gradients_value[object_name].shape[1]):
                    foperator = sp.interpolate.interp1d(time, operator_value[object_name][:, j, :, :], kind="cubic", axis=0)
                    L_value[object_name][:, j, :, :] = sp.integrate.odeint(lambda L, t : dL_dt(foperator, object_name, j, L, t), np.identity(3).flatten(order='C'), time).reshape((gradients_value[object_name].shape[0], 3, 3), order='C')
                print("INFO:    " + object_name + " done.", flush=True)
            print("INFO: Done.", flush=True)
            print("INFO: Saving L...", flush=True)
            for object_name in gradients_value:
                np.save(object_name + "_L", L_value[object_name])
            print("INFO: Done.", flush=True)
        print("INFO: Computing int L^t L...", flush=True)
        for object_name in int_Lt_L_to_process:
            print("INFO:    Processing " + object_name + "...", flush=True)
            # value
            int_Lt_L_value[object_name] = sp.integrate.cumtrapz(np.matmul(L_value[object_name].transpose(0, 1, 3, 2), L_value[object_name], axes=[(2, 3), (2, 3), (2, 3)]), axis=0, x=time)
            print("INFO:    " + object_name + " done.", flush=True)
        print("INFO: Done.", flush=True)
        print("INFO: Saving int_Lt_L...", flush=True)
        for object_name in int_Lt_L_to_process:
            np.save(object_name + "_int_Lt_L", L_value[object_name])
        print("INFO: Done.", flush=True)
    print("INFO: Computing Tau...", flush=True)
    Tau_value = {}
    for object_name in object_names:
        print("INFO:    Processing " + object_name + "...")
        # value
        Tau_value[object_name] = np.identity(3) + 4.0 * D / s0**2 * int_Lt_L_value[object_name]
        print("INFO:    " + object_name + " done.", flush=True)
    print("INFO: Done.", flush=True)
    print("INFO: Computing c pdf...", flush=True)
    c_pdf = {object_name:np.zeros((Tau_value[object_name].shape[0], nc)) for object_name in Tau_value}
    for object_name in Tau_value:
        print("INFO:    Processing " + object_name + "...", flush=True)
        # value
        # for i in range(Tau_value[object_name].shape[0]):
        for i in range(10,11):
            for ic in range(1, nc):
                c = ic * dc
                val = np.zeros(nC)
                for iC in range(ic + 1, nC):
                    C = iC * dC
                    for j in range(Tau_value[object_name].shape[1]):
                        etas = np.linalg.eigvalsh(Tau_value[object_name][i,j]).tolist()
                        etas.sort()
                        etas.reverse()
                        if etas[0] < 1.0:
                            print(etas, flush=True)
                        val[iC] += Q(C, etas[0], etas[1], etas[2])
                    val[iC] /= c * np.sqrt(np.log(C/c))
                c_pdf[object_name][i, ic] = np.trapz(val, dx=dC) / Tau_value[object_name].shape[1]
            plt.plot(np.linspace(0.0, 1.0, nc), c_pdf[object_name][i, :])
        plt.savefig("test.png")
        print("INFO:    " + object_name + " done.", flush=True)
    # print("INFO: Done.")
    # print("INFO: Saving pdfs (not done yet)...")
    # print("INFO: Done.")

if __name__ == '__main__':
    args = parse()
    main()
