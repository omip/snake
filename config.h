#pragma once

namespace config
{
    inline constexpr const char* title = "snake";
    inline constexpr const char* texturePath = "resources/texture.png";
    inline constexpr const char* targetSoundPath = "resources/target.mp3";
    inline constexpr const char* lossSoundPath = "resources/loss.mp3";
    inline constexpr int FPS = 60;
    inline constexpr int frameCount = 6;
    inline constexpr int frameWidth = 25;
    inline constexpr int frameHeight = 25;
    inline constexpr int frameSize = 25;
    inline constexpr int marginInFrames = 3;
    inline constexpr int margin = marginInFrames * frameSize;
    inline constexpr int groundWidthInFrames = 31;
    inline constexpr int groundHeightInFrames = 17; 
    inline constexpr int GWIF = groundWidthInFrames;
    inline constexpr int GHIF = groundHeightInFrames;
    inline constexpr int wallThickness = frameWidth;
    inline constexpr int marginAndWall = margin + wallThickness;
    inline constexpr int screenWidth = frameWidth * GWIF + marginAndWall * 2;
    inline constexpr int screenHeight = frameHeight * GHIF + marginAndWall * 2;
    inline constexpr int screenWidthInFrames = screenWidth / frameWidth;
    inline constexpr int screenHeightInFrames = screenHeight / frameWidth;
    inline constexpr int brickCount = GWIF * 2 + GHIF * 2 + 4;
    inline constexpr int speed = 5;
    inline constexpr int acceleration = 1;
    inline constexpr int speedUpdateFrequency = 6;
    inline constexpr int middleX = marginAndWall + (GWIF - 1) * frameWidth / 2;
    inline constexpr int middleY = marginAndWall + (GHIF - 1) * frameHeight / 2;   
}


