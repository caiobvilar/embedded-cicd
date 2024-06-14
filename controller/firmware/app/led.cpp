#include "led.hpp"

namespace {
constexpr uint32_t GPIO_NUMBER_OFFSET = 16;
}

Led::Led() : port(GPIOB), pin((std::uint32_t)0x4000) { state = OFF; }

Led::Led(port_t port, const pin_t pin) : port(port), pin(pin) { state = OFF; }

void Led::on() {
  port->BSRR = (pin_t)pin;
  state = ON;
}

void Led::off() {
  port->BRR = (pin_t)pin;
  state = OFF;
}

void Led::toggle() {
  uint32_t odr;

  odr = port->ODR;

  /* Set selected pins that were at low level, and reset ones that were high */
  port->BSRR = ((odr & pin) << GPIO_NUMBER_OFFSET) | (~odr & pin);

  state = (state == ON) ? OFF : ON;
}

Led::LedState_t Led::getState() const { return state; }