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
  Vector2 text_log_pos;
  int open_stats;
  int open_stuff;
  int open_backpack;
}Interface;

Interface *interface_init(){
  Interface *interface;
  interface = malloc(sizeof(Interface));
  interface->state = MAIN_MENU;
  interface->closer = 0;
  interface->text_log_pos = (Vector2) {0, 0};
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
  /* Character Portraits */
  GuiButton((Rectangle) {0, 0, 100, 150}, "CH1");
  GuiButton((Rectangle) {0, 150, 100, 150}, "CH2");
  GuiButton((Rectangle) {0, 300, 100, 150}, "CH3");

  if(GuiButton((Rectangle) {0, 450, 75, 75}, "STATS")){
    interface->open_stats = (interface->open_stats + 1) % 2;
  }
  if(GuiButton((Rectangle) {75, 450, 75, 75}, "STUFF")){
    interface->open_stuff = (interface->open_stuff + 1) % 2;
  }
  if(GuiButton((Rectangle) {150, 450, 75, 75}, "BACKPACK")){
    interface->open_backpack = (interface->open_backpack + 1) % 2;
  }
  GuiButton((Rectangle) {0, 525, 75, 75}, "SPELLS");
  GuiButton((Rectangle) {75, 525, 75, 75}, "MAP");
  GuiButton((Rectangle) {150, 525, 75, 75}, "SPIRIT");

  GuiButton((Rectangle) {550, 400, 50, 50}, "Q1");
  GuiButton((Rectangle) {600, 400, 50, 50}, "Q2");
  GuiButton((Rectangle) {650, 400, 50, 50}, "Q3");
  GuiButton((Rectangle) {700, 400, 50, 50}, "Q4");
  GuiButton((Rectangle) {750, 400, 50, 50}, "Q5");

  GuiScrollPanel((Rectangle) {225, 450, 575, 150}, (Rectangle) {0, 0, 555, 450}, &(interface->text_log_pos));

  if(interface->open_stats){
    if(GuiWindowBox((Rectangle) {102, 2, 246, 222}, "CHARACTER STATS")){
      interface->open_stats = 0;
    }
  }
  if(interface->open_stuff){
    if(GuiWindowBox((Rectangle) {102, 226, 246, 222}, "EQUIPMENT")){
      interface->open_stuff = 0;
    }
  }
  if(interface->open_backpack){
    if(GuiWindowBox((Rectangle) {552, 2, 246, 396}, "BACKPACK")){
      interface->open_backpack = 0;
    }
  }
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
