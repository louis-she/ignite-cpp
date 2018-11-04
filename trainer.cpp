#include "trainer.h"

int MainProcess() {
  TestModel model{nullptr};
  Trainer trainer(5, model, new TextLogger("./log.txt"));

  trainer.registerCallback(sample_callback);
  trainer.registerCallback(sample_callback);
  trainer.registerCallback(sample_callback);
  trainer.registerCallback(sample_callback);
  trainer.run();

  return 0;
};

int main() {
  pid_t pid1 = fork();
  int status;
  if (pid1 != 0) {
    waitpid(pid1, &status, 0);
  } else {
    pid_t pid2 = fork();
    if (pid2 != 0) {
      exit(0);
    } else {
      MainProcess();
    }
  }

  return 0;
}