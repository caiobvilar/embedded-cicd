#ifndef __PWM_STM32_H
#define __PWM_STM32_H

#include "pwm_base.hpp" // for pwm_base
#include <cstdint>      // for std::uint16_t      
#include "stm32l475xx.h"   // For GPIO_TypeDef
#include "stm32l4xx_hal.h" // For HAL_GPIO_TogglePin

class pwm_stm32 final: public pwm_base {
public:
    // Constructors and Destructors
    pwm_stm32(TIM_HandleTypeDef * htim, pwmChannel_t channel);
    ~pwm_stm32() = default;
    
    // Class methods
    void setDutyCycle(pwmChannel_t channel, std::uint16_t dutyCycleInTenths) override;

private:
    TIM_HandleTypeDef * const htim;
    pwmChannel_t const channel;
};

#endif /* __PWM_STM32_HPP */
