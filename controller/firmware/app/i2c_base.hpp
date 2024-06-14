#ifndef __I2C_BASE_H
#define __I2C_BASE_H

#include <cstdint> // for std::uint32_t      

class i2c_base {
public:
    // Constructors and Destructors
    i2c_base() = default;
    virtual ~i2c_base() = default;
    
    // Class methods
    virtual void register_write(uint8_t const devAddress,
                                uint8_t const registerAddress, 
                                uint8_t const * const txData, 
                                uint8_t const txDataSizeInBytes) = 0;


private:
    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of dio objects.
    i2c_base(const i2c_base &other) = delete;
    i2c_base& operator=(const i2c_base&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of dio objects.
    i2c_base(i2c_base &&other) = delete;
    i2c_base &operator=(i2c_base &&other) = delete;
};

#endif /* __I2C_BASE_HPP */
