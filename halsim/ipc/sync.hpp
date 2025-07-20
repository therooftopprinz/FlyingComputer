#ifndef __HALSIM_IPC_SYNC_HPP__
#define __HALSIM_IPC_SYNC_HPP__

#include <cstdint>
#include <string>

#include <pthread.h>
#include <errno.h>

#include <cstring>
#include <stdexcept>

namespace hal
{

template<typename... Ts>
std::string format(const char* fmt, Ts&&... ts)
{
    char out[1024*64];
    snprintf(out, sizeof(out), fmt, ts...);
    return out;
}

class mutex
{
public:
    mutex()
    {
        pthread_mutexattr_t attr;
        if (0 != pthread_mutexattr_init(&attr))
        {
            throw std::runtime_error(format("Failed to initialize mutex attributes error=%s", strerror(errno)));
        }

        if (0 != pthread_mutex_init(&m_mutex, &attr))
        {
            throw std::runtime_error(format("Failed to initialize mutex error=%s", strerror(errno)));
        }

        pthread_mutexattr_destroy(&attr);
    }

    ~mutex()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    mutex(const mutex&) = delete;
    mutex& operator=(const mutex&) = delete;

    void lock();
    void unlock();
    bool try_lock();

private:
    pthread_mutex_t m_mutex;
};

template<typename mutex>
class scoped_lock
{
public:
    scoped_lock(mutex& m)
        : m(&m)
    {
        m.lock();
    }

    ~scoped_lock()
    {
        m->unlock();
    }

    void lock()
    {
        m->lock();
    }

    void unlock()
    {
        m->unlock();
    }

private:
    mutex* m;
};

class condition_variable
{
public:
    template <typename lock>
    void wait(lock&);
    void notify_one();
    void notify_all();
private:
};

} // namespace hal

#endif // __HALSIM_IPC_SYNC_HPP__
