#ifndef GENE_TOOL_CONTAINER_HEAP
#define GENE_TOOL_CONTAINER_HEAP

#include <algorithm>
#include <string>
#include <vector>
namespace gtool
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    class Heap
    {
    private:
        std::vector<T> heap;
        long long top = 0;

        long long getParent(long long index)
        {
            return index / 2;
        }

        long long getLeftChild(long long index)
        {
            return index * 2;
        }

        long long getTop()
        {
            return top;
        }

        void bubbleDown(long long index)
        {
            if (index >= getTop())
                return;
            long long leftChildIndex = getLeftChild(index);

            long long newIndex = index;
            for (long long i = 0; i < 2; i++)
            {
                if (!cmp(heap[newIndex], heap[leftChildIndex + i]) && leftChildIndex + i <= getTop())
                {
                    newIndex = leftChildIndex + i;
                }
            }
            if (newIndex != index)
            {
                std::swap(heap[newIndex], heap[index]);
                bubbleDown(newIndex);
            }
        }

        void bubbleUp(long long index)
        {
            if (index == 1)
                return;
            long long parentIndex = getParent(index);
            if (cmp(heap[index], heap[parentIndex]))
            {
                std::swap(heap[index], heap[parentIndex]);
                bubbleUp(parentIndex);
            }
        }

    public:
        Heap()
        {
            heap.resize(1);
        }

        Heap(long long size)
        {
            heap.setSize(size);
            top = size - 1;
        }

        ~Heap()
        {
        }

        T pop()
        {
            return remove(1);
        }

        T remove(long long index)
        {
            if (getTop() < 1)
                gtool::err("Heap is empty by T &pop()");
            // do remove action here

            T out = heap[index];
            std::swap(heap[getTop()], heap[index]);
            top--;
            bubbleDown(index);

            return out;
        }

        T getRoot()
        {
            if (getTop() < 1)
                gtool::err("Heap is empty by T &getRoot()");

            return heap[1];
        }

        void insert(const T &value)
        {
            heap.push_back(value);
            top++;
            bubbleUp(getTop());
        }

        void reHeapify()
        {
            for (long long i = getTop() / 2; i >= 1; i--)
            {
                bubbleDown(i);
            }
        }

        long long size()
        {
            return getTop();
        }

        T &operator[](long long index)
        {
            return heap[index + 1];
        }

        gtool::Heap<T, cmp> &operator=(const gtool::Heap<T, cmp> &t)
        {
            heap = std::vector<T>(t.heap);
            top = heap.size() - 1;
            return *this;
        }

        void operator+=(gtool::Heap<T, cmp> &t)
        {
            for (long long i = 0; i < t.size(); i++)
            {
                insert(t[i]);
            }
        }

        void operator+=(std::vector<T> &t)
        {
            for (long long i = 0; i < t.size(); i++)
            {
                insert(t[i]);
            }
        }

        void operator+=(T &t)
        {
            insert(t);
        }
    };
}
#endif
