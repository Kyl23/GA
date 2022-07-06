#ifndef GENE_TOOL_TIMER
#define GENE_TOOL_TIMER

#include <sys/time.h>

namespace gtool
{
    class Timer
    {
    private:
        struct timeval start_t, end_t;

    public:
        void start()
        {
            gettimeofday(&start_t, nullptr);
        }
        float end()
        {
            gettimeofday(&end_t, nullptr);

            float delta = ((end_t.tv_sec - start_t.tv_sec) * 1000000u +
                           end_t.tv_usec - start_t.tv_usec) /
                          1.e6;

            return delta;
        }
    };
}

#endif
