#pragma once

#include "raylib.h"
#include "Ground.h"
#include "Snake.h"
#include "Wall.h"
#include "Food.h"
#include "Score.h"
#include <vector>
#include "Random.h"

class Game
{
private:
    Texture texture_;
    Ground ground_;
    Snake snake_;
    Wall wall_;
    Food food_;
    Sound target_;
    Sound loss_;
    Score score_;
    int frameCounter_;
    bool isOver_;
    Random random_;
    std::vector<Vector2> GetFreePositions() const;
    Vector2 GenerateFreePosition();

public:
    Game();
    void Draw() const;
    void Update();
    void Unload() const;
    bool IsOver() const { return isOver_; };
    void Reset();
};
