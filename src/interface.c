#include "interface.h"
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

typedef enum{
  MAIN_MENU,
  GAMEPLAY
}InterfaceState;

typedef struct Interface{
  InterfaceState state;
}Interface;

Interface *interface_init(){
  Interface *interface;
  interface = malloc(sizeof(Interface));
  interface->state = MAIN_MENU;
  return interface;
}

void interface_destroy(Interface *interface){
  free(interface);
  return;
}

void interface_run(Interface *interface){
  InitWindow(800, 600, "LABYRINTH SPIRIT");
  SetExitKey(KEY_NULL);

  int closer = 0;

  while(!closer){

    BeginDrawing();
    switch(interface->state){
    case MAIN_MENU:
      ClearBackground(RAYWHITE);
      if(GuiButton((Rectangle) {300, 400, 200, 50}, "NEW GAME")){
        interface->state = GAMEPLAY;
      }
      if(GuiButton((Rectangle) {300, 460, 200, 50}, "CONTINUE")){
        interface->state = GAMEPLAY;
      }
      if(GuiButton((Rectangle) {300, 520, 200, 50}, "EXIT")){
        closer = 1;
      }
      break;
    case GAMEPLAY:
      if(IsKeyPressed(KEY_ESCAPE)){
        interface->state = MAIN_MENU;
      }
      ClearBackground(BLACK);
      break;
    default:
      assert(0);
    }
    EndDrawing();
    closer |= WindowShouldClose();
  }

  CloseWindow();
  return;
}
