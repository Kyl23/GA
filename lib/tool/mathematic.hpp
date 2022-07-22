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
            return (int)(randProb() * INT32_MAX);
        }

        int randInt(int upper_bound)
        {
            if (!upper_bound)
                upper_bound = 1;
            return (int)(randProb() * INT32_MAX) % upper_bound;
        }

        int randInt(int lower_bound, int upper_bound)
        {
            return (int)(randProb() * INT32_MAX) % (upper_bound - lower_bound) + lower_bound;
        }

        float randProb()
        {
            return (float)rand() / RAND_MAX;
        }
    };
}

#endif
