#ifndef GENE_CORE_CROSSOVER_FULL
#define GENE_CORE_CROSSOVER_FULL

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    std::vector<T> &fullCrossover(gtool::Heap<T, cmp> &env, float crossoverRate, gtool::Random *rdm, T &(*operate)(T &, T &))
    {
        std::vector<T> *newChromo = new std::vector<T>;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < crossoverRate)
            {
                long long wifeIndex = rdm->randInt(env.size());
                newChromo->push_back(operate(env[i], env[wifeIndex]));
            }
        }

        return *newChromo;
    }
}

#endif
