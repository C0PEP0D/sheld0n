#!/usr/bin/env python3

import os
import math
import numpy as np
import glob
import shutil

def set_flow_tgv():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_tgv')
    os.chdir('../..')
    os.system('./.cli_set_parameter param cLength M_PI')
    os.system('./.cli_set_parameter param cTime M_PI')
    os.system('./.cli_set_parameter param cDomainSize "{2*M_PI, 2*M_PI}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')

def set_solutions_surfers(c_time, c_length):
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation surfers')
    os.chdir('surfers')
    os.system('./.cli_choose cpp_surfers')
    os.chdir('..')
    # time horizon
    os.system('./.cli_batch_copy_equation surfers -p TimeHorizon -f EnvParameters::cTime -v ' + " ".join([str(v) for v in np.arange(0.0, 1.0 + 0.125, 0.125)]))
    os.system('./.cli_remove_equation surfers')
    # swimming velocity
    surfers = " ".join(glob.glob("surfers__*"))
    c_velocity = c_length / c_time
    os.system('./.cli_batch_copy_equation ' + surfers + ' -p SwimmingVelocity -f EnvParameters::cVelocity -v ' + ' '.join([str(v) for v in [0.25, 0.5, 1.0, 2.0, 4.0]]))
    os.system('./.cli_remove_equation ' + surfers)
    os.chdir('../..')

def main():
    set_flow_tgv()
    set_solutions_surfers(math.pi, math.pi)
    # param
    os.system('./.cli_set_parameter param cGroupSize 128')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "8.0 * M_PI / Dt"')
    os.system('./.cli_set_parameter param/run NSave 16')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_vertical_migration_performance_over_time_horizon.py", "post_process/plot_vertical_migration_performance_over_time_horizon.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
