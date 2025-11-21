#!/usr/bin/env python3

import os
import shutil

def set_flow_tgv():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_tgv')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions_nn_swimmers():
    os.chdir('param/solutions')
    # nn swimmers
    os.system('./.cli_create_new_equation nn_swimmers')
    os.chdir('nn_swimmers')
    os.system('./.cli_choose cpp_nn_swimmers')
    os.chdir('..')
    # naive swimmers
    os.system('./.cli_create_new_equation naive_swimmers')
    os.chdir('naive_swimmers')
    os.system('./.cli_choose cpp_buoyant_particles')
    os.chdir('..')
    # surfers
    os.system('./.cli_create_new_equation surfers')
    os.chdir('surfers')
    os.system('./.cli_choose cpp_surfers')
    os.chdir('..')
    # back
    os.chdir('../..')
    # set surfing parameters
    os.system('./.cli_set_parameter param/solutions/surfers TimeHorizon "0.25*EnvParameters::cTime"')

def main():
    set_flow_tgv()
    set_solutions_nn_swimmers()
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "8.0 * M_PI / Dt"')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_average_vertical_velocity_over_time.py", "post_process/plot_average_vertical_velocity_over_time.py")
    shutil.copy(code_dir + "/app/post/generate_trajectory_animation_2d.py", "post_process/generate_trajectory_animation_2d.py")
    # remove symbolic link
    os.unlink("learn")
    # print
    print('WARNING: This case is designed for the evaluation of a neural network learn using the rl_tgv case.\n         To do so, copy the files in "param/learn/neural_network/data" from the rl_tgv case to this one after the reinforcement learning process ended.\n         Make sure the environment parameters from the rl_tgv case are the same (in particular the agent\'s swimming velocity) as this one before running the evaluation.')

if __name__ == '__main__':
    main()
