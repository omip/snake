#include "raylib.h"
#include "config.h"
#include "Game.h"
#include <chrono>
#include <thread>

using config::screenWidth;
using config::screenHeight;
using config::title;
using config::FPS;

int main()
{
    InitWindow(screenWidth, screenHeight, title);

    InitAudioDevice();
    
    Game game;

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        if (game.IsOver())
        {
            game.Reset();
            std::this_thread::sleep_for(std::chrono::seconds { 2 });
        }   
        else 
        {
            game.Update();
        }

        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        game.Draw();

        EndDrawing();
    }  

    game.Unload();

    CloseAudioDevice();

    CloseWindow();

    return 0;
}
