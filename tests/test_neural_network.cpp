#include <gtest/gtest.h>
#include <random>
#include "subprojects/neural-network/include/neuron.hpp"

using namespace neural_network;

class NeuronTest : public ::testing::Test {
    protected:
        void SetUp() override {
            rng.seed(42); // 固定种子
        }

        std::mt19937 rng{42};
};

// 测试：相同种子，产生相同权重
TEST_F(NeuronTest, SameSeedProduceSame) {
    auto neuron = Neuron::random(5, rng);
    
}