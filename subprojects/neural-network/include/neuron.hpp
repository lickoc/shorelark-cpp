#include <cstddef>
#include <random>
#include <vector>

namespace neural_network {
    class Neuron {
        private:
            float bias;
            std::vector<float> weights;

        public:
            Neuron(float bias_, std::vector<float> weights_): bias(bias_), weights(weights_) {};
            float propagate(const std::vector<float>& inputs) const;
            Neuron random(size_t input_size, std::mt19937& rng);

    };
}