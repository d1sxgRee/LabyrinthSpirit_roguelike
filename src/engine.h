#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "command.h"

#define VIEW_SIZE 13

typedef struct Engine Engine;

typedef struct View{
  int fov [VIEW_SIZE][VIEW_SIZE];
} View;

Engine *engine_init();
void engine_destroy(Engine *engine);
void engine_execute_command(Engine *engine, Command command, View *view);

#endif /* __ENGINE_H__ */
