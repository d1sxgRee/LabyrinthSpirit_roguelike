#include <stdio.h>
#include "interface.h"

int main(){
  Interface *interface = interface_init();
  interface_run(interface);
  interface_destroy(interface);
  return 0;
}
