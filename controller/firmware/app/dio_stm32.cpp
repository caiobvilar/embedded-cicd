#include "dio_stm32.hpp"

extern "C" {
#include "stm32l4xx_hal.h"
}

void dio_stm32::write(dioPort_t port, dioPin_t pin, dioState_t state) {
  HAL_GPIO_WritePin((GPIO_TypeDef*)port, pin, (GPIO_PinState)state);
}

dio_stm32::dioState_t dio_stm32::read(dioPort_t port, dioPin_t pin) {
  return (dioState_t)HAL_GPIO_ReadPin((GPIO_TypeDef*)port, pin);
}