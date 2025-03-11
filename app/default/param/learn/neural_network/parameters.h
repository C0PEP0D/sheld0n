#ifndef C0P_PARAM_LEARN_NEURAL_NETWORK_PARAMETERS_H
#define C0P_PARAM_LEARN_NEURAL_NETWORK_PARAMETERS_H
#pragma once

#include <rl_tools/operations/cpu.h>
#include <rl_tools/nn/layers/dense/operations_cpu.h>
#include <rl_tools/nn_models/mlp/operations_generic.h>

namespace rlt = rl_tools;

namespace c0p {

// Run simulation parameters
struct NeuralNetworkParameters {
	using tDevice = rlt::devices::DefaultCPU;
	
	// // batch size is different to 1 when one wants to control a batch of agents using the same neural network (not supported yet)
	constexpr static unsigned int BatchSize = 1;
	// // definition of the neural network
	constexpr static unsigned int InputDim = DIM + DIM * DIM;
	constexpr static unsigned int OutputDim = DIM;
	constexpr static unsigned int HiddenDim = 32;
	constexpr static unsigned int NumLayers = 3; // total number of layers (including input and output)
	
	constexpr static auto activationFunction = rlt::nn::activation_functions::RELU;
	constexpr static auto outputActivationFunction = rlt::nn::activation_functions::RELU;
	
	using tNnConfig = rlt::nn_models::mlp::Configuration<double, unsigned int, OutputDim, NumLayers, HiddenDim, activationFunction, outputActivationFunction>;
	
	using tCapability = rlt::nn::capability::Forward<>;
	using tInputShape = rlt::tensor::Shape<unsigned int, BatchSize, InputDim>;
	
	using tNnType = rlt::nn_models::mlp::NeuralNetwork<tNnConfig, tCapability, tInputShape>;
};

}

#endif
