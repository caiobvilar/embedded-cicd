#ifndef __LED_IO_H
#define __LED_IO_H

#include "led_base.hpp"    // For led_base
#include "dio_base.hpp"    // For dio_base
#include <cstdint>         // For std::uint32_t

class led_io final: public led_base {
public:
    // Standard class constructors
    led_io(dio_base<std::uint32_t> *dio, dio_base<std::uint32_t>::dioPort_t port, dio_base<std::uint32_t>::dioPin_t pin);

    // Destructor
    ~led_io() = default;

    // Class methods
    void on() override;
    void off() override;
    void toggle() override;

private:
    dio_base<std::uint32_t> * const dio;
    dio_base<std::uint32_t>::dioPort_t const port;
    dio_base<std::uint32_t>::dioPin_t const pin;
};

#endif /* __LED_IO_HPP */