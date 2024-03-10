/**
 * This C++ program creates a window with a moving text and circle based on keyboard input.
 * 
 * @return The main function is returning an integer value of 0.
 */
#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

/* The code snippet `struct Vel { int x; int y; } speed;` is defining a structure named `Vel` that
contains two integer variables `x` and `y`. */
struct Vel
{
    int x;
    int y;
}speed;

int main()
{
    /* The lines `speed.x = 10;` and `speed.y = 10;` are initializing the values of the `x` and `y`
    members of the `speed` struct to 10 each. This means that the initial speed of the moving circle
    in the program is set to 10 pixels per frame in both the horizontal (x) and vertical (y)
    directions. */
    speed.x = 10;
    speed.y = 10;
    int vectorotate = 1;
    int width = 800;
    int height = 540;
    Vector2 PositionOnScreen = {(float)width/2,(float)height/2};
    
    int radiant = 50;

    InitWindow(width,height,"Window");
    SetTargetFPS(60);

    char* const text = "Congrats you are new here";

    while (!WindowShouldClose())
    {
        /* The code snippet you provided is checking for keyboard input to move the text and circle on
        the window. Here's what each line does: */
        if (IsKeyDown(KEY_RIGHT)) PositionOnScreen.x += speed.x;
        if (IsKeyDown(KEY_LEFT)) PositionOnScreen.x -= speed.x;
        if (IsKeyDown(KEY_UP)) PositionOnScreen.y -= speed.y;
        if (IsKeyDown(KEY_DOWN)) PositionOnScreen.y += speed.y;

        /* The lines `PositionOnScreen.x += speed.x;` and `PositionOnScreen.y += speed.y;` are updating
        the position of the text and circle on the window by adding the values of `speed.x` and
        `speed.y` to the current x and y coordinates of `PositionOnScreen` respectively. */
        PositionOnScreen.x += speed.x;
        PositionOnScreen.y += speed.y;
        
        /* These `if` statements are responsible for handling the boundary conditions of the moving
        circle on the window. Here's a breakdown of what each `if` statement does: */
        if (PositionOnScreen.x-radiant < 0.0){PositionOnScreen.x = radiant;speed.x = -1*speed.x;vectorotate = -1*vectorotate;}
        if(PositionOnScreen.x+radiant >=width){PositionOnScreen.x=width-radiant;speed.x = -1*speed.x;vectorotate = -1*vectorotate;}
        if (PositionOnScreen.y-radiant < 0.0){PositionOnScreen.y = radiant;speed.y = -1*speed.y;vectorotate = -1*vectorotate;}
        if(PositionOnScreen.y+radiant >=height){PositionOnScreen.y = height-radiant;speed.y = -1*speed.y;vectorotate = -1*vectorotate;}
        
        Vector2 Endline = {(PositionOnScreen.x),(PositionOnScreen.y)};
        Endline.x += 100*vectorotate;
        Endline.y += 100*vectorotate;
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLineV(PositionOnScreen,Endline,GRAY);
            DrawCircleV(PositionOnScreen,radiant,LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}