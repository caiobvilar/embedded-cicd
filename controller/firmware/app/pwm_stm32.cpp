#include "main.h"
#include "stm32l4xx_hal_tim.h"
#include "pwm_stm32.hpp"

namespace {
TIM_OC_InitTypeDef sConfigOC = {0};
std::uint16_t OFF = UINT16_C(0);
}  // namespace

pwm_stm32::pwm_stm32(TIM_HandleTypeDef* htim, pwmChannel_t channel)
                                            : htim(htim), channel(channel) {                                           
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = dutyCycleInTenths;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    setDutyCycle(channel, OFF);
};

void pwm_stm32::setDutyCycle(pwmChannel_t channel, std::uint16_t dutyCycleInTenths){
    sConfigOC.Pulse = dutyCycleInTenths;
    HAL_TIM_PWM_Stop(htim, channel);
    HAL_TIM_PWM_ConfigChannel(htim, &sConfigOC, channel);
    HAL_TIM_PWM_Start(htim, channel);
}