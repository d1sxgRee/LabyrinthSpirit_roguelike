#include "engine.h"
#include <stdlib.h>
#include "level.h"

#define LEVEL_COUNT 1

typedef struct Engine{
  Level* levels[LEVEL_COUNT];
  size_t cur_level;
  Character* hero1;
}Engine;

void engine_load_scripts(){
  scm_c_primitive_load("resources/scripts/level_gen.scm");
  return;
}

Engine *engine_init(){
  engine_load_scripts();
  Engine *engine = scm_gc_malloc(sizeof(Engine), "engine");
  engine->levels[0] = level_init();
  engine->cur_level = 0;
  engine->hero1 = character_init();
  level_add_character(engine->levels[engine->cur_level], engine->hero1);
  return engine;
}

void engine_destroy(Engine *engine){
  return;
}

void engine_execute_command(Engine *engine, Command command, View *view){
  character_set_command(engine->hero1, command);
  level_do_step(engine->levels[engine->cur_level]);
  level_get_fov(engine->levels[engine->cur_level], engine->hero1, view);
  return;
}

void engine_register_types(){
  scm_register_coords();
  scm_register_character();
  scm_register_level();
  return;
}

