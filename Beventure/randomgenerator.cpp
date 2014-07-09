#include "randomgenerator.h"

RandomGenerator::RandomGenerator() :
    a (16807),
    m (2147483647),
    q (127773),
    r (2836)
{
    seed = QDateTime::currentMSecsSinceEpoch();
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
