#ifndef GENE_CORE_MUTATION_ONE_POINT
#define GENE_CORE_MUTATION_ONE_POINT

#include "../../tool.hpp"

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    gtool::ArrayList<T> onePointMutation(gtool::Heap<T, cmp> &env, float mutationRate, gtool::Random *rdm, T (*operate)(const T &))
    {
        gtool::ArrayList<T> newChromo;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < mutationRate)
            {
                newChromo.push(operate(env[i]));
            }
        }

        return newChromo;
    }
}

#endif
