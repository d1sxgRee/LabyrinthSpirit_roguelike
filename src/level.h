#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "character.h"

typedef struct Level Level;

Level *level_init();
void level_destroy(Level *level);
void level_add_character(Level *level, Character *character);
void level_do_step(Level *level);

#endif /* __LEVEL_H__ */