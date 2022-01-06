#include "character.h"

typedef struct Character{
  Coords coords;
  Command command;
}Character;

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
