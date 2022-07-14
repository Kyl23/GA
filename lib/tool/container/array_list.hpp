#ifndef GENE_TOOL_CONTAINER_ARRAY_LIST
#define GENE_TOOL_CONTAINER_ARRAY_LIST

#include <memory.h>
#include <exception>
#include "../console.hpp"

namespace gtool
{
    template <typename T>
    class ArrayList
    {
    private:
        T *arr;

        long long arrSize = 100;

        long long top = -1;

        void extendArr()
        {
            if (arrSize < 0x7fffffffffffffff / 2)
                arrSize *= 2;
            else
                arrSize = 0x7fffffffffffffff;

            T *temp = new T[arrSize];
            memcpy(&temp[0], &arr[0], sizeof(T) * (top + 1));
            delete[] arr;
            arr = temp;
        }

    public:
        ArrayList()
        {
            arr = new T[arrSize];
        }
        
        ArrayList(long long initSize)
        {
            arrSize = initSize;
            arr = new T[arrSize];
        }

        ~ArrayList()
        {
            delete[] arr;
        }

        T &operator[](long long index)
        {
            return arr[index];
        }

        void setTop(long long index)
        {
            top = index;
        }

        void setSize(long long size)
        {
            delete[] arr;
            arr = new T[size];
            arrSize = size;
        }

        void pop()
        {
            top--;
        }

        void push(const T &value)
        {
            if (top == arrSize - 1 && top == 0x7fffffffffffffff - 1)
                gtool::err("ArrayList is overflow by void push(T value)");
            if (top == arrSize - 1)
            {
                extendArr();
            }
            // do insert here
            arr[++top] = value;
        }

        long long size()
        {
            return top + 1;
        }

        long long getArrSize()
        {
            return arrSize;
        }

        void clear()
        {
            top = -1;
        }

        gtool::ArrayList<T> &operator=(const gtool::ArrayList<T> &t)
        {
            clear();
            setSize(t.arrSize);
            memcpy(&arr[0], &t.arr[0], sizeof(T) * (t.top + 1));
            top = t.top;
            return *this;
        }

        void operator+=(gtool::ArrayList<T> &t)
        {
            for (long long i = 0; i < t.size(); i++)
            {
                push(t[i]);
            }
        }

        void operator+=(T &t)
        {
            push(t);
        }
    };
}

#endif
