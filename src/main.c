#include <stdio.h>
#include <raylib.h>

int main(){
  InitWindow(800, 600, ":)");
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
