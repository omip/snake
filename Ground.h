#pragma once

#include "raylib.h"
#include <array>
#include "config.h"

class Ground
{
private:
    std::array<std::array<Vector2, config::GWIF>, config::GHIF> positions_;
    Rectangle rectOne_;
    Rectangle rectTwo_;
public:
    Ground(Rectangle areaRectOne, Rectangle areaRectTwo);
    void Draw(const Texture& texture) const;
    std::array<std::array<Vector2, config::GWIF>, config::GHIF> GetPositions() const { return positions_; };
};