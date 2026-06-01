#include "include/layer.hpp"
#include "network.hpp"
#include <cstddef>
#include <random>
#include <vector>

using namespace neural_network;

std::vector<float> Layer::propagate(const std::vector<float>& inputs) const {
    std::vector<float> outputs;

    for (const auto& neuron : neurons) {
        float output = neuron.propagate(inputs);
        outputs.push_back(output);
    }

    return outputs;
}

Layer Layer::random(size_t input_size, size_t output_size, std::mt19937& rng) {
    std::vector<Neuron> neurons;

    for (size_t i = 0; i < output_size; ++i) {
        neurons.push_back(Neuron::random(input_size, rng));
    }

    return Layer(neurons);
}