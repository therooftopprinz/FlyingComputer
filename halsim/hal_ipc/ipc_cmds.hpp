#ifndef __HALSIM_IPC_IPC_HPP__
#define __HALSIM_IPC_IPC_HPP__

#include <hal_ipc/sync.hpp>

namespace hal
{

enum cmd_e
{
    E_CMD_SPI_INIT
};

struct spi_init
{
    char name[128];
    
};

static_assert(1024 >= sizeof(spi_init_s));

} // namespace hal

#endif // __HALSIM_IPC_IPC_HPP__
