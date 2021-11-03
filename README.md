# Sheld0n: Lagrangian active particles advection

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

A code that enables complex active particle advection in flows.

This code enables to compute active particle trajectories inside flows. It enables the user to specify a complex behaviour of particles. It can be used with external flow data, thus enabling to use data from flow simulations or experiments. Please keep in mind that this is a work in progress, all may not work out of the box yet.
This software should be usable on any operating system but only have been tested on recent Linux distributions (Ubuntu 20, Archlinux).

This repository contains:

1. [Lagrangian active particles advection software](./app) that binds low-level c++ modules into a high-level command line tool.
2. A few low-level c++ modules [modules](./modules) that can be used independently.

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
* a c++17 compliant compiler, such as [**gcc** `v9`](https://cmake.org/download/) or higher must be installed
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
$ git pull
```

## Usage

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

Go to the cases folder and a choose a case:

```sh
$ cd cases
$ ls
adaptative_surfers spherical_surfers comparison surfers tracers
```

Then navigate in the case you choose, **surfers** for example, and run the case.

```sh
$ cd surfers
$ ./run
```

Once the simulation has started or finished, one can run some post processing:

```sh
$ ./post
```

Final data should be in the `post_process` directory. Further post processing can be done using various scripts in that directory. Post processing will generated CSV files that can then be processed thirdparty softwares to plot curves.

### Creating a new case

Go to the cases folder and run the new_case script

```sh
$ cd cases
$ ./new_case new_case_name
```

### Editing simulation parameters

All parameters are included in the `param`.
One can edit any `parameters.h` file in this subtree.
Furthermore can choose between different simulation parameters using the `choose` scripts.
The `print_param` is a helper script to print all parameters that can be used to check all simulation parameters before running a simulation.

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.

## License

[MIT](LICENSE) © Centrale Marseille, Rémi Monthiller

