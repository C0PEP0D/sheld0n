# Writing your own equations

Here you'll learn how to customize particles and flows to encode your own equations into the code.

## Table of Contents

- [Writing in C++](#writting-in-c++)
- [Custom particle equation](#custom-particle-equation)
- [Custom flow equation](#custom-flow-equation)
- [Next tutorial](#next-tutorial)

## Writing in C++

The following will teach you how to customize your own equations directly in **C++** rather
than in **Pyhton** to avoid its performance drop.

First of all, you will not have to bee an expert in **C++** to specify your own equations.
We will get through this together by analysing and replicating the same example as the 
previous **Python** tutorial provided.

When starting modifying the **C++** files, the risk is to generate compilation errors.
**C++** compilers tend to generate long and sometime overwhelming errors.
They have their own language which require some time to get into but 
once you get familiar with it, you find the compilation errors very descriptive.

So if you get a compilation error, make sure to read the output carefully from the beginning 
and you should be able to solve it. 
If not, feel free to **open an issue** or contact me if you need any help.

## Custom particle equation

First let's generate a new case to avoid breaking the first tutorial case.
Rather than generating a new case from scratch, let's just copy our first case.
```sh
$ cd cases
$ ls
case_00  generate_new_case
$ cp -r case_00 case_02
$ ls
case_00 case_02 generate_new_case
```

Let's move into it, clean entirely the simulation and create a new equation.
```sh
$ cd case_02
$ ./clean
$ cd param/solutions
$ ./create_new_equation custom_particles
$ cd custom_particles
```

As an exercise, let's try to create a particle that is both buoyant and inertial (the same as the previous tutorial).
The motion of such a particle would be described by the following equations
```math
\frac{d \vec{x}}{dt} = \vec{v}
```
```math
\frac{d \vec{v}}{dt} = \frac{ u \left ( \vec{x}, t \right ) + V_{\mathrm{buoyancy}} \vec{z} - \vec{v} }{\tau} \, \mathrm{.}
```

While this equation is not included in the choices available in the solver, `buoyant_particles` and `inertial_particles`
are both already available.
By merging together both behavior, we should be fine.

Let's first get the `parameters.h` for buoyant particles and save it to have access to it later.
```sh
$ ./choose buoyant_particles
$ cp parameters.h save_buoyant_parameters.h
```

Let's now start our new custom behavior from inertial particles.
```sh
$ ./choose inertial_particles
```

We can now open both file at the same time and try to merge the `save_buoyant_parameters.h` file into the `parameters.h` file.
Let us first copy paste the buoyancy parameters into our parameters.
```cpp
22	// ---------------- CUSTOM EQUATION PARAMETERS START
23	static const unsigned StateSize = 2 * DIM; // dimension of the state variable 
24	// feel free to add parameters if you need
25	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
26	static constexpr double ReactionTime = 1.0;
27	static constexpr float BuoyantVelocity = 0.5; // <--- ADDED
28	static constexpr std::array<double, DIM> BuoyancyDirection = {0.0, 1.0}; // <--- ADDED
29	// ---------------- CUSTOM EQUATION PARAMETERS END
```

Then we need to modify the definition of the temporal derivative of our state variables to match the previous equation.
To do so, let's first copy the line **38** of `save_buoyant_parameters.h` into our `parameters.h` file.
This line gives us access to the vertical in vector form.
```cpp
37			// ---------------- CUSTOM EQUATION START
38			// parameters <--- ADDED
39			const tView<const tSpaceVector> z(BuoyancyDirection.data()); // <--- ADDED
40			// input
41			const tView<const tSpaceVector> x(pState);
42			const tView<const tSpaceVector> v(pState + DIM);
43			// flow
44			const tSpaceVector u = Flow::getVelocity(x.data(), t);
45			// output
46			tView<tSpaceVector> dX(dState.data());
47			tView<tSpaceVector> dV(dState.data() + DIM);
48			dX = v;
49			dV = (u - v) / ReactionTime;
50			// ---------------- CUSTOM EQUATION END
```

Finally, we just have to change the line **49** to match our new equation.
```cpp
49			dV = (u + BuoyantVelocity * z - v) / ReactionTime;
```

Congrats ! You implemented your first custom equation into the solver.
The code should already be able to run and solve your equation,
but before moving on, let's try to edit both the `init` and the `post` function too.

Starting with the `init`, it might make more sense to initialize the velocity of particles to
their buoyant velocity.
```cpp
66		// ---------------- CUSTOM INIT START
67		// interpret BoxCenter and BoxSize as vectors
68		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
69		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
70		// loop over each member of the variable group
71		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
72			// get the state variable of the subIndex member of the group
73			double* pSubState = tVariable::state(pState, subIndex);
74			// parameters <--- ADDED
75			const tView<const tSpaceVector> z(BuoyancyDirection.data()); // <-- ADDED
76			// interpret subState as a tSpaceVector
77			tView<tSpaceVector> x(pSubState);
78			tView<tSpaceVector> v(pSubState + DIM);
79			// set the initial position of this member
80			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
81			v = z * BuoyantVelocity; // <--- EDITED
82		}
83		// ---------------- CUSTOM INIT END
```

Finally, in this context, it might be of interest to extract the flow velocity sampled
by the particles along their trajectories.
```cpp
91		// ---------------- CUSTOM INIT START
92		tSpaceVector xAverage = tSpaceVector::Zero();
93		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
94			const double* pSubState = tVariable::cState(pState, subIndex);
95			const tView<const tSpaceVector> x(pSubState);
96			const tView<const tSpaceVector> v(pSubState + DIM);
97			const tSpaceVector u = Flow::getVelocity(x.data(), t); // <--- ADDED
98			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_0"] = x[0];
99			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__pos_1"] = x[1];
100			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__vel_0"] = v[0];
101			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__vel_1"] = v[1];
102			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__u_0"] = u[0]; // <--- ADDED
103			output["custom_particles__index" + std::format("{:0>{}d}", subIndex, FormatNumber) + "__u_1"] = u[1]; // <--- ADDED
104			xAverage += x;
105		}
106		xAverage /= Number;
107		output["custom_particles__average_pos_0"] = xAverage[0];
108		output["custom_particles__average_pos_1"] = xAverage[1];
109		// ---------------- CUSTOM INIT END
```

Once everything is setup, we can run the simulation and the post processing.
```sh
$ cd ../../..
$ ./run
[...]
$ ./post
$ cd post_process
```

You can then add some further custom post processing if necessary (the same as the previous tutorial for instance).

## Custom flow equation

The flow can similarly by customized by editing the `param/flow/parameters.h` file.
Each function originally defined in this file must be provided analytically.

In the future, you should be able to also use local flow databases and JHTDB databases.

## Next tutorial

That's the end of this tutorial. 
In the next tutorial [03-parametric-study.md](03-parametric-study.md), 
you'll learn how to perform easily a parametric study through the example case of the **surfing strategy**.


