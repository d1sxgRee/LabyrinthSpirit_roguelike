#include <stdio.h>
#include <libguile.h>
#include "interface.h"
#include "engine.h"

int main(){
  scm_init_guile();
  engine_register_types();
  Engine *engine = engine_init();
  Interface *interface = interface_init(engine);
  interface_run(interface);
  interface_destroy(interface);
  engine_destroy(engine);
  return 0;
}
