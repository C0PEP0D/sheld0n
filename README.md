# Sheld0n: Lagrangian active particles advection

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)
[![DOI](https://zenodo.org/badge/421041396.svg)](https://zenodo.org/badge/latestdoi/421041396)

A code that enables complex active particle advection in flows. 
The code is still in active developpement, feel free to ask for features.

This code enables to compute active particle trajectories inside flows. It enables the user to specify a complex behaviour of particles. It can be used with external flow data, thus enabling to use data from flow simulations or experiments. Moreover, provided an internet connection, the software enables to use flows of the [Johns Hopkins Turbulence Database](http://turbulence.pha.jhu.edu/).
Please keep in mind that this is a work in progress, all may not work out of the box yet.
This software should be usable on any operating system but only have been tested on recent Linux distributions (Ubuntu 20, Archlinux).

This repository contains:

1. [Lagrangian active particles advection software](./app) that binds low-level c++ modules into a high-level command line tool.
2. A few low-level c++ [modules](./modules) that can be used independently.

## Table of Contents

- [Background](#background)
- [Install](#install)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Background

This software has been produced during my PhD thesis and as part as the European Research Council project: [C0PEP0D](https://c0pep0d.github.io/)

## Install

### Dependencies

The dependencies are standard softwares that may already be installed on your system.
If not, you should be able to install these dependencies with your package manager.

* [**Python**](https://www.python.org/) must be installed
* [**CMake** `v?`](https://cmake.org/download/) or higher must be installed
* a c++20 compliant compiler, such as [**gcc** `v10`](https://askubuntu.com/questions/1192955/how-to-install-g-10-on-ubuntu-18-04) or higher must be installed
* the [**Threading Building Block Library** `v2018`](https://github.com/ibaned/tbb) or higher must be installed ([this version](https://github.com/wjakob/tbb) that enables is installing it using CMake is advised)

### Installing

Start by cloning this repository with its submodules.

```sh
$ git clone --recurse-submodules https://github.com/C0PEP0D/sheld0n.git
```

And that's it!
The executables are in the [cases](./cases) directory.

### Updating

A simple pull should be enough.

```sh
$ git pull --recurse-submodules
```

## Usage

The following covers basic usage of the code, while the documentation is improving, feel free to contact me if you have any questions regarding using this software.

Most scripts provided by this software contain their description, explaining how to use them. 
One can access this description using the following:

```sh
$ script -h
```
or
```sh
$ script --help
```

### Quick start

Go to the cases folder and and execute the script `generate_new_case` providing a name for that case:

```sh
$ cd cases
$ ./generate_new_case my_new_case
```

Then navigate in the case you new case, and run the case.

```sh
$ cd my_new_case
$ ./run
```

Once the simulation has started or finished, one can run some post processing:

```sh
$ ./post
```

Final data should be in the `post_process` directory. Further post processing can be done using various scripts in that directory.
Feel free to run the `--help` option of these scripts to learn how to use them.

### Editing simulation parameters

All parameters are included in the `param` directory.
One can edit any `parameters.h` file in this subtree as you see fit.
Furthermore can choose between different default simulation parameters using the `choose` scripts.
Again, feel free to use the `--help` option to learn how to use those scripts.

### Known issue

There is a memory leak somewhere. 
I am pretty sure it comes from the turblib library but I have not got the time to investigate it more.
You should be fine if you do not use the jhtdb flow.
If you do, just kill the process when too much memory is used and rerun it.

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.
Or just propose features you would like to have implemented in the code.

## License

[MIT](LICENSE) © Centrale Marseille, Rémi Monthiller

