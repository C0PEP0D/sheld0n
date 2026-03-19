# Reinforcment Learning

The code includes a very basic interface for reinforcement learning applications based on [rl-tools](https://github.com/rl-tools/rl-tools). 
This interface is at a proof of concept state but can already by used to solve simple navigation problems.
This tutorial covers running and evaluating the performance of an agent that tries to solve the upward swimming problem introduced in the [Surfing on Turbulence](https://journals.aps.org/prl/abstract/10.1103/PhysRevLett.129.064502) paper.

## Table of Contents

- [Learning case](#learning-case)
- [Evaluation case](#evaluation-case)

## Learning case

First let's generate a new "learning" case.
```
Move to the cases directory.
Execute the generate_new_case script, name it case_04a and select the "tgv_rl" example case.
("rl" stands for Reinforcement Learning)
Move to the case_04a directory.
```

The agent parameters and behavior is defined in the file `param/solutions/rl_simmer/parameters.h`.
The neural network parameters are defined in `param/learn/neural_network/parameters.h`.
Learning parameters are defined in `param/learn/parameters.h`.

Refer to [rl-tools](https://github.com/rl-tools/rl-tools) for more details.

```
Execute the learn script to start the learning process.
```
This may take a long time.
Feel free to edit parameters to reduce computation time.

## Evaluation case

Once the learning has ended, you may evaluate the performance of your agents.
To do so, you will have to create a new case.
```
Move to the cases directory.
Execute the generate_new_case script, name it case_04b and select the "tgv_nn" example case.
("nn" stands for Neural Network)
Move to the case_04b directory.
```

The neural network parameters are defined in `param/learn/neural_network/parameters.h` these should **exactly** match those of the `case_04a`.
You then have to copy the reult of the learning process (that occured in the preevious case).
```
Copy the directory case_04a/param/learn/neural_network/data to case_04b/param/learn/neural_network/data.
```

Then you juste have to run the simulation.
```
Execute the run script.
```
