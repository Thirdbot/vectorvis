#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;
/**
 * This C++ program creates a window with a moving text and circle based on keyboard input.
 * 
 * @return The main function is returning an integer value of 0.
 */
int main()
{
    int width = 800;
    int height = 540;
    Vector2 PositionOnScreen = {(float)width/2,(float)height/2};
    int radiant = 50;

    InitWindow(width,height,"Window");
    SetTargetFPS(60);

    char* const text = "Congrats you are new here";
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) PositionOnScreen.x += 10.0f;
        if (IsKeyDown(KEY_LEFT)) PositionOnScreen.x -= 10.0f;
        if (IsKeyDown(KEY_UP)) PositionOnScreen.y -= 10.0f;
        if (IsKeyDown(KEY_DOWN)) PositionOnScreen.y += 10.0f;


        /* These `if` statements are ensuring that the circle drawn on the window stays within the
        boundaries of the window. */
        if (PositionOnScreen.x-radiant < 0.0){PositionOnScreen.x = radiant;}
        if(PositionOnScreen.x+radiant >=width){PositionOnScreen.x=width-radiant;}
        if (PositionOnScreen.y-radiant < 0.0){PositionOnScreen.y = radiant;}
        if(PositionOnScreen.y+radiant >=height){PositionOnScreen.y = height-radiant;}

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(PositionOnScreen,radiant,LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}