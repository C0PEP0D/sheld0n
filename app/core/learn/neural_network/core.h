#ifndef C0P_CORE_LEARN_NEURAL_NETWORK_CORE_H
#define C0P_CORE_LEARN_NEURAL_NETWORK_CORE_H
#pragma once

// std includs
#include <iostream>
// app includes
#include "param/learn/neural_network/parameters.h"
// lib includes
#include "l0ad/ascii/double.h"

namespace c0p {

	struct NeuralNetwork {

		inline static typename NeuralNetworkParameters::tDevice device;

		inline static auto rng = rlt::random::default_engine(NeuralNetworkParameters::tDevice::SPEC::RANDOM(), EnvParameters::randomSeed);
		inline static typename NeuralNetworkParameters::tNnType nn;

		using tInput = typename rlt::Matrix<rlt::matrix::Specification<tScalar, unsigned int, NeuralNetworkParameters::BatchSize, NeuralNetworkParameters::InputDim, false>>;
		using tOutput = typename rlt::Matrix<rlt::matrix::Specification<tScalar, unsigned int, NeuralNetworkParameters::BatchSize, NeuralNetworkParameters::OutputDim, false>>;

		static void init() {
			// memory init
			std::cout << "INFO : Initializing Neural Network..." << std::endl;
			rlt::malloc(device, nn); // this is never freed because it is needed until the end of the simulation
			std::cout << "INFO : Done." << std::endl;
			// load
			load();
		}

		static tOutput evaluate(const tInput& input) {
			// declare
			typename NeuralNetworkParameters::tNnType::Buffer<false> buffer;
			tOutput output;
			// evaluate
			rlt::evaluate(device, nn, input, output, buffer, rng);
			// output
			return output;
		}

		static void load() {
			std::cout << "INFO: Loading Neural Network..." << std::endl;
			// create directory if necessary
			if(std::filesystem::exists("param/learn/neural_network/data")) {
				// input layer
				l0ad::ascii::loadDouble("param/learn/neural_network/data/input_weights.txt", nn.input_layer.weights.parameters._data, nn.input_layer.INPUT_DIM * nn.input_layer.OUTPUT_DIM);
				l0ad::ascii::loadDouble("param/learn/neural_network/data/input_biases.txt", nn.input_layer.biases.parameters._data, nn.input_layer.OUTPUT_DIM);
				// hidden layers
				l0ad::ascii::loadDouble("param/learn/neural_network/data/hidden_weights.txt", nn.hidden_layers->weights.parameters._data, nn.hidden_layers->INPUT_DIM * nn.hidden_layers->OUTPUT_DIM);
				l0ad::ascii::loadDouble("param/learn/neural_network/data/hidden_biases.txt", nn.hidden_layers->biases.parameters._data, nn.hidden_layers->OUTPUT_DIM);
				// output layer
				l0ad::ascii::loadDouble("param/learn/neural_network/data/output_weights.txt", nn.output_layer.weights.parameters._data, nn.output_layer.INPUT_DIM * nn.output_layer.OUTPUT_DIM);
				l0ad::ascii::loadDouble("param/learn/neural_network/data/output_biases.txt", nn.output_layer.biases.parameters._data, nn.output_layer.OUTPUT_DIM);
			} else {
				std::cout << "WARNING: NO NEURAL NETWORK DATA TO BE LOADED !" << std::endl;
			}
			// info
			std::cout << "INFO: Done..." << std::endl;
		}
	};

}

#endif
