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
    parser = argparse.ArgumentParser(description='Computes particles swimming velocity statistics.')
    return parser.parse_args()

def main():
    # get gradient matrix
    time = libpost.get_time();
    # get axis
    objects_us = libpost.get_objects_properties(["us"])
    objects_us_average = {object_name:{"value":np.array([np.average(objects_us[object_name]["value"])]), "info":["average_us"]} for object_name in objects_us}
    # reduce axis to a scalar
    objects_us_2 = copy.deepcopy(objects_us)
    for object_name in objects_us:
        # value
        for i in range(0, objects_us[object_name]["value"].shape[0]):
            for j in range(0, objects_us[object_name]["value"].shape[1]):
                # get us
                us = objects_us[object_name]["value"][i,j]
                # compute
                objects_us_2[object_name]["value"][i, j] = us*us
        # info
        objects_us_2[object_name]["info"] = [info.replace("us", "us^2") for info in objects_us[object_name]["info"]]
    objects_us_2_average = {object_name:{"value":np.array([np.average(objects_us_2[object_name]["value"])]), "info":["average_us^2"]} for object_name in objects_us_2}
    # compute fft
    objects_fft_us = copy.deepcopy(objects_us)
    objects_fft_us_2 = copy.deepcopy(objects_us_2)
    for object_name in objects_fft_us:
        # value
        objects_fft_us[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_us[object_name]["value"], axis=0))/objects_fft_us[object_name]["value"].shape[0]
        objects_fft_us_2[object_name]["value"] = np.abs(np.fft.rfft(objects_fft_us_2[object_name]["value"], axis=0))/objects_fft_us_2[object_name]["value"].shape[0]
        # info
        objects_fft_us[object_name]["info"] = [info.replace("us", "fft_us") for info in objects_fft_us[object_name]["info"]]
        objects_fft_us_2[object_name]["info"] = [info.replace("us^2", "fft_us^2") for info in objects_fft_us_2[object_name]["info"]]
    # average fft and 95CLI
    objects_average_fft_us = copy.deepcopy(objects_fft_us)
    objects_average_fft_us_2 = copy.deepcopy(objects_fft_us_2)
    for object_name in objects_average_fft_us:
        # value
        objects_average_fft_us[object_name]["value"] = np.column_stack([np.average(objects_fft_us[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_us[object_name]["value"], axis=1) / np.sqrt(objects_fft_us[object_name]["value"].shape[1])])
        objects_average_fft_us_2[object_name]["value"] = np.column_stack([np.average(objects_fft_us_2[object_name]["value"], axis=1), 1.96 * np.std(objects_fft_us_2[object_name]["value"], axis=1) / np.sqrt(objects_fft_us_2[object_name]["value"].shape[1])])
        # info
        objects_average_fft_us[object_name]["info"] = ["average_fft_us", "95CLI"]
        objects_average_fft_us_2[object_name]["info"] = ["average_fft_us^2", "95CLI"]
    # save
    angular_frequency = 2 * np.pi / (time[-1] - time[0]) * np.linspace(1, len(time)//2+2, num=len(time)//2+1)
    libpost.saveaf(angular_frequency, objects_average_fft_us, "average_fft_us")
    libpost.save(objects_us_average, "average_us")
    libpost.saveaf(angular_frequency, objects_average_fft_us_2, "average_fft_us_2")
    libpost.save(objects_us_2_average, "average_us_2")

if __name__ == '__main__':
    args = parse()
    main()
