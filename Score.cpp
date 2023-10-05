#include "Score.h"
#include "config.h"

using config::margin;
using config::frameHeight;

Score::Score() : total_ { 0 }, size_ { 32 }, color_ { 222, 94, 117, 255 } 
{
}

void Score::Draw() const
{
    float x = margin - 1;
    float y = margin - 2 - frameHeight * 2;
    DrawText(TextFormat("%i", total_), x, y, size_, color_);
}

void Score::Update()
{
    total_ += 5;
}

void Score::Reset()
{
    total_ = 0;
} 


