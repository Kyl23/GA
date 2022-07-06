#ifndef GENE_TOOL_FREE_STL_CONTAINER
#define GENE_TOOL_FREE_STL_CONTAINER

namespace gtool
{
    template <typename T>
    void freeContainer(T &i)
    {
        T temp;
        i.swap(temp);
    }
}

#endif
