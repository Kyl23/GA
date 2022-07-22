#ifndef GENE_ALGO
#define GENE_ALGO

#include "./tool.hpp"
#include "./core.hpp"

template <typename T, bool (*cmp)(const T &, const T &)>
class DarwinEnv
{
private:
    gtool::Heap<T, cmp> env;

    gtool::Heap<T, cmp> &(*selection)(gtool::Heap<T, cmp> &ENV);

    std::vector<T> &(*mutation)(gtool::Heap<T, cmp> &ENV);

    std::vector<T> &(*crossover)(gtool::Heap<T, cmp> &ENV);

    void concatEnv(std::vector<T> &mutationBuffer, std::vector<T> &crossoverBuffer)
    {
        env += mutationBuffer;
        env += crossoverBuffer;
    }

public:
    explicit DarwinEnv(const gtool::Heap<T, cmp> &ENV)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        env = ENV;
    }

    gtool::Heap<T, cmp> history;

    void setSelectFunc(gtool::Heap<T, cmp> &(*selectionFunc)(gtool::Heap<T, cmp> &ENV))
    {
        selection = selectionFunc;
    }

    void setMutationFunc(std::vector<T> &(*mutationFunc)(gtool::Heap<T, cmp> &ENV))
    {
        mutation = mutationFunc;
    }

    void setCrossoverFunc(std::vector<T> &(*crossoverFunc)(gtool::Heap<T, cmp> &ENV))
    {
        crossover = crossoverFunc;
    }

    void simulate(long long generation, long long familySize)
    {
        while (generation--)
        {
            if (env.size() > familySize)
                env = selection(env);
            // restructure heap here

            std::vector<T> mutationBuffer = mutation(env);   // nowait
            std::vector<T> crossoverBuffer = crossover(env); // nowait

            concatEnv(mutationBuffer, crossoverBuffer);
            // wait here
            // concat all the response from mutate and crossover
            history.insert(env.getRoot());
            gtool::log("remaining epoch: " + std::to_string(generation), "best solution: " + std::to_string(history[0].cost));
        }
    }
};

#endif
