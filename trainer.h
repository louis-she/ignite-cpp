#include <cstddef>
#include <vector>
#include <functional>
#include <torch/torch.h>
#include <iostream>
#include <chrono>

#include "callback.h"
#include "model.h"
#include "logger.h"

using namespace std;

class Trainer {

  public:
    Trainer(size_t persistStrideIn, torch::nn::ModuleHolder<TestModelImpl> model, BaseLogger *l, string model_path="",
        size_t max_epochs=-1);
    void run();
    void registerCallback(function<void(int)> callback);

  private:
    string model_path;
    vector<function<void(int)>> callbacks;
    torch::nn::ModuleHolder<TestModelImpl> model;
    BaseLogger *logger_;
    size_t max_epochs_;
    size_t persist_stride_;
    size_t current_epochs_;
};

Trainer::Trainer(
    size_t persist_stride,
    torch::nn::ModuleHolder<TestModelImpl> model,
    BaseLogger *logger,
    string model_path="",
    size_t max_epochs=-1) {

  logger_ = logger;
  persist_stride_ = persist_stride;
  model = model;
  current_epochs_ = 0;
  if (!model_path.empty()) {
    cout<<"model Path is empty"<<endl;
    torch::load(model, model_path);
  }
};

void Trainer::registerCallback(function<void(int)> callback) {
  callbacks.emplace_back(callback);
};

void Trainer::run() {
  logger_->info("Start to train!");
  while (true) {
    logger_->info("running epochs ", current_epochs_);
  }
  // auto start = chrono::system_clock::now();
  // for (size_t i = 0; i <= 100000; i++) {
  //   torch::Tensor x = model->forward(torch::rand({10}));
  //   x.backward();
  // }
  // auto end = chrono::system_clock::now();
  // chrono::duration<double> diff = end - start;
  // cout<<diff.count()<<endl;
};

