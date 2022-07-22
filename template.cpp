#include <iostream>
#include <string>
#include "./lib/geneAlgo.hpp"

#define EPOCHS 3
#define FAMILY_SIZE 5

using namespace std;
using namespace gcore;
using namespace gtool;

// * here is prepare for the openMP library auto judgement

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_max_threads() 1
#define omp_get_num_threads() 0
#endif

// * end of auto judgement

Random *rdm;

/**
 * You should write your code in this area
 *
 * ~~~ area start ~~~
 */
#define GENE_TYPE float

struct Pkg
{
public:
    // decide your structure
    float cost;

    vector<GENE_TYPE> gene;

    Pkg()
    {
        gene = vector<GENE_TYPE>();
    }

    void setGeneLen(long long len)
    {
        gene.resize(len);
    }

    long long size()
    {
        return gene.size();
    }

    Pkg &operator=(const Pkg &pkg)
    {
        if (this == &pkg)
            return *this;
        cost = pkg.cost;
        gene = vector<GENE_TYPE>(pkg.gene);
        return *this;
    }

    GENE_TYPE &operator[](long long index)
    {
        return gene[index];
    }
};

bool cmp(const Pkg &a, const Pkg &b)
{
    // the comparator you wish
    return a.cost < b.cost;
}

Heap<Pkg, cmp> &selectionFunc(Heap<Pkg, cmp> &env)
{
    // you could add some function when doing the selection
    // the lib has provided some function, you may also write by yourself

    return randomSelection<Pkg, cmp>(env, 0.5f, rdm);
}

vector<Pkg> &mutationFunc(Heap<Pkg, cmp> &env)
{
    // you could add some function when doing the selection

    // the lib has provided some function, you may also write by yourself
    return onePointMutation<Pkg, cmp>(env, 0.5f, rdm,0,1);
}

vector<Pkg> &crossoverFunc(Heap<Pkg, cmp> &env)
{
    // you could add some function when doing the selection

    // the lib has provided some function, you may also write by yourself
    return fullCrossover<Pkg, cmp>(env, 0.5f, rdm);
}

Heap<Pkg, cmp> initialize()
{
    /** in this function you should initialize the with
     *  _______________________________
     *  | Heap <Structure,comparator> |
     *  |_____________________________|
     * and provide the type of template
     */
    Heap<Pkg, cmp> t;
    Pkg pkg;
    pkg.setGeneLen(2);
    pkg[0] = 1;
    pkg[1] = 0;
    pkg.cost = 1100;
    t.insert(pkg);
    return t;
}

/**
 * You should not change main function
 *
 */
int main()
{
    // auto judgement
    rdm = new Random[omp_get_max_threads()];
    for (int i = 0; i < omp_get_max_threads(); i++)
    {
        rdm[i] = Random(i);
    }
    // auto judgement end

    DarwinEnv<Pkg, cmp> darwinEnv(initialize());
    darwinEnv.setSelectFunc(selectionFunc);
    darwinEnv.setCrossoverFunc(crossoverFunc);
    darwinEnv.setMutationFunc(mutationFunc);

    darwinEnv.simulate(EPOCHS, FAMILY_SIZE);

    cout << darwinEnv.history[0].cost << endl;

    return 0;
}
