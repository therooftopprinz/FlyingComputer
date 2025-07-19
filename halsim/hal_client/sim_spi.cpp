#ifndef __HAL_HAL_HPP__
#define __HAL_HAL_HPP__

#include <hal/spi.hpp>
#include <hal_ipc/ipc_cmds.hpp>
#include <hal_ipc/ipc.hpp>

namespace hal
{

struct spi_context_s
{
    
};

spi_t spi_init(const spi_id_s& id, unsigned cs_pin, const spi_config_s& config)
{
}

void spi_deinit(spi_t spi)
{
}

int  spi_transfer(spi_t spi, const std::byte *tx_data, std::byte *rx_data, size_t count)
{
}

int  spi_write(spi_t spi, const std::byte *data, size_t count)
{
}

int  spi_read(spi_t spi, std::byte *data, size_t count)
{
}

} // namespace hal

#endif // __HAL_HAL_HPP__
