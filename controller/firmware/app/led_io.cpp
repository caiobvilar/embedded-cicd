#include "led_io.hpp"

led_io::led_io(dio_base<uint32_t> *dio, dio_base<uint32_t>::dioPort_t port, dio_base<uint32_t>::dioPin_t pin)
    : dio(dio), port(port), pin(pin) {
  state = OFF;
};

void led_io::on() { dio->write(port, pin, dio->HIGH); }

void led_io::off() { dio->write(port, pin, dio->LOW); }

void led_io::toggle() {
  dio->write(port, pin,
             (dio->read(port, pin) == dio->HIGH) ? dio->LOW : dio->HIGH);

  state = (state == ON) ? OFF : ON;
}