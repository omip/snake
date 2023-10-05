#include "Wall.h"
#include "config.h"
#include <algorithm>

using config::margin;
using config::marginAndWall;
using config::groundWidthInFrames;
using config::groundHeightInFrames;
using config::frameWidth;
using config::frameHeight;
using config::screenHeight;
using config::screenWidth;
using config::brickCount;

Wall::Wall(Rectangle rect) : rect_ { rect }
{
    auto x = margin;
    auto y = margin;

    int i = 0;
    int j = 1;
    Vector2* position = nullptr;

    for (; i < groundWidthInFrames * 2; i++)
    {
        position = &positions_.at(i);

        if (i < groundWidthInFrames)
        {
            position->x = margin + frameWidth * (i + 1);
            position->y = margin;
        }
        else
        {
            position->x = margin + frameWidth * j;
            position->y = screenHeight - marginAndWall;
            j++;
        }
    }

    j = 0;
    int k = 0;
    for (; i < brickCount; i++)
    {
        position = &positions_.at(i);

        if (j < groundHeightInFrames + 2)
        {
            position->x = margin;
            position->y = margin + frameHeight * j;
        }
        else
        {
            position->x = screenWidth - marginAndWall;
            position->y = margin + frameHeight * k;
            k++;
        }
        j++;
    }
}

void Wall::Draw(const Texture& texture) const
{
    for (const auto& position : positions_)
    {
        DrawTextureRec(texture, rect_, position, WHITE);
    }
}