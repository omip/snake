#include "Game.h"
#include "config.h"

using config::FPS;
using config::frameWidth;
using config::frameHeight;
using config::groundHeightInFrames;
using config::groundWidthInFrames;
using config::speedUpdateFrequency;
using config::texturePath;
using config::targetSoundPath;
using config::lossSoundPath;
using config::frameWidth;
using config::frameHeight;

Game::Game() 
    :   texture_ { LoadTexture(texturePath) },
        ground_ { {0.0f, 0.0f, frameWidth, frameHeight}, {frameWidth, 0.0f, frameWidth, frameHeight} },
        snake_ { {frameWidth * 3, 0.0f, frameWidth, frameHeight}, {frameWidth * 7, 0.0f, frameWidth, frameHeight} },
        wall_ { {frameWidth * 2, 0.0f, frameWidth, frameHeight} },
        food_ { {frameWidth * 8, 0.0f, frameWidth, frameHeight} },
        target_ { LoadSound(targetSoundPath) },
        loss_ { LoadSound(lossSoundPath) },
        frameCounter_ { 0 }, 
        isOver_ { false }, 
        random_ { 0, groundHeightInFrames * groundWidthInFrames - 3 }
{
    food_.SetPosition(GenerateFreePosition());
}

void Game::Draw() const
{   
    ground_.Draw(texture_);
    food_.Draw(texture_);
    snake_.Draw(texture_);
    wall_.Draw(texture_);
    score_.Draw();
}

void Game::Update()
{
    frameCounter_++;

    if (!snake_.HasNewDirection())
    {
        auto currentDirection = snake_.GetDirection();

        if (IsKeyDown(KEY_UP)) 
        {
            if (currentDirection != Direction::down)
            {
                snake_.SetDirection(Direction::up);
            }
        }
        else if (IsKeyDown(KEY_RIGHT)) 
        {
            if (currentDirection != Direction::left)
            {
                snake_.SetDirection(Direction::right);
            }
        }
        else if (IsKeyDown(KEY_DOWN)) 
        {
            if (currentDirection != Direction::up)
            {
                snake_.SetDirection(Direction::down);
            }
        }
        else if (IsKeyDown(KEY_LEFT)) 
        {
            if (currentDirection != Direction::right)
            {
                snake_.SetDirection(Direction::left);
            }
        }    
    }

    if (frameCounter_ % (FPS / snake_.GetSpeed()) == 0)
    {
        if(snake_.HasCollided())
        {
            isOver_ = true;
            PlaySound(loss_);
        }

        if (snake_.GotFood(food_))
        {
            PlaySound(target_);

            snake_.Grow();
            score_.Update();
            random_.ChangeRange(random_.GetMin(), random_.GetMax() - 1);
            food_.SetPosition(GenerateFreePosition());

            int foodCount = snake_.GetFoodCount();
            if (foodCount != 0 && foodCount % speedUpdateFrequency == 0)
            {
                snake_.SpeedUp();
            }
        }

        if (!isOver_)
        {
            snake_.Update();  
        }
    }
   
    frameCounter_ = frameCounter_ % FPS;
}

std::vector<Vector2> Game::GetFreePositions() const 
{
    const auto snakePositions = snake_.GetPositions();
    const auto groundPositions = ground_.GetPositions();
    std::vector<Vector2> freePositions;
    bool isFree = true;

    freePositions.reserve(groundHeightInFrames * groundWidthInFrames - snakePositions.size());

    for (const auto& rowOfGroundPositions : groundPositions)
    {
        for (const auto& groundPosition : rowOfGroundPositions)
        {
            for (const auto& snakePosition : snakePositions)
            {
                if (snakePosition.x == groundPosition.x && snakePosition.y == groundPosition.y)
                {   
                    isFree = false;
                    break;
                }
            }

            if (isFree)
            {
                freePositions.push_back(groundPosition);
            }

            isFree = true;
        }
    }

    return freePositions;
}

Vector2 Game::GenerateFreePosition() 
{
    auto freePositions = GetFreePositions();
    return freePositions.at(random_.Generate());
}

void Game::Unload() const
{
    UnloadTexture(texture_);
    UnloadSound(target_);
    UnloadSound(loss_);
}

void Game::Reset()
{
    random_.ChangeRange(random_.GetMin(), groundHeightInFrames * groundWidthInFrames - 3);
    score_.Reset();
    snake_.Reset();
    food_.SetPosition(GenerateFreePosition());

    isOver_ = false;
}