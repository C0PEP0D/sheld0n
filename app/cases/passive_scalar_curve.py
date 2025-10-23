#!/usr/bin/env python3

import os

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
    ## param
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true}"')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(16.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime/16"')

def set_solutions_passive_curve():
    os.chdir('param/solutions')
    # nn swimmers
    os.system('./.cli_create_new_equation passive_scalar_curve')
    os.chdir('passive_scalar_curve')
    os.system('./.cli_choose cpp_passive_scalar_curve')
    os.chdir('..')
    # back
    os.chdir('../..')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(24.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave "NTime/4"')

def main():
    set_flow_point_vortices_periodic()
    set_solutions_passive_curve()
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/.."
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
