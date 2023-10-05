#include "Food.h"

Food::Food(Rectangle rect) : rect_ { rect }, position_ { 0.0f, 0.0f } 
{
}

void Food::Draw(const Texture& texture) const
{
    DrawTextureRec(texture, rect_, position_, WHITE);
}

void Food::SetPosition(Vector2 position)
{
    position_ = position;
}
