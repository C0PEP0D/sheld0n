#!/usr/bin/env python3

import os
import shutil

def set_flow_point_vortices_periodic():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_point_vortices_periodic')
    os.chdir('../..')
    # solutions
    os.chdir('param/solutions')
    # passive particles
    os.chdir('passive_particles')
    os.system('./.cli_choose cpp_passive_particles_periodic')
    os.chdir('..')
    # point vortices
    os.system('./.cli_create_new_equation point_vortices_periodic')
    os.chdir('point_vortices_periodic')
    os.system('./.cli_choose cpp_point_vortices_periodic')
    os.chdir('..')
    # end solutions
    os.chdir('../..')
    # parameters
    os.system('./.cli_set_parameter param/solutions/point_vortices_periodic MaxCirculation "4.0/Number"')
    ## param
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(4.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime"')

def set_solutions_passive_curve():
    os.chdir('param/solutions')
    # curve
    os.system('./.cli_create_new_equation passive_scalar_curve')
    os.chdir('passive_scalar_curve')
    os.system('./.cli_choose cpp_passive_scalar_curve')
    os.chdir('..')
    # back
    os.chdir('../..')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(4.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime"')

def main():
    set_flow_point_vortices_periodic()
    set_solutions_passive_curve()
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    ## ops
    os.remove("post_process/plot_average_vertical_velocity_over_time.py")
    os.remove("post_process/generate_trajectory_animation.py")
    shutil.copy(code_dir + "/app/post/generate_scalar_concentration_animation.py", "post_process/generate_scalar_concentration_animation.py")
    shutil.copy(code_dir + "/app/post/generate_profile_c_animation.py", "post_process/generate_profile_c_animation.py")
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
