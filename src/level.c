#include "level.h"

typedef struct Level{
  SCM creatures;
}Level;

Level *level_init(){
  Level *level = scm_gc_malloc(sizeof(Level), "level");
  level->creatures = scm_list_n(SCM_UNDEFINED);
  return level;
}

void level_destroy(Level *level){
  level->creatures = scm_list_n(SCM_UNDEFINED);
  return;
}

void level_add_character(Level *level, Character *character){
  SCM creature = scm_make_foreign_object_1(scm_get_character_type(), character);
  level->creatures = scm_append(scm_list_2(level->creatures,
                                           scm_list_1(creature)));
  return;
}

void level_do_step(Level *level){
  return;
}
