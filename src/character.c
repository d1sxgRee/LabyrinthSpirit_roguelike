#include "character.h"
#include <assert.h>

static SCM character_type;

typedef struct Character{
  Coords coords;
  Command command;
}Character;

Character *character_init(){
  Character *character = scm_gc_malloc(sizeof(Character), "character");
  character->coords = (Coords) {0, 0};
  character->command = WAIT;
  return character;
}

void character_set_command(Character *character, Command command){
  character->command = command;
  return;
}

Command character_get_command(Character *character){
  return character->command;
}

void character_set_coords(Character *character, Coords coords){
  character->coords = coords;
  return;
}

Coords character_get_coords(Character *character){
  return character->coords;
}

void scm_register_character(){
  character_type = scm_make_foreign_object_type(scm_from_utf8_symbol("character"),
                                             scm_list_1(scm_from_utf8_symbol("data")),
                                             NULL);
  return;
}

SCM scm_get_character_type(){
  assert(character_type);
  return character_type;
}
