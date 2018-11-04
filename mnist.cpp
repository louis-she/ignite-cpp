#include "mnist.h"

Mnist::Mnist(std::string datasetDir) {
  datasetDir = datasetDir;
}

torch::Tensor Mnist::load() {
  return at::rand(at::IntList({28, 28}));
}