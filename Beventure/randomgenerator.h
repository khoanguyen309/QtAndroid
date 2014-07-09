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
        const long int a;
        const long int m;
        const long int q;
        const long int r;
};

#endif // RANDOMGENERATOR_H
