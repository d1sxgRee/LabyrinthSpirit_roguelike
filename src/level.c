#include "level.h"
#include <assert.h>

#define LEVEL_SIZE_X 25
#define LEVEL_SIZE_Y 25

static SCM level_type;

typedef struct Level{
  SCM creatures;
  int map[LEVEL_SIZE_Y][LEVEL_SIZE_X];
}Level;

Level *level_init(){
  Level *level = scm_gc_malloc(sizeof(Level), "level");
  level->creatures = scm_list_n(SCM_UNDEFINED);
  for(int i = 0; i < LEVEL_SIZE_Y; i++){
    for(int j = 0; j < LEVEL_SIZE_X; j++){
      level->map[i][j] = 0;
    }
  }
  scm_call_1(scm_variable_ref(scm_c_lookup("generate-level")), scm_make_foreign_object_1(level_type, level));
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
    break;
  case GO_W:
    c.x --;
    break;
  case GO_S:
    c.y ++;
    break;
  case GO_E:
    c.x ++;
    break;
  case WAIT:
    break;
  default:
    assert(0);
  }
  if(c.y >= 0 && c.x >= 0 && c.y < LEVEL_SIZE_Y && c.x < LEVEL_SIZE_X && level->map[c.y][c.x] == 0){
    character_set_coords(character, c);
  }
  return;
}

void level_get_fov(Level *level, Character *c, View *view){
  Coords coords = character_get_coords(c);
  for(int i = 0; i < VIEW_SIZE; i++){
    for(int j = 0; j < VIEW_SIZE; j++){
      int x = coords.x - (VIEW_SIZE - 1) / 2 + i;
      int y = coords.y - (VIEW_SIZE - 1) / 2 + j;
      if(x >= 0 && x < LEVEL_SIZE_X && y >= 0 && y < LEVEL_SIZE_Y){
        view->fov[j][i] = level->map[y][x];
      }
      else{
        view->fov[j][i] = 1;
      }
    }
  }
  return;
}

void level_do_step(Level *level){
  for(SCM l = level->creatures; l != SCM_EOL; l = scm_list_tail(l, scm_from_int(1))){
    scm_assert_foreign_object_type(scm_get_character_type(), scm_list_ref(l, scm_from_int(0)));
    Character *c = scm_foreign_object_ref(scm_list_ref(l, scm_from_int(0)), 0);
    level_execute_command(level, c);
  }
  return;
}

SCM scm_level_get_cell(SCM level, SCM coords){
  scm_assert_foreign_object_type(scm_get_level_type(), level);
  scm_assert_foreign_object_type(scm_get_coords_type(), coords);
  Level *lvl = scm_foreign_object_ref(level, 0);
  Coords c = *((Coords*) scm_foreign_object_ref(coords, 0));
  return scm_from_int(lvl->map[c.y][c.x]);
}

SCM scm_level_set_cell_x(SCM level, SCM coords, SCM value){
  scm_assert_foreign_object_type(scm_get_level_type(), level);
  scm_assert_foreign_object_type(scm_get_coords_type(), coords);
  assert(scm_is_integer(value));
  Level *lvl = scm_foreign_object_ref(level, 0);
  Coords c = *((Coords*) scm_foreign_object_ref(coords, 0));
  int val = scm_to_int(value);
  lvl->map[c.y][c.x] = val;
  return SCM_EOL;
}

void scm_register_level(){
  level_type = scm_make_foreign_object_type(scm_from_utf8_symbol("level"),
                                            scm_list_1(scm_from_utf8_symbol("data")),
                                            NULL);
  scm_c_define_gsubr("level-get-cell", 2, 0, 0, (scm_t_subr) scm_level_get_cell);
  scm_c_define_gsubr("level-set-cell!", 3, 0, 0, (scm_t_subr) scm_level_set_cell_x);
  return;
}

SCM scm_get_level_type(){
  assert(level_type);
  return level_type;
}
