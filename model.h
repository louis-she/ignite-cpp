#include <torch/torch.h>

class TestModelImpl : public torch::nn::Cloneable<TestModelImpl> {
 public:
  explicit TestModelImpl() {
    fc1 = register_module("fc1", torch::nn::Linear(10, 10));
    fc2 = register_module("fc2", torch::nn::Linear(10, 10));
    fc3 = register_module("fc3", torch::nn::Linear(10, 1));
  }

  torch::Tensor forward(torch::Tensor x) {
    x = fc1->forward(x);
    x = fc2->forward(x);
    return x;
  }

  torch::nn::Linear fc1{nullptr};
  torch::nn::Linear fc2{nullptr};
  torch::nn::Linear fc3{nullptr};

  void reset() {}
};

TORCH_MODULE(TestModel);
