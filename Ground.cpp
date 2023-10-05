#include "Ground.h"
#include "config.h"

using config::frameWidth;
using config::frameHeight;
using config::marginAndWall;

Ground::Ground(Rectangle rectOne, Rectangle rectTwo) : rectOne_ { rectOne }, rectTwo_ { rectTwo }
{
    float x = marginAndWall;
    float y = marginAndWall;

    for (auto& rowOfPositions : positions_)
    {
        for (auto& position : rowOfPositions)
        {
            position.x = x;
            position.y = y;
            x += frameWidth;
        }
        x = marginAndWall;
        y += frameHeight;
    }
}

void Ground::Draw(const Texture& texture) const
{
    const auto* rectOnePtr = &rectOne_;
    const auto* rectTwoPtr = &rectTwo_; 

    int i = 0;
    for (auto& rowOfPositions : positions_)
    {
        for (auto& position : rowOfPositions)
        {
            DrawTextureRec(texture, i % 2 ? *rectOnePtr : *rectTwoPtr, position, WHITE);
            i++;
        }
        std::swap(rectOnePtr, rectTwoPtr);
        i = 0;
    }
}

