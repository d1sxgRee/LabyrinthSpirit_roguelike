#include "interface.h"
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION
#include "lavanda.h"

typedef enum{
  MAIN_MENU,
  GAMEPLAY
}InterfaceState;

typedef struct Interface{
  InterfaceState state;
  int closer;
}Interface;

Interface *interface_init(){
  Interface *interface;
  interface = malloc(sizeof(Interface));
  interface->state = MAIN_MENU;
  interface->closer = 0;
  return interface;
}

void interface_destroy(Interface *interface){
  free(interface);
  return;
}

void mainmenu_draw(Interface *interface, Texture2D *logo){
  ClearBackground(RAYWHITE);
  DrawTexture(*logo, 0, 0, RAYWHITE);
  if(GuiButton((Rectangle) {300, 400, 200, 50}, "NEW GAME")){
    interface->state = GAMEPLAY;
  }
  if(GuiButton((Rectangle) {300, 460, 200, 50}, "CONTINUE")){
    interface->state = GAMEPLAY;
  }
  if(GuiButton((Rectangle) {300, 520, 200, 50}, "EXIT")){
    interface->closer = 1;
  }
}

void gameplay_draw(Interface *interface){
  if(IsKeyPressed(KEY_ESCAPE)){
    interface->state = MAIN_MENU;
  }
  ClearBackground(BLACK);
}

void interface_run(Interface *interface){
  InitWindow(800, 600, "LABYRINTH SPIRIT");
  SetExitKey(KEY_NULL);

  GuiLoadStyleLavanda();

  Texture2D logo = LoadTexture("resources/textures/labyrinthspirit.png");

  while(!interface->closer){

    BeginDrawing();
    switch(interface->state){
    case MAIN_MENU:
      mainmenu_draw(interface, &logo);
      break;
    case GAMEPLAY:
      gameplay_draw(interface);
      break;
    default:
      assert(0);
    }
    EndDrawing();
    interface->closer |= WindowShouldClose();
  }

  UnloadTexture(logo);
  
  CloseWindow();
  return;
}
