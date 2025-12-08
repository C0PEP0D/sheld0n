#!/usr/bin/env python3

import os
import shutil

def set_flow_point_vortices_periodic():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_point_vortices')
    os.chdir('../..')
    # solutions
    os.chdir('param/solutions')
    # passive particles
    os.chdir('passive_particles')
    os.system('./.cli_choose cpp_passive_particles')
    os.chdir('..')
    # point vortices
    os.system('./.cli_create_new_equation point_vortices')
    os.chdir('point_vortices')
    os.system('./.cli_choose cpp_point_vortices')
    os.chdir('..')
    # end solutions
    os.chdir('../..')
    # parameters
    os.system('./.cli_set_parameter param/solutions/point_vortices InitCirculation "16.0/InitNumber"')
    ## param
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(2.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime"')

def set_solutions():
    os.chdir('param/solutions')
    # passive scalar blobs
    os.system('./.cli_create_new_equation passive_scalar_blobs')
    os.chdir('passive_scalar_blobs')
    os.system('./.cli_choose cpp_passive_scalar_blobs')
    os.chdir('..')
    # back
    os.chdir('../..')
    # set parameters
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Diffusivity 1.0e-16')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Dx 2.5e-2')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs InitS 1.0e-3')
    os.system('./.cli_set_parameter param/solutions/passive_scalar_blobs Cth 1.0e-3')

def main():
    set_flow_point_vortices_periodic()
    set_solutions()
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## copy
    shutil.copy(code_dir + "/app/post/plot_cmax_over_time.py", "post_process/plot_cmax_over_time.py")
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation_2d.py", "post_process/generate_scalar_concentration_animation_2d.py")
    shutil.copy(code_dir + "/app/post/generate_trajectory_animation_2d.py", "post_process/generate_trajectory_animation_2d.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
