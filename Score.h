#pragma once

#include "raylib.h"

class Score
{
private:
    int total_;
    int size_;
    Color color_;

public:
    Score();
    void Draw() const;
    void Update();
    void Reset();
};