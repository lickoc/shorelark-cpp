#include "include/neuron.hpp"
#include "fmt/format.h"
#include <algorithm>
#include <cstddef>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>
#include <fmt/core.h>

using namespace neural_network;

float Neuron::propagate(const std::vector<float>& inputs) const {
    if (inputs.size() != weights.size()) {
        throw std::runtime_error(
            fmt::format(
                "got {} inputs, but {} inputs were expected",
                inputs.size(), weights.size()
            )
        );
    }

    float output = std::inner_product(
        inputs.begin(), inputs.end(),
        weights.begin(),
        bias
    );

    return std::max(output, 0.0f);
}

Neuron Neuron::random(size_t input_size, std::mt19937& rng) {
    // 均匀分布 [min, max]
    std::uniform_real_distribution<float> real_dist(-1.0f, 1.0f);

    float bias = real_dist(rng);

    std::vector<float> weights;
    weights.reserve(input_size);
    std::generate(weights.begin(), weights.end(), [&] {
        return real_dist(rng);
    });

    return Neuron(bias, weights);
}