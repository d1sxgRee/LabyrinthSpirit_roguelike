#include <stdio.h>
#include <libguile.h>
#include "interface.h"
#include "engine.h"

int main(){
  scm_init_guile();
  engine_register_types();
  Interface *interface = interface_init();
  interface_run(interface);
  interface_destroy(interface);
  return 0;
}
