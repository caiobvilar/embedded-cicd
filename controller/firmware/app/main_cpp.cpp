
#include <cstdint>
#include <utility>
#include <cstdio>
#include <string>

#include "dio_stm32.hpp"
#include "led_io.hpp"
#include "led_pwm.hpp"
#include "led_expander.hpp"
#include "relay_io.hpp"
#include "pwm_stm32.hpp"
#include "i2c_stm32.hpp"
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern I2C_HandleTypeDef hi2c1;

namespace {
dio_stm32 dio{};
pwm_stm32 pwm{&htim3, pwm_stm32::PWM_CHANNEL_3};
i2c_stm32 i2c{&hi2c1};

relay_io relayGreen{&dio, (std::uint32_t)LED2_GPIO_Port, LED2_Pin};
led_io ledBlue{&dio, (std::uint32_t)GPIOC, GPIO_PIN_9};
led_pwm ledRed{&pwm, pwm_base::PWM_CHANNEL_3};
led_expander ledGreen{&i2c, 0x3E};

constexpr bool EnableLedBrightness = false;
constexpr bool EnableDynamicPolymorphism = true;

void led_toggler(led_base& led) { led.toggle(); }

template <typename led_t>
void led_stoggler(led_t& led) { led.toggle(); }

}  // namespace

namespace template_functions {
    template <typename T>
    T min(const T& a, const T& b) {
    return a < b ? a : b;
    }

    template <typename T1, typename T2>
    T1 add(const T1& a, const T2& b) {
    return a + (T1)b;
    }

    template <typename T>
    T max(const T& a, const T& b) {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

    return (a > b) ? a : b;
    }
}

int main_cpp(void) {
  // The following loop is the main loop for our C++ application.
  // We don't expect it to ever return.
  static uint32_t counter = 0;
  
  const std::uint32_t value0 = template_functions::min(42, 43);
  const std::uint16_t value1 = template_functions::min(41, 43);
  const std::uint8_t value2 = template_functions::min<std::uint16_t>(40, 43);

  const auto value3 = template_functions::add(42, 43);
  const std::uint16_t value4 = template_functions::add<std::uint16_t, std::uint8_t>(41, 43);
  static const float value5 = template_functions::add<float, float>(40.0, 43.5);
 
  const auto value6 = template_functions::max(42, 43);
  const std::uint16_t value7 = template_functions::max(41, 43);
  const std::uint8_t value8 = template_functions::max<std::uint8_t>(40, 43);

//    std::string a = "Hello";
//    std::string b = "World";
//    auto result = template_functions::max(a, b);

    std::printf("Hello World! %lu %u %d %d %u %0.1f %u %u %d\r\n", value0, value1, value2, value3, value4, value5, value6, value7, value8);

    // Here is an example of creating a pointer to a base class and
    // using it to call a method on a derived class.
    //    led_base *led = &ledGreen;
    //    led->toggle();
    if constexpr(EnableDynamicPolymorphism) {
        led_toggler(ledBlue);
        led_toggler(ledGreen);  
    } else {
        led_stoggler(ledBlue);
        led_stoggler(ledGreen);
    }

    if constexpr (EnableLedBrightness)
    {
        ledRed.setBrightness(counter);
        counter += 200;
        if (counter > 1000)
        {
            counter = 0;
        }
    } else {
        if constexpr(EnableDynamicPolymorphism) {
          led_toggler(ledRed);
        } else {
          led_stoggler(ledRed);
        }
    }

    if(relayGreen.getState() == relay_base::CLOSED) {
      relayGreen.open();
    } else {
      relayGreen.close();
    }

  return 42;
}
