#pragma once

#include "layer.hpp"
#include <vector>

namespace neural_network {
    class Network {
        private:
            std::vector<Layer> layers;

        public:
            std::vector<float> propagate(std::vector<float>& inputs);
    };
}
