#ifndef C0P_CORE_LEARN_CORE_H
#define C0P_CORE_LEARN_CORE_H
#pragma once

// std includs
#include <iostream>
// app includes
#include "param/learn/parameters.h"
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"

namespace c0p {

	struct Learn {

		inline static typename c0p::LearnParameters::tDevice device;
		inline static typename c0p::LearnParameters::tLoopState ls;

		static void init() {
			std::cout << "INFO : Initializing Learning Process..." << std::endl;
			rlt::malloc(device, ls);
			rlt::init(device, ls, EnvParameters::randomSeed);
			std::cout << "INFO : Done." << std::endl;
		}

		static void run() {
			std::cout << "INFO : Running Learning Process..." << std::endl;
			while(!rlt::step(device, ls)) {
				save();
			}
			std::cout << "INFO : Done." << std::endl;
		}

		static void save() {
			std::cout << "INFO: Saving neural network..." << std::endl;
			// create directory if necessary
			if(not std::filesystem::exists("param/learn/neural_network/data")) {
				std::filesystem::create_directory("param/learn/neural_network/data");
			}
			// input layer
			s0ve::saveDouble("param/learn/neural_network/data/input_weights.txt", ls.ppo.actor.next_module.content.input_layer.weights.parameters._data, ls.ppo.actor.next_module.content.input_layer.INPUT_DIM * ls.ppo.actor.next_module.content.input_layer.OUTPUT_DIM);
			s0ve::saveDouble("param/learn/neural_network/data/input_biases.txt", ls.ppo.actor.next_module.content.input_layer.biases.parameters._data, ls.ppo.actor.next_module.content.input_layer.OUTPUT_DIM);
			// hidden layers
			s0ve::saveDouble("param/learn/neural_network/data/hidden_weights.txt", ls.ppo.actor.next_module.content.hidden_layers->weights.parameters._data, ls.ppo.actor.next_module.content.hidden_layers->INPUT_DIM * ls.ppo.actor.next_module.content.hidden_layers->OUTPUT_DIM);
			s0ve::saveDouble("param/learn/neural_network/data/hidden_biases.txt", ls.ppo.actor.next_module.content.hidden_layers->biases.parameters._data, ls.ppo.actor.next_module.content.hidden_layers->OUTPUT_DIM);
			// output layer
			s0ve::saveDouble("param/learn/neural_network/data/output_weights.txt", ls.ppo.actor.next_module.content.output_layer.weights.parameters._data, ls.ppo.actor.next_module.content.output_layer.INPUT_DIM * ls.ppo.actor.next_module.content.output_layer.OUTPUT_DIM);
			s0ve::saveDouble("param/learn/neural_network/data/output_biases.txt", ls.ppo.actor.next_module.content.output_layer.biases.parameters._data, ls.ppo.actor.next_module.content.output_layer.OUTPUT_DIM);
			// info
			std::cout << "INFO: Done..." << std::endl;
		}
	};

}

#endif
