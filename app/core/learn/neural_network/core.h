#ifndef C0P_CORE_LEARN_NEURAL_NETWORK_CORE_H
#define C0P_CORE_LEARN_NEURAL_NETWORK_CORE_H
#pragma once

// std includs
#include <iostream>
// app includes
#include "param/learn/neural_network/parameters.h"
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"

namespace c0p {

	struct NeuralNetwork {

		inline static typename NeuralNetworkParameters::tDevice device;
		inline static unsigned int seed = 0;

		inline static auto rng = rlt::random::default_engine(NeuralNetworkParameters::tDevice::SPEC::RANDOM(), seed);
		inline static typename NeuralNetworkParameters::tNnType nn;
		inline static typename NeuralNetworkParameters::tNnType::Buffer<> nnBuffer;

		inline static typename rlt::Matrix<rlt::matrix::Specification<tScalar, unsigned int, NeuralNetworkParameters::BatchSize, NeuralNetworkParameters::InputDim>> input;
		inline static typename rlt::Matrix<rlt::matrix::Specification<tScalar, unsigned int, NeuralNetworkParameters::BatchSize, NeuralNetworkParameters::OutputDim>> output;

		static void init() {
			// memory init
			std::cout << "INFO : Initializing Neural Network..." << std::endl;
			rlt::malloc(device, nn);
			rlt::malloc(device, nnBuffer);
			rlt::malloc(device, input);
			rlt::malloc(device, output);
			std::cout << "INFO : Done." << std::endl;
			// load
			load();
		}

		static double* evaluate() {
			// evaluate
			rlt::evaluate(device, nn, input, output, nnBuffer, rng);
			// output
			return output._data;
		}

		static void load() {
			std::cout << "INFO: Loading Neural Network..." << std::endl;
			// create directory if necessary
			if(std::filesystem::exists("learn_output")) {
				// input layer
				l0ad::ascii::loadDouble("learn_output/input_weights.txt", nn.input_layer.weights.parameters._data, nn.input_layer.INPUT_DIM * nn.input_layer.OUTPUT_DIM);
				l0ad::ascii::loadDouble("learn_output/input_biases.txt", nn.input_layer.biases.parameters._data, nn.input_layer.OUTPUT_DIM);
				// hidden layers
				l0ad::ascii::loadDouble("learn_output/hidden_weights.txt", nn.hidden_layers->weights.parameters._data, nn.hidden_layers->INPUT_DIM * nn.hidden_layers->OUTPUT_DIM);
				l0ad::ascii::loadDouble("learn_output/hidden_biases.txt", nn.hidden_layers->biases.parameters._data, nn.hidden_layers->OUTPUT_DIM);
				// output layer
				l0ad::ascii::loadDouble("learn_output/output_weights.txt", nn.output_layer.weights.parameters._data, nn.output_layer.INPUT_DIM * nn.output_layer.OUTPUT_DIM);
				l0ad::ascii::loadDouble("learn_output/output_biases.txt", nn.output_layer.biases.parameters._data, nn.output_layer.OUTPUT_DIM);
			}
			// info
			std::cout << "INFO: Done..." << std::endl;
		}
	};

}

#endif
