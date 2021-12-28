#include "interface.h"
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>

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
  InitWindow(800, 600, "LABIRINTH SPIRIT");
  
  while(!WindowShouldClose()){
    switch(interface->state){
      
    case MAIN_MENU:
      if(IsKeyPressed(KEY_ENTER)){
        interface->state = GAMEPLAY;
      }
      break;
    case GAMEPLAY:
      if(IsKeyPressed(KEY_ENTER)){
        interface->state = MAIN_MENU;
      }
      break;
    default:
      assert(0);
    }
    
    BeginDrawing();
    switch(interface->state){
    case MAIN_MENU:
      ClearBackground(RAYWHITE);
      break;
    case GAMEPLAY:
      ClearBackground(BLACK);
      break;
    default:
      assert(0);
    }
    EndDrawing();
  }
  
  CloseWindow();
  return;
}
