#!/usr/bin/env python3

import os

def set_flow_point_vortices_jet():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_point_vortices')
    os.chdir('../..')
    # solutions
    os.chdir('param/solutions')
    os.system('./.cli_create_new_equation point_vortices -p cpp_point_vortices_jet')
    os.chdir('../..')
    # parameters
    ## param
    os.system('./.cli_set_parameter param cLength 1.0')
    os.system('./.cli_set_parameter param cTime 1.0')
    os.system('./.cli_set_parameter param cDomainSize "{2.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{false, false}"')
    ## run
    os.system('./.cli_set_parameter param/run Dt 1.0/128.0')
    os.system('./.cli_set_parameter param/run NTime "int(8.0/Dt)"')
    os.system('./.cli_set_parameter param/run NSave NTime')

def main():
    set_flow_point_vortices_jet()
    # edit passive_particles
    os.chdir('param/solutions/passive_particles')
    os.system('./.cli_choose cpp_source_of_passive_particles')
    os.chdir('../../..')
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/../.."
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
