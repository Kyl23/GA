#ifndef GENE_CORE_MUTATION_ONE_POINT
#define GENE_CORE_MUTATION_ONE_POINT

#include "../../tool.hpp"

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    std::vector<T> &onePointMutation(gtool::Heap<T, cmp> &env, float mutationRate, gtool::Random *rdm, int mutate_lower_bound, int mutate_upper_bound)
    {
        std::vector<T> *newChromo = new std::vector<T>;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < mutationRate)
            {
                T temp;
                temp = env[i];
                temp[rdm->randInt(env[i].size())] = rdm->randInt(mutate_lower_bound, mutate_upper_bound);
                newChromo->push_back(temp);
            }
        }

        return *newChromo;
    }
}

#endif
