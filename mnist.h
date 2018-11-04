#include <string>
#include <torch/torch.h>

class Mnist {
  public:
    Mnist(std::string datasetDir);
    torch::Tensor load();
  private:
    std::string datasetDir;
};
