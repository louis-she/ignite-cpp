#include <cstddef>
#include <vector>
#include <functional>


class Trainer {

  public:
    Trainer(size_t persistStrideIn);
    void run();
    void register_callback(std::function<void(int)> callback);

  private:
    size_t persistStride;
    std::vector<std::function<void(int)>> callbacks;
};

Trainer::Trainer(size_t persistStrideIn) {
  persistStride = persistStrideIn;
}

void Trainer::run() {
  for (auto callback : callbacks) {
    callback(10);
  }
}

