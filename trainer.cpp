#include "trainer.h"
#include "callback.h"


int main() {

  Trainer t(5);
  t.registerCallback(sample_callback);
  t.registerCallback(sample_callback);
  t.registerCallback(sample_callback);
  t.registerCallback(sample_callback);
  t.run();

  return 0;
}