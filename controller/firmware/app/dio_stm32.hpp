#ifndef __DIO_STM32_H
#define __DIO_STM32_H

#include <cstdint> // for std::uint32_t      
#include "dio_base.hpp" // for dio_base

class dio_stm32 : public dio_base<std::uint32_t>{
public:
    // Constructors and Destructors
    dio_stm32() = default;
    ~dio_stm32() = default;
    
    // Class methods
    void write(dioPort_t port, dioPin_t pin, dioState_t state) override;
    dioState_t read(dioPort_t port, dioPin_t pin) override;
};

#endif /* __DIO_STM32_HPP */
