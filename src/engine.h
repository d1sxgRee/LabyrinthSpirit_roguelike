#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "command.h"
#include "view.h"

typedef struct Engine Engine;

Engine *engine_init();
void engine_destroy(Engine *engine);
void engine_execute_command(Engine *engine, Command command, View *view);
void engine_register_types();

#endif /* __ENGINE_H__ */
