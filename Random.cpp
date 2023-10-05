#include "Random.h"

Random::Random(int min, int max) 
    :   min_ { min }, max_ { max }, generator_ { device_() }, distribution_ { min, max } 
{
}

int Random::Generate() 
{ 
    return distribution_(generator_); 
} 

void Random::ChangeRange(int min, int max) 
{ 
    distribution_.param(std::uniform_int_distribution<>::param_type { min, max }); 
    min_ = min;
    max_ = max;
}