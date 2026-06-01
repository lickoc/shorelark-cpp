#include "../include/network.hpp"
#include "fmt/format.h"
#include <random>
#include <stdexcept>
#include <vector>

using namespace neural_network;

// 通用折叠操作（支持任意二元操作）
// template<typename BinaryOp, typename... Args>
// auto fold(BinaryOp op, Args... args) {
//     return (op(args, ...));
// }

std::vector<float> Network::propagate(const std::vector<float>& inputs) const {
    std::vector<float> current = inputs;
    for (const auto& layer : layers) {
        current = layer.propagate(current);
    }
    return current;
}

Network Network::random(const std::vector<LayerTopology>& layers, std::mt19937& rng) {
    if (layers.size() <= 1) {
        throw std::invalid_argument(
            fmt::format(
                "expect more than 1 layer"
            )
        );
    }

    std::vector<Layer> built_layers;

    for (size_t i = 0; i < layers.size() - 1 ; ++i) {
        auto input_size = layers[i].neurons;
        auto output_size = layers[i + 1].neurons;

        built_layers.push_back(Layer::random(input_size, output_size, rng));
    }

    return Network(built_layers);
}