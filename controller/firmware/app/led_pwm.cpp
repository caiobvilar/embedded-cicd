#include "led_pwm.hpp"
#include "main.h"
#include "stm32l4xx_hal_tim.h"

namespace {
std::uint16_t LED_ON = UINT16_C(1000);
std::uint16_t LED_OFF = UINT16_C(0);
}  // namespace

led_pwm::led_pwm(pwm_base * pwm, pwm_base::pwmChannel_t channel)
    : pwm(pwm), channel(channel) {
  state = OFF;
  brightness = LED_OFF;

  setBrightness(brightness);
};

void led_pwm::on() {
  setBrightness(LED_ON);
  state = ON;
}

void led_pwm::off() {
  setBrightness(LED_OFF);
  state = OFF;
}

void led_pwm::toggle() {
  if (state == ON) {
    off();
  } else {
    on();
  }
}

void led_pwm::setBrightness(std::uint16_t brightness) {
  this->brightness = brightness;
  pwm->setDutyCycle(channel, brightness);
}

std::uint16_t led_pwm::getBrightness() const { return brightness; }
