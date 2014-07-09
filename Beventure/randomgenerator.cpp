#include "randomgenerator.h"

RandomGenerator::RandomGenerator() :
    a (16807l),
    m (2147483647l),
    q (127773l),
    r (2836l)
{
    seed = 1l;
}

int& RandomGenerator::getSeed() const
{
    return const_cast<int&>(seed);
}

void RandomGenerator::setSeed(const int& seed)
{
    if (seed > 1 && seed < m)
        this->seed = seed;
}

double RandomGenerator::next()
{
    seed = a * (seed % q) - r * (seed / q);
    if (seed < 0)
        seed += m;
    return ((double)seed / (double)m);
}
