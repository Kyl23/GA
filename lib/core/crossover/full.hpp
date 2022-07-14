#ifndef GENE_CORE_CROSSOVER_FULL
#define GENE_CORE_CROSSOVER_FULL

namespace gcore
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    gtool::ArrayList<T> &fullCrossover(gtool::Heap<T, cmp> &env, float crossoverRate, gtool::Random *rdm, T &(*operate)(T &, T &))
    {
        gtool::ArrayList<T> *newChromo = new gtool::ArrayList<T>;

        for (long long i = 0; i < env.size(); i++)
        {
            if (rdm->randProb() < crossoverRate)
            {
                long long wifeIndex = rdm->randInt(env.size());
                newChromo->push(operate(env[i], env[wifeIndex]));
            }
        }

        return *newChromo;
    }
}

#endif
