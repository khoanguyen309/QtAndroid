#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QDateTime>

class RandomGenerator
{
    public:
        RandomGenerator();

        int& getSeed() const;

        void setSeed(const int&);

        double next();

    private:
        int seed;
        const int a;
        const int m;
        const int q;
        const int r;
};

#endif // RANDOMGENERATOR_H
