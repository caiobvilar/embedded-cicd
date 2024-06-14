#ifndef __LED_PWM_H
#define __LED_PWM_H

#include "led_base.hpp"    // For led_base
#include "pwm_base.hpp"    // For pwm_base
#include <cstdint>         // For std::uint32_t

class led_pwm final: public led_base {
public:
    // Standard class constructors
    led_pwm(pwm_base * pwm, pwm_base::pwmChannel_t channel);
    
    // Destructor
    ~led_pwm() = default;

    // Class methods
    void on() override;
    void off() override;
    void toggle() override;

    void setBrightness(std::uint16_t brightness);
    std::uint16_t getBrightness() const;

private:
    pwm_base * const pwm;
    std::uint16_t brightness;
    const pwm_base::pwmChannel_t channel;
};

#endif /* __LED_IO_HPP */