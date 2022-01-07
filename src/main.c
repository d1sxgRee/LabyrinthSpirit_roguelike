#include <stdio.h>
#include <libguile.h>
#include "interface.h"
#include "engine.h"
#include "character.h"
#include "position.h"

int main(){
  scm_init_guile();
  scm_register_coords();
  scm_register_character();
  Interface *interface = interface_init();
  interface_run(interface);
  interface_destroy(interface);
  return 0;
}
