#!/usr/bin/env python3

import os

def set_flow_jhtdb():
    os.chdir('param/flow')
    os.system('./.cli_choose cpp_jhtdb_isotropic')
    os.chdir('../..')
    ## param
    os.system('./.cli_set_parameter param DIM 3')
    os.system('./.cli_set_parameter param cLength 0.00280')
    os.system('./.cli_set_parameter param cTime 0.0424')
    os.system('./.cli_set_parameter param cDomainSize "{1.0, 1.0, 1.0}"')
    os.system('./.cli_set_parameter param cDomainIsAxisPeriodic "{true, true, true}"')
    ## run
    os.system('./.cli_set_parameter param/run Dt 0.002')
    os.system('./.cli_set_parameter param/run NTime "int(10.056/Dt)"')
    os.system('./.cli_set_parameter param/run NSave NTime')

def main():
    set_flow_jhtdb()
    # post processing
    ## input
    script_dir = os.path.dirname(os.path.realpath(__file__))
    code_dir = script_dir + "/.."
    # remove symbolic link
    os.unlink("learn")
    # shutil.rmtree("param/learn")

if __name__ == '__main__':
    main()
