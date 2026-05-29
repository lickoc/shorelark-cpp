#include "neuron.hpp"
#include <vector>

namespace neural_network {
    class Layer {
        private:

            std::vector<float> propagate(std::vector<float>& inputs);


            std::vector<Neuron> neurons;      
    };
}