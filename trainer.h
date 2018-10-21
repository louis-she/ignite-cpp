#include <cstddef>
#include <vector>
#include <functional>


class Trainer {

  public:
    Trainer(size_t persistStrideIn);
    void run();
    void registerCallback(std::function<void(int)> callback);

  private:
    size_t persistStride;
    std::vector<std::function<void(int)>> callbacks;
};

Trainer::Trainer(size_t persistStrideIn) {
  persistStride = persistStrideIn;
};

void Trainer::registerCallback(std::function<void(int)> callback) {
  callbacks.emplace_back(callback);
};

void Trainer::run() {
  for (auto callback : callbacks) {
    callback(10);
  }
};

