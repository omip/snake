#pragma once

#include "raylib.h"

class Food
{
private:
    Rectangle rect_;
    Vector2 position_;

public:
    Food(Rectangle rect);
    void Draw(const Texture& texture) const;
    Vector2 GetPosition() const { return position_; };
    void SetPosition(Vector2 position);
};