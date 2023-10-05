#include <random>

class Random
{
private:
    std::random_device device_;
    std::mt19937 generator_;
    std::uniform_int_distribution<> distribution_;
    int min_;
    int max_;

public:
    Random(int min, int max);
    int Generate();
    void ChangeRange(int min, int max);
    int GetMin() const { return min_; };
    int GetMax() const { return max_; };
};
