#include "i2c_stm32.hpp"

// Class methods
void i2c_stm32::register_write( uint8_t const devAddress,
                                uint8_t const registerAddress, 
                                uint8_t const * const txData, 
                                uint8_t const txDataSizeInBytes){

    HAL_I2C_Mem_Write(hi2c, devAddress, registerAddress, I2C_MEMADD_SIZE_8BIT, (uint8_t *)txData, 1, HAL_MAX_DELAY);
}