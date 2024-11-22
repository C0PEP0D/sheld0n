# Adding new particles to the simulation

Welcome to the tutorial series that will teach you how to use the `sheld0n` code.
This tutorial series assumes you already learnt the basic usage of the code in the [README](../README.md) file.

## Table of Contents

- [Setting up the case](#setting-up-the-case)
- [Global parameters](#global-parameters)
- [Adding a new type of particle](#adding-a-new-type-of-particle)
- [Choosing the type of particle](#choosing-the-type-of-particle)
- [Running the simulation](#running-the-simulation)
- [Next tutorial](#next-tutorial)

## Setting up the case 

Start by creating a new case and moving to its root.

```sh
$ cd cases/
$ ./generate_new_case case_00
$ cd case_00/
```

## Global parameters

All parameters are located in the directory `param`.
Let's first open the file `param/parameters.h` and analyse its content.

In this file, you can:
* set the simulation in 2D or in 3D by setting the variable `DIM`.
* control how the random generation of numbers is managed by setting the variable `randomSeed`
* define optional parameters such as characteristic scales to help setting other parameters of the simulation case.

```cpp
9  // define if the simulation is in 2D or 3D 
10 constexpr unsigned int DIM = 2;
11 // definition of a SpaceVector and a SpaceMatrix,
12 // this should not be edited
13 using tSpaceVector = tVector<DIM>;
14 using tSpaceMatrix = tMatrix<DIM, DIM>;
15
16 // main simulation parameters
17 // the users can add whatever parameters they judge suitable,
18 // these parameters are accessible from the other parameter files
19 struct EnvParameters {
20      // optional characteristic group size. 
21      // should be greater than zero.
22      constexpr static const double cGroupSize = 16;
23      // optional characteristic scales used to parameterize equations.
24      constexpr static const double cLength = M_PI;
25      constexpr static const double cTime = M_PI;
26      constexpr static const double cVelocity = cLength / cTime;
27      // seed used for random generation
28      constexpr static const unsigned int randomSeed = 0;
29      EnvParameters() {
30          rand0m::seed(randomSeed); // comment this line to set a random seed
31      }
32 };
```

Let's move on for now, we'll come back to these parameters later.

## Adding a new type of particle

The default simulation case created using the `./generate_new_case` script is a 2D simulation of passive particles in a Taylor-Green flow.

Let's first try to add some buoyant particles in the flow.
To do so, move to the `param/solutions` directory.

```sh
$ cd param/solutions/
```

This directory contains the parameters that describe the equation of motion of all particles in the flow that will be solved by the flow.
Checkout its content.

```sh
$ ls
batch_copy_equation  copy_equation  create_new_equation  parameters.h  passive_particles  remove_equation  rename_equation
```

The `parameters.h` file lists the equations to be solved in your simulation.
Contrary to most of the other `parameters.h` files in the `param/` directory, this file is solely meant to be modified using the scripts `batch_copy_equation`, `copy_equation`, `create_new_equation`, `remove_equation`, `rename_equation`.

Each execution of a script will change the directories content while editing the `parameters.h` file.

For now, our simulation only solves the trajectory of passive particles, represented by the `passive_particles` directory.
Let's try to add **buoyant particles** in the flow using the `create_new_equation` script and specify a name for these particles.

```sh
$ ./create_new_equation buoyant_particles
```

Checkout again the content of the directory.

```sh
$ ls
batch_copy_equation  buoyant_particles  copy_equation  create_new_equation  parameters.h  passive_particles  remove_equation  rename_equation
```

The `buoyant_particles` directory appeared. 
However when creating a new equation, regardless of its name, the default behavior is the behavior of passive particles so we will have to change that.

Move into that directory and checkout its content.

```sh
$ cd buoyant_particles
$ ls
choose  parameters.h
```

Let's open the `parameters.h` file and analyse its content.
Every part of the file that can be edited by the user is between comment flags such as the following.

```cpp
// ---------------- CUSTOM [...] START
// [...]
// ---------------- CUSTOM [...] END
```

Let's focus on the first editable part of the file: the equation parameters.
The first parameter, `StateSize`, represents the dimension of the state variable you want to solve.

In our case, the state variable we want to solve is the position of a particle. 
This represents a state variable of dimension `2` in 2D and `3` in 3D (we will go through a different example later on).
Currently `StateSize` is set to `DIM` representing the current dimension of the space defined in the `param/parameters.h` file.

```cpp
22	// ---------------- CUSTOM EQUATION PARAMETERS START
23	static const unsigned StateSize = DIM; // dimension of the state variable 
24	// feel free to add parameters if you need
25	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
26	// ---------------- CUSTOM EQUATION PARAMETERS END
```

The second parameter, `Number`, defines the number of particles to be set inside the simulation.
Currently, it is set to `EnvParameters::cGroupSize`. 
If you remember well, `EnvParameters::cGroupSize` is defined in `param/parameters.h` where it is set to `16`.
Therefore `Number = EnvParameters::cGroupSize;` is equivalent `Number = 16;`.

The use of a global parameter `EnvParameters::cGroupSize` may be useful in certain cases but is completely optional.

Furthermore, when defining parameters, simple mathematical operations can be performed:
```cpp
25	static const unsigned Number = 2 * EnvParameters::cGroupSize; // number of members in the group
```
```cpp
25	static const unsigned Number = EnvParameters::cGroupSize / 2; // number of members in the group
```

> [!NOTE]
> You can also add your own parameters in between these flags if you need.

Let's move on to the next editable part: the definition of the equation and more specifically, the definition of the temporal derivative of your state variables.

```cpp
31		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
32			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);
33
34			// ---------------- CUSTOM EQUATION START
35			// input
36			const tView<const tSpaceVector> x(pState);
37			// flow
38			const tSpaceVector u = Flow::getVelocity(x.data(), t);
39			// output
40			tView<tSpaceVector> dX(dState.data());
41			dX = u;
42			// ---------------- CUSTOM EQUATION END
43
44			// return result
45			return dState;
46		}
```

This function takes three arguments:
* `pState`, an array of scalars of size `StateSize` that represent the current values of your state variables
* `stateSize` equal to `StateSize` in this particular case
* `t` represents the current time of the simulation

> [!NOTE]
> For the reader that knows about C++, all pointers in the code will be preceded by the letter *p*.
> That is why the array is named *pState* rather that *state*.

The variable `dState` represents the temporal derivative of `pState` that describes the motion of this type of particle.
The code in between the `CUSTOM EQUATION` flags is meant to encode that particle behavior.

Let's analyse further this code. 
In the line **36**, the first 2 elements of the array `pState` are interpreted as a 2D Vector (`tSpaceVector`) called `x` here and representing the particle position.
This variable `x` can now be used as a vector and employed in mathematical expressions as such.

The line **38** just means we are getting and storing the flow velocity at position `x` and time `t` in the variable `u`.

In the line **40**, the first 2 elements of the array `dState` are interpreted as a `tSpaceVector`.
The variable `dX` now represent the temporal derivative of `x` aka the particle velocity.

As stated above, the default behavior of a new equation added in the solver is that of a passive particle in a flow.
The motion of such a particle is described by the following equation,
```math
\frac{d \vec{x}}{dt} = \vec{u} \left ( \vec{x}, t \right )
```
with $\vec{x}$ the position of the particle, $\vec{u}$ the flow velocity field and $t$ the time.
This is exactly what the line **41** states and this is the line that should be edited to change the behavior of the particle.

Before changing the behavior from a passive particle to a buoyant particle, let's move on to :
* the `init` function, used to initialize the state variables of your particles.
* the `post` function, used to extract data from the simulation when post processing.
```cpp
57	static void init(double* pState) {
	// [...]
72	}
	// [...]
77	static std::map<std::string, tScalar> post(const double* pState, const double t) {
	// [...]
93	}

```

Contrary to the `stateTemporalDerivative` function, these functions affect all the particles of this type in the simulation (their number defined by the parameter `Number`).
Therefore, one must iterate over the number of particles to initialize or post process each particle.

Currently the function `init` sets the particle position randomly within a box of center `BoxCenter` and size `BoxSize` and the `post` function extracts the position of each particle and computes the average position of all particles.

## Choosing the type of particle

Now that we analysed the `parameters.h` file of a passive particle, we want to change that file to match the behavior of a **buoyant** particle.
We could manually edit the `parameters.h`, but we can also use the `choose` script in the same directory to choose another default behavior.

Let's first see what are the available options:
```sh
$ ./choose -h
usage: choose [-h] {surfers,passive_particles,buoyant_particles,inertial_particles}

Script to choose parameters among default ones.

positional arguments:
  {surfers,passive_particles,buoyant_particles,inertial_particles}
                        specify your choice

options:
  -h, --help            show this help message and exit
```

Buoyant particles are an available option, let's choose that.
```sh
$ ./choose buoyant_particles
```

> [!CAUTION]
> Using a `choice` script will override the `parameters.h` file in the same directory and all changes will be lost.

If you open again the `parameters.h` file, you'll see it has changed.
You may note two new parameters,
```cpp
26	static constexpr float BuoyantVelocity = 0.5;
27	static constexpr std::array<double, DIM> BuoyancyDirection = {0.0, 1.0}; // defined for 2D simulations, use {0.0, 0.0, 1.0} for 3D
```
and a different definition of the temporal derivative corresponding to the following equation
This code corresponds to the definition of the following equation
```math
\frac{d \vec{x}}{dt} = \vec{u} \left ( \vec{x}, t \right ) + V_{\mathrm{buoyancy}} \vec{z} \, \mathrm{,}
```
with $V_{\mathrm{buoyancy}}$ the buoyancy induced velocity of the particle and $\vec{z}$ the vertical.

OK, now our buoyant particles are setup. Now that we know how to do, let's just add inertial particles to the simulation just for fun.

```sh
$ cd ..
$ ./create_new_equation inertial_particles
$ cd inertial_particles
$ ./choose inertial_particles
```

Before moving on, let's just analyse the `parameters.h` file of our inertial particles.
First of all, the motion of inertial particles is described by
```math
\frac{d \vec{x}}{dt} = \vec{v}
```
and
```math
\frac{d \vec{v}}{dt} = \frac{1}{\tau} \left [ u \left ( \vec{x}, t \right ) - \vec{v} \right ] \, \mathrm{,}
```
with a $\vec{v}$ the velocity of the particle and $\tau$ a constant reaction time.

This time, this particle is described by two state variables, its position and its velocity, both of dimension `DIM = 2`.
Therefore you can see that the parameter `StateSize` is set accordingly.
```sh
23	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
```

You can read further the file to understand how having two state variable changes:
* the way to define the temporal derivative.
* how to initialize the state of your particles.
* how to add several state variables in the post processing.

## Running the simulation

To control further the simulation, three other directories exists with parameters you can set.
* The `param/flow` directory where you can choose and customize the flow.
* The `param/run` directory where you can set the parameters of the solver (such as the time step, the total time of the simulation, etc...).
* The `param/post` directory where you can control the post processing.

Once that is done, we can run the simulation and the post processing.

```sh
$ cd ../../..
$ ./run
```

```sh
$ ./post
```

Finally one can visualize its simulation by generating an animation of the particle trajectories.

```sh
$ cd post_process
$ ls
generate_trajectory_animation.py  libpost.py  plot_over_time.py  time
$ ./generate_trajectory_animation.py
$ ls
generate_trajectory_animation.py  libpost.py  plot_over_time.py  time  trajectory_animation.mp4
```

The `time` directory at the root of the case contains the saved state of all particles for each time step saved once the simulation has been run.
If the simulation stops before it ends for any kind of reason, when running again the simulation, the last saved simulation step in `time` will be used to continue the simulation.
This also means that you can increase the total number of time steps after a simulation without having to run again the beginning of the simulation.
However, you'll need to remove the directory `time` to rerun the simulation from the beginning.

Similarly, the directory `post_process/time` is created when running the post processing and can be continued if the post processing ended prematurely.

In certain cases, if the simulation or the post_processing was stopped while writing a file, the last time step may be corrupted.
In that case, just delete the last step to continue from the previous step.

Because the `run` and the `post` are separated, you may change any post-processing function after the simulation has been executed without having to run again the whole simulation.
However, in that case, make sure you delete the directory `post_process/time`, if it exists, before running again the `post` script (otherwise the post processing script might think that their is no need to run again).

Finally the script `clean` completely cleans the simulation (without changing the parameters) if you want to completely start over the compilation configuration, the simulation and the post processing. It may be necessary if the directory of the case moved or changed name.

## Next tutorial

That's the end of this first tutorial. 
In the next, you'll learn how to create customize your flows and particles.
