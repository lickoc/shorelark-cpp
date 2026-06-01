#pragma once

#include "layer.hpp"
#include <cstddef>
#include <random>
#include <vector>

namespace neural_network {

    struct LayerTopology {
        std::size_t neurons;
    };

    class Network {
        private:
            std::vector<Layer> layers;

        public:
            Network(const std::vector<Layer> layers_): layers(layers_) {}
            std::vector<float> propagate(const std::vector<float>& inputs) const;
            Network random(const std::vector<LayerTopology>& neurons_per_layer, std::mt19937& rng);
    };
}
