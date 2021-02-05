#include "Rng.h"

namespace GameWrapper
{
namespace Rng
{
int generate(int min, int max)
{
    std::random_device seed;

    // initializing mt19937 with the generated seed
    std::mt19937 rnd(std::time(nullptr));

    // setting the PRNG distibution range
    std::uniform_int_distribution<int> distribution(min, max);

    int randomNum = distribution(rnd);

    return randomNum;
}
}
}