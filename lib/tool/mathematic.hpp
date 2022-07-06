#ifndef GENE_TOOL_MATHEMATIC
#define GENE_TOOL_MATHEMATIC

#include <cstdlib>

namespace gtool
{
    class Random
    {
    private:
        unsigned int seed;

    public:
        Random(int seed_ = 42)
        {
            seed = seed_;
        }

        int randInt()
        {
            return rand_r(&seed);
        }

        int randInt(int upper_bound)
        {
            if (!upper_bound)
                upper_bound = 1;
            return rand_r(&seed) % upper_bound;
        }

        int randInt(int lower_bound, int upper_bound)
        {
            return rand_r(&seed) % (upper_bound - lower_bound) + lower_bound;
        }

        float randProb()
        {
            return rand_r(&seed) / RAND_MAX;
        }
    };
}

#endif
