#ifndef GENE_CORE_SELECTION_RANDOM
#define GENE_CORE_SELECTION_RANDOM

#include "../../tool.hpp"

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    gtool::Heap<T, cmp> &randomSelection(gtool::Heap<T, cmp> &env, float selectionRate, gtool::Random *rdm)
    {
        gtool::Heap<T, cmp> *newEnv = new gtool::Heap<T, cmp>;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < selectionRate)
            {
                newEnv->insert(env[i]);
            }
        }

        return *newEnv;
    }
}

#endif
