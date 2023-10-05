#include "Snake.h"
#include "raylib.h"
#include "config.h"

using config::frameWidth;
using config::frameHeight;
using config::marginAndWall;
using config::middleX;
using config::middleY;
using config::speed;
using config::acceleration;
using config::screenWidth;
using config::screenHeight;

Snake::Snake(Rectangle headRect, Rectangle tailRect) 
    :   headRect_ { headRect }, tailRect_ { tailRect }, direction_ { Direction::up }, 
        speed_ { speed }, hasNewDirection_ { false }
{
    SetInitialState();
}

void Snake::SetInitialState()
{
    Vector2 headPosition{middleX, middleY};
    Vector2 tailPosition{middleX, middleY + frameHeight};

    positions_.push_back(headPosition);
    positions_.push_back(tailPosition);
}

void Snake::Draw(const Texture& texture) const
{
    DrawTextureRec(texture, headRect_, positions_.at(0), WHITE);

    for (auto i = 1; i < positions_.size(); i++)
    {
        DrawTextureRec(texture, tailRect_, positions_.at(i), WHITE);
    }
}

void Snake::Update()
{
    const auto [x, y] = ConvertDirectionToVector(direction_);

    auto& headPosition = positions_.at(0);
    auto oneBeforePosition = headPosition;

    for (auto i = 1; i < positions_.size(); i++)
    {
        std::swap(oneBeforePosition, positions_.at(i));
    }

    headPosition.x += x * frameWidth;
    headPosition.y += y * frameHeight;

    hasNewDirection_ = false;

    switch (direction_)
    {
        case Direction::up:
            headRect_.x = frameWidth * 3;
            break;
        case Direction::right:
            headRect_.x = frameWidth * 4;
            break;
        case Direction::down:
            headRect_.x = frameWidth * 5;
            break;
        case Direction::left:
            headRect_.x = frameWidth * 6;
            break;
    }
}

void Snake::SetDirection(const Direction& direction)
{
    direction_ = direction;
    hasNewDirection_ = true;
}

bool Snake::HasCollided() const
{
    auto headPosition = positions_.at(0);
    auto [x, y] = ConvertDirectionToVector(direction_);
    bool collided = false;

    headPosition.x += x * frameWidth;
    headPosition.y += y * frameHeight;

    if (headPosition.y < marginAndWall)
    {
        collided = true;
    }
    else if (headPosition.x > screenWidth - marginAndWall - frameWidth)
    {
        collided = true;
    }
    else if (headPosition.y > screenHeight - marginAndWall - frameHeight)
    {
        collided = true;
    }
    else if (headPosition.x < marginAndWall)
    {
        collided = true;
    }

    if (!collided)
    {
        const Vector2* position = nullptr;

        for (auto i = 3; i < positions_.size(); i++)
        {
            position = &positions_.at(i);
            
            if (headPosition.x == position->x && headPosition.y == position->y)
            {
                collided = true;
                break;
            }
        }
    }
    
    return collided;
}

bool Snake::GotFood(const Food& food) const
{
    const auto& headPosition = GetHeadPosition();
    const auto& foodPosition = food.GetPosition();

    return headPosition.x == foodPosition.x && headPosition.y == foodPosition.y;
}

void Snake::Grow()
{
    positions_.push_back({0.0f, 0.0f});
}
 
void Snake::Reset()
{
    speed_ = speed;
    positions_.clear();
    SetInitialState();
    direction_ = Direction::up;
}

void Snake::SpeedUp()
{
    speed_ += acceleration;
}

int Snake::GetFoodCount() const
{
    return positions_.size() - 2;
}

Vector2 Snake::ConvertDirectionToVector(const Direction& direction) const
{
    Vector2 directionVector;

    switch (direction)
    {
        case Direction::up:
            directionVector.x = 0;
            directionVector.y = -1;
            break;

        case Direction::right:
            directionVector.x = 1;
            directionVector.y = 0;
            break;
        
        case Direction::down:
            directionVector.x = 0;
            directionVector.y = 1;
            break;

        case Direction::left:
            directionVector.x = -1;
            directionVector.y = 0;
            break;

        default:
            directionVector.x = -1;
            directionVector.y = -1;
    }

    return directionVector;
}