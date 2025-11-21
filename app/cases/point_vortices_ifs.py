#!/usr/bin/env python3

import os
import shutil

def set_flow_point_vortices_ifs_particles():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_point_vortices')
    os.chdir('../..')
    # solutions
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation point_vortices -p cpp_point_vortices_ifs_particles')
    os.chdir('../..')
    # parameters
    ## param
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{false, false}"')

def set_solutions_ifs_particles():
    os.chdir('param/solutions')
    # ifs swimmers
    os.system('./.cli_create_new_equation ifs_particles')
    os.chdir('ifs_particles')
    os.system('./.cli_choose cpp_ifs_particles')
    os.chdir('..')
    # back
    os.chdir('../..')
    # parameters
    os.system('./.cli_set_parameter param cGroupSize 512')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(4.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime"')

def main():
    set_flow_point_vortices_ifs_particles()
    # edit meanVelocity
    os.system('./.cli_set_parameter param/flow meanVelocity "tSpaceVector({1.0, 0.0})"')
    # ifs particles
    set_solutions_ifs_particles()
    # edit passive_particles
    os.chdir('param/solutions/passive_particles')
    os.system('./.cli_choose cpp_source_of_passive_particles')
    os.chdir('../../..')
    # parameters
    # os.system('./.cli_set_parameter param/solutions/passive_particles Rate "512.0"')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_average_vertical_velocity_over_time.py", "post_process/plot_average_vertical_velocity_over_time.py")
    shutil.copy(code_dir + "/app/post/generate_trajectory_animation_2d.py", "post_process/generate_trajectory_animation_2d.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
