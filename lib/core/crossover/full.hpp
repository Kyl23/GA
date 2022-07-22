#ifndef GENE_CORE_CROSSOVER_FULL
#define GENE_CORE_CROSSOVER_FULL

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    std::vector<T> &fullCrossover(gtool::Heap<T, cmp> &env, float crossoverRate, gtool::Random *rdm)
    {
        std::vector<T> *newChromo = new std::vector<T>;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < crossoverRate)
            {
                long long wifeIndex = rdm->randInt(env.size());
                T temp = env[i];
                for (long long j = 0; j < env[wifeIndex].size(); j++)
                {
                    if (rdm->randProb() < 0.5f)
                    {
                        temp[j] = env[wifeIndex][j];
                    }
                }
                newChromo->push_back(temp);
            }
        }

        return *newChromo;
    }
}

#endif
