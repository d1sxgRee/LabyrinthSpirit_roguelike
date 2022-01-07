#include "engine.h"
#include <stdlib.h>
#include "level.h"

#define LEVEL_COUNT 1

typedef struct Engine{
  Level* levels[LEVEL_COUNT];
  Character* hero1;
}Engine;

Engine *engine_init(){
  Engine *engine = scm_gc_malloc(sizeof(Engine), "engine");
  engine->levels[0] = level_init();
  engine->hero1 = character_init();
  return engine;
}

void engine_destroy(Engine *engine){
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

void engine_register_types(){
  scm_register_coords();
  scm_register_character();
  return;
}
    
