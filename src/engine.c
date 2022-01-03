#include "engine.h"
#include <stdlib.h>

typedef struct Engine{
} Engine;

Engine *engine_init(){
  return malloc(sizeof(Engine));
}

void engine_destroy(Engine *engine){
  free(engine);
  return;
}

void engine_execute_command(Engine *engine, Command command, View *view){
  for(int i = 0; i < VIEW_SIZE; i++){
    for(int j = 0; j < VIEW_SIZE; j++){
      if(i == 0 || i == VIEW_SIZE - 1 || j == 0 || j == VIEW_SIZE - 1){
        view->fov[i][j] = 1;
      }
      else{
        view->fov[i][j] = 0;
      }
    }
  }
  return;
}
