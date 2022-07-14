#ifndef GENE_TOOL_CONTAINER_HEAP
#define GENE_TOOL_CONTAINER_HEAP

#include <algorithm>
#include <string>
#include "./array_list.hpp"

namespace gtool
{
    template <typename T, bool (*cmp)(const T &, const T &)>
    class Heap
    {
    private:
        gtool::ArrayList<T> heap;

        long long getParent(long long index)
        {
            return index / 2;
        }

        long long getLeftChild(long long index)
        {
            return index * 2;
        }

        long long heapSize()
        {
            return heap.getArrSize();
        }

        long long getTop()
        {
            return heap.size() - 1;
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
            heap.setTop(0);
        }

        Heap(long long size)
        {
            heap.setTop(0);
            heap.setSize(size + 1);
        }

        ~Heap()
        {
        }

        T &pop()
        {
            if (getTop() < 1)
                gtool::err("Heap is empty by T &pop()");
            // do pop action here

            T min = heap[1];
            std::swap(heap[getTop()], heap[1]);
            heap.pop();
            bubbleDown(1);

            return min;
        }

        T getRoot()
        {
            return heap[1];
        }

        void insert(const T &value)
        {
            heap.push(value);
            bubbleUp(getTop());
        }

        void clear()
        {
            heap.setTop(0);
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

        long long getHeapSize()
        {
            return heapSize();
        }

        T &operator[](long long index)
        {
            return heap[index + 1];
        }

        gtool::Heap<T, cmp> &operator=(const gtool::Heap<T, cmp> &t)
        {
            heap = t.heap;
            return *this;
        }

        void operator+=(gtool::Heap<T, cmp> &t)
        {
            for (long long i = 0; i < t.size(); i++)
            {
                insert(t[i]);
            }
        }

        void operator+=(gtool::ArrayList<T> &t)
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
