#ifndef __I2C_STM32_H
#define __I2C_STM32_H

#include <cstdint>      // for std::uint32_t      
#include "i2c_base.hpp" // for i2c_base

extern "C" {
#include "stm32l4xx_hal.h"
}

class i2c_stm32 final : public i2c_base {
public:
    // Constructors and Destructors
    i2c_stm32(I2C_HandleTypeDef * hi2c) : hi2c(hi2c) {};
    ~i2c_stm32() = default;
    
    // Class methods
    void register_write(uint8_t const devAddress,
                        uint8_t const registerAddress, 
                        uint8_t const * const txData, 
                        uint8_t const txDataSizeInBytes) override;

private:
    I2C_HandleTypeDef *const hi2c; 

};

#endif /* __I2C_STM32_HPP */
