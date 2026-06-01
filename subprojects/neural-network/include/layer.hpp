#include "neuron.hpp"
#include <cstddef>
#include <random>
#include <vector>

namespace neural_network {
    class Layer {
        private:
            std::vector<Neuron> neurons;     
        
        public:
            Layer(const std::vector<Neuron> neurons_): neurons(neurons_) {}
            std::vector<float> propagate(const std::vector<float>& inputs) const;
            Layer random(size_t input_size, size_t output_size, std::mt19937& rng);
    };
}