#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "command.h"
#include "position.h"

typedef struct Character Character;

void character_set_command(Character *character, Command command);
Command character_get_command(Character *character);
void character_set_coords(Character *character, Coords coords);
Coords character_get_coords(Character *character);

#endif /* __CHARACTER_H__ */
