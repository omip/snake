#pragma once

#include "raylib.h"
#include <vector>
#include "Direction.h"
#include "Food.h"

class Snake
{
private:
    std::vector<Vector2> positions_;
    Rectangle headRect_;
    Rectangle tailRect_;
    Direction direction_;
    int speed_;
    bool hasNewDirection_;

public: 
    Snake(Rectangle headRect, Rectangle tailRect);
    void Draw(const Texture& texture) const;
    void Update();
    void SetDirection(const Direction& direction);
    int GetSpeed() const { return speed_; };
    Direction GetDirection() const { return direction_; };
    bool HasNewDirection() const { return hasNewDirection_; };
    Vector2 GetHeadPosition() const { return positions_.at(0); };
    std::vector<Vector2> GetPositions() const { return positions_; };
    Vector2 ConvertDirectionToVector(const Direction& direction) const;
    bool HasCollided() const;
    bool GotFood(const Food& food) const;
    void Grow();
    void SetInitialState();
    void Reset();
    void SpeedUp();
    int GetFoodCount() const; 
};