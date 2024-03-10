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

//it state is moving at random direction(x,y) when it see pray it take control of direction
class Bot
{
    public:
    
    string bname;
    int width = 800;
    int height = 540;

    struct Vel
    {
        int x=10;
        int y=10;
    }speed;

    int radiant = 50;
    int vectorotatex = 1;
    int vectorotatey = 1;
    //random in screen
    float posxrandom = rand()%width+1;
    float posyrandom = rand()%height+1;

    Vector2 PositionOnScreen = {posxrandom,posyrandom};
    Vector2 Lastine;
    void setname(string name)
    {
        bname = name;
    }
    void setpos(int x,int y)
    {
        posxrandom = x;
        posyrandom = y;
    }
    void setradiant(int rad)
    {
        radiant = rad;
    }
    void setspeed(int x ,int y )
    {
        speed.x = x;
        speed.y = y;
    }
    void draw()
    {  
        cout << "Name:" << bname << "\tPosX:" << PositionOnScreen.x << "\tPosY:" << PositionOnScreen.y << endl;
        BeginDrawing();
            ClearBackground(BLACK);
            DrawLineV(PositionOnScreen,Lastine,RED);
            DrawCircleV(PositionOnScreen,radiant,WHITE);
        EndDrawing();
    }
    void process()
    {
        /* The code snippet you provided is checking for keyboard input to move the text and circle on
        the window. Here's what each line does: */
        if (IsKeyDown(KEY_RIGHT)) 
        {
            PositionOnScreen.x += speed.x*vectorotatex;
        }
        if (IsKeyDown(KEY_LEFT)) 
        {
            PositionOnScreen.x -= speed.x*vectorotatex;
        }
        
        if (IsKeyDown(KEY_UP)) 
        {
            PositionOnScreen.y -= speed.y*vectorotatey;
        }
        if (IsKeyDown(KEY_DOWN)) 
        {   
            PositionOnScreen.y += speed.y*vectorotatey;
        }
        
        
        /* The lines `PositionOnScreen.x += speed.x;` and `PositionOnScreen.y += speed.y;` are updating
        the position of the text and circle on the window by adding the values of `speed.x` and
        `speed.y` to the current x and y coordinates of `PositionOnScreen` respectively. */

        PositionOnScreen.x += speed.x;
        PositionOnScreen.y += speed.y;
        
        /* This block of code is responsible for handling the boundary conditions of the moving circle
        on the window. Let's break down what each `if` statement is doing: */
        
        if (PositionOnScreen.x-radiant < 0.0){PositionOnScreen.x = radiant;speed.x = -1*speed.x;vectorotatex = -1*vectorotatex;}
        if(PositionOnScreen.x+radiant >=width){PositionOnScreen.x=width-radiant;speed.x = -1*speed.x;vectorotatex = -1*vectorotatex;}
        if (PositionOnScreen.y-radiant < 0.0){PositionOnScreen.y = radiant;speed.y = -1*speed.y;vectorotatey = -1*vectorotatey;}
        if(PositionOnScreen.y+radiant >=height){PositionOnScreen.y = height-radiant;speed.y = -1*speed.y;vectorotatey = -1*vectorotatey;}

        /* The code snippet `Vector2 Endline = {(PositionOnScreen.x),(PositionOnScreen.y)};` is
        creating a new `Vector2` variable named `Endline` and initializing it with the x and y
        coordinates of the `PositionOnScreen` vector. */
        Vector2 Endline = {(PositionOnScreen.x),(PositionOnScreen.y)};

        Endline.x += 100*vectorotatex;
        Endline.y += 100*vectorotatey;

        Lastine = Endline;
        }
    //a
    
};

int main()
{
    /* The lines `speed.x = 10;` and `speed.y = 10;` are initializing the values of the `x` and `y`
    members of the `speed` struct to 10 each. This means that the initial speed of the moving circle
    in the program is set to 10 pixels per frame in both the horizontal (x) and vertical (y)
    directions. */
    
    
    int width = 800;
    int height = 540;
    InitWindow(width,height,"Window");
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);

    Bot bot1;
    Bot bot2;
    bot1.setname("Steve");
    bot1.setradiant(60);
    bot1.setspeed(5,5);

    bot2.setname("Alex");
    bot2.setspeed(20,20);

    while (!WindowShouldClose())
    {
        bot1.process();
        bot2.process();
        bot1.draw();
        bot2.draw();
    }
    CloseWindow();
    

    
    
    
    return 0;
}