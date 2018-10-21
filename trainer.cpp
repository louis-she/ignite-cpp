#include "trainer.h"
#include "callback.h"


int main() {

  Trainer t(5);
  t.register_callback(sample_callback);
  t.run();

  return 0;
}