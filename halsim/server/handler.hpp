#ifndef __HALSIM_HAL_SERVER_HAL_HANDLER_HPP__
#define __HALSIM_HAL_SERVER_HAL_HANDLER_HPP__

#include "ipc/sync.hpp"

namespace hal
{

struct ISPIHandler
{
    ~ISPIHandler() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void xfer(const std::byte*, std::byte*, size_t) = 0;
};

struct II2CHandler
{
    ~II2CHandler() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void xfer(const std::byte*, std::byte*, size_t) = 0;
};

} // namespace hal

#endif // __HALSIM_HAL_SERVER_HAL_HANDLER_HPP__
