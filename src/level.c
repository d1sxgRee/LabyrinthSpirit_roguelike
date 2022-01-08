#include "level.h"
#include <assert.h>

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

void level_execute_command(Level *level, Character *character){
  Coords c = character_get_coords(character);
  switch(character_get_command(character)){
  case GO_N:
    c.y --;
    character_set_coords(character, c);
    break;
  case GO_W:
    c.x --;
    character_set_coords(character, c);
    break;
  case GO_S:
    c.y ++;
    character_set_coords(character, c);
    break;
  case GO_E:
    c.x ++;
    character_set_coords(character, c);
    break;
  case WAIT:
    break;
  default:
    assert(0);
  }
  return;
}

void level_do_step(Level *level, View *view){
  for(SCM l = level->creatures; l != SCM_EOL; l = scm_list_tail(l, scm_from_int(1))){
    scm_assert_foreign_object_type(scm_get_character_type(), scm_list_ref(l, scm_from_int(0)));
    Character *c = scm_foreign_object_ref(scm_list_ref(l, scm_from_int(0)), 0);
    level_execute_command(level, c);
  }
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
