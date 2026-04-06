#include <stdio.h>
#include <raylib.h>

int main(){
    InitWindow(1000,600,"test_raylib");
    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
