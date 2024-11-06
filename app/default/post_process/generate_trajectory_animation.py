#!/usr/bin/env python3

# command line program
import argparse
# deepcopy
import copy
# numpy
import numpy as np
# internal modules
import libpost
# plotting
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def parse():
    parser = argparse.ArgumentParser(description='Plots 2D trajectories of all solutions over time, assuming pos_0 as x and pos_1 as y.')
    parser.add_argument('--step', '-s', type=int, default=1, help='animation frame step')
    return parser.parse_args()

def main(anim_step):
    print("INFO: Reading equation names...", flush=True)
    equation_name_list = libpost.get_equation_names()
    print("INFO: Reading time...", flush=True)
    time_dir_list, time_list, time = libpost.get_time()
    print("INFO: Preparing for animation...", flush=True)
    cmap = plt.cm.get_cmap("hsv", len(equation_name_list))
    art_fig, art_ax = plt.subplots()
    art_ax.set_aspect('equal', 'box')
    art_ax.grid(False)
    art_ax.axis('off')
    art_ax.set_facecolor("black")
    art_fig.set_facecolor("black")
    trajectories = []
    artists = []
    for equation_index, name in enumerate(equation_name_list):
        print("\tINFO: Processing equation {name}...".format(name=name), flush=True)
        for time_index in range(0, time.size):
            if time_index % anim_step == 0:
                current_time = time[time_index]
                print("\t\tINFO: Processing t={t}/{t_f}...".format(t=current_time, t_f=time[-1]), flush=True)
                print("\t\t\tINFO: Reading data...", flush=True)
                equation = libpost.get_equation(time_dir_list[time_list.index(current_time)], name)
                info = libpost.get_equation_properties(equation, [".*__pos_0"])["info"]
                if info.size > 0:
                    pos_0 = libpost.get_equation_properties(equation, [".*__pos_0"])["value"]
                    pos_1 = libpost.get_equation_properties(equation, [".*__pos_1"])["value"]
                    print("\t\t\t\tINFO: Sorting data...", flush=True)
                    sorted_index = np.empty(pos_0.size)
                    sorted_index[:] = np.nan
                    for index in range(len(info)):
                        sorted_index[index] = libpost.get_properties_from_string(info[index])["particle"]
                    sorted_index = np.argsort(sorted_index)
                    sorted_index = sorted_index[np.logical_not(np.isnan(sorted_index))]
                    # updating everything
                    info = info[sorted_index]
                    pos_0 = pos_0[sorted_index]
                    pos_1 = pos_1[sorted_index]
                    print("\t\t\tINFO: Processing data...", flush=True)
                    if not trajectories:
                        for index in range(pos_0.size):
                            trajectories.append({"x":[pos_0[index]], "y":[pos_1[index]]})
                    else:
                        for index in range(pos_0.size):
                            trajectories[index]["x"].append(pos_0[index])
                            trajectories[index]["y"].append(pos_1[index])
                    print("\t\t\tINFO: Done.", flush=True)
                    print("\t\t\tINFO: Animating...", flush=True)
                    artists.append([])
                    for index in range(len(trajectories)):
                        art, = art_ax.plot(trajectories[index]["x"], trajectories[index]["y"], color=(0.5, 0.5, 0.75))
                        artists[-1].append(art)
                    art = art_ax.scatter(pos_0, pos_1, color=(0.75, 0.75, 1.0))
                    artists[-1].append(art)
                print("\t\tINFO: Done processing t={t}/{t_f}.".format(t=current_time, t_f=time[-1]), flush=True)
        print("\tDone processing equation {name}.".format(name=name), flush=True)
    print("\t\tINFO: Animating...", flush=True)
    anim = animation.ArtistAnimation(art_fig, artists, interval=30)
    anim.save("trajectory_animation.mp4")
    print("\t\tINFO: Done.", flush=True)
    print("INFO: Done.", flush=True)

if __name__ == '__main__':
    args = parse()
    main(args.step)
