#pragma once

#include "raylib.h"
#include <array>
#include "config.h"

class Wall
{
private:
    std::array<Vector2, config::brickCount> positions_;
    Rectangle rect_;

public:
    Wall(Rectangle rect);
    void Draw(const Texture& texture) const;
};