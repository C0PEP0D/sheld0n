#!/usr/bin/env python3

import os
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

def set_solutions_soft_swimmers():
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    os.chdir('../..')

def main():
    set_flow_tgv()
    set_solutions_soft_swimmers()
    # param
    os.system('./.cli_set_parameter param cGroupSize 256')
    # run
    os.system('./.cli_set_parameter param/run Dt "1.0/128.0"')
    os.system('./.cli_set_parameter param/run NTime "16.0 * M_PI / Dt"')
    os.system('./.cli_set_parameter param/run NSave "NTime/16"')
    # post
    os.system('./.cli_set_parameter param/run Number 0')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    os.remove("post_process/plot_average_vertical_velocity_over_time.py")
    os.remove("post_process/generate_trajectory_animation.py")
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation.py", "post_process/generate_scalar_concentration_animation.py")
    shutil.copy(code_dir + "/app/post/generate_profile_c_animation.py", "post_process/generate_profile_c_animation.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
