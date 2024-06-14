#ifndef __LED_EXPANDER_H
#define __LED_EXPANDER_H

#include "led_base.hpp"    // For led_base
#include "i2c_base.hpp"

class led_expander final: public led_base {
public:
    // Standard class constructors
    led_expander(i2c_base *const i2c, uint8_t const devAddress);

    // Destructor
    ~led_expander() = default;

    // Class methods
    void on() override;
    void off() override;
    void toggle() override;

protected:
    LedState_t state;

private:
    i2c_base * const i2c;
    uint8_t const devAddress;
};

#endif /* __LED_EXPANDER_HPP */
