#ifndef __ENGINE_H__
#define __ENGINE_H__

#define VIEW_SIZE 13

typedef struct Engine Engine;

typedef struct View{
  int fov [VIEW_SIZE][VIEW_SIZE];
} View;

typedef enum Command{
  GO_N,
  GO_W,
  GO_S,
  GO_E,
  WAIT
} Command;

Engine *engine_init();
void engine_destroy(Engine *engine);
void engine_execute_command(Engine *engine, Command command, View *view);

#endif /* __ENGINE_H__ */
