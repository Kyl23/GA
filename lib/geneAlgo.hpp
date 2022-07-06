#ifndef GENE_ALGO
#define GENE_ALGO

#include "./tool.hpp"
#include "./core.hpp"

template <typename T, bool (*cmp)(const T &, const T &)>
class DarwinEnv
{
private:
    gtool::Heap<T, cmp> env;

    gtool::Heap<T, cmp> (*selection)(gtool::Heap<T, cmp> &ENV);

    gtool::ArrayList<T> (*mutation)(gtool::Heap<T, cmp> &ENV);

    gtool::ArrayList<T> (*crossover)(gtool::Heap<T, cmp> &ENV);

    void concatEnv(gtool::ArrayList<T> &mutationBuffer, gtool::ArrayList<T> &crossoverBuffer)
    {
        env += mutationBuffer;
        env += crossoverBuffer;
    }

public:
    explicit DarwinEnv(gtool::Heap<T, cmp> ENV)
    {
        env = ENV;
    }

    gtool::Heap<T, cmp> history;

    void setSelectFunc(gtool::Heap<T, cmp> (*selectionFunc)(gtool::Heap<T, cmp> &ENV))
    {
        selection = selectionFunc;
    }

    void setMutationFunc(gtool::ArrayList<T> (*mutationFunc)(gtool::Heap<T, cmp> &ENV))
    {
        mutation = mutationFunc;
    }

    void setCrossoverFunc(gtool::ArrayList<T> (*crossoverFunc)(gtool::Heap<T, cmp> &ENV))
    {
        crossover = crossoverFunc;
    }

    void simulate(long long generation)
    {
        while (generation--)
        {
            env = selection(env);
            // restructure heap here

            gtool::ArrayList<T> mutationBuffer = mutation(env);   // nowait
            gtool::ArrayList<T> crossoverBuffer = crossover(env); // nowait

            concatEnv(mutationBuffer, crossoverBuffer);
            // wait here
            // concat all the response from mutate and crossover
            history.insert(env.getRoot());
        }
    }
};

#endif
