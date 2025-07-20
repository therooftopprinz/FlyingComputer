#ifndef __HALSIM_IPC_IPC_HPP__
#define __HALSIM_IPC_IPC_HPP__

#include <halsim_ipc/sync.hpp>

namespace hal
{

struct command_s
{
    size_t data_sz;
    std::byte data[1024];
    bool satisfied;
    mutex m;
    condition_variable cv;
};

class ipc
{
public:
    command_s& current()
    {
        scoped_lock lg(m);
        return cmd_queue[head];
    }

    void enqueue(const std::byte* in, size_t in_sz, std::byte* out, size_t& out_sz)
    {
        size_t i = 0;

        {
            scoped_lock lg(m);
            while (n == N)
            {
                cv.wait(lg);
            }

            i = tail;
            tail = (tail+1)%N;
            n++;
        }

        auto& c = cmd_queue[i];

        c.data_sz = in_sz;
        c.satisfied = false;
        std::memcpy(c.data, in, c.data_sz);
        
        {
            scoped_lock lg(c.m);
            while (!c.satisfied)
            {
                c.cv.wait(lg);
            }

            out_sz = c.data_sz;
            std::memcpy(out, c.data, c.data_sz);
        }

        {
            scoped_lock lg(m);
            head = (head+1)%N;
            n--;
        }
    }

    void dequeue()
    {
        scoped_lock lg(m);
        auto& c = cmd_queue[head];
        c.satisfied = true;
        c.cv.notify_one();
    }

private:
    constexpr static size_t N = 1024*64;
    command_s cmd_queue[N];
    size_t head = 0;
    size_t tail = 0;
    size_t n = 0;
    mutex m;
    condition_variable cv;
};

} // namespace hal

#endif // __HALSIM_IPC_IPC_HPP__
