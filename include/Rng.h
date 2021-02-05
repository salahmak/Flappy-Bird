#ifndef RNG_H
#define RNG_H
#include <ctime>
#include <random>

// namespace GameWrapper
// {

// class Rng
// {
//   public:
//     static int generate(int min, int max)
//     {
//         std::random_device seed;

//         // initializing mt19937 with the generated seed
//         std::mt19937 rnd(seed());

//         // setting the PRNG distibution range
//         std::uniform_int_distribution<int> distribution(min, max);

//         int randomNum = distribution(rnd);

//         return randomNum;
//     }
// };

namespace GameWrapper
{
namespace Rng
{

int generate(int min, int max);


} // Rng

} // GameWrapper

#endif // RNG_H
