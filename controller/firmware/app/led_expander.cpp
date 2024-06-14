#include "led_expander.hpp"
#include "main.h"

namespace {
    uint16_t regAddress = 0x1;
    uint8_t  txData = 0x00;
}

led_expander::led_expander(i2c_base * const i2c, uint8_t const devAddress): i2c(i2c), devAddress(devAddress<<1) {
    state = OFF;

    Early_Init();

    // Set Bank A to output
    regAddress = 0xF;
    i2c->register_write(this->devAddress, regAddress, &txData, 1);

    // Disable Bank A LED mode
    regAddress = 0x21;
    i2c->register_write(this->devAddress, regAddress, &txData, 1);

    // Set Bank A pin 0 to ground
    regAddress = 0x11;
    i2c->register_write(this->devAddress, regAddress, &txData, 1);
};

void led_expander::on() {
    txData = 0x01;

    i2c->register_write(devAddress, regAddress, &txData, 1);
    state = ON;
}

void led_expander::off() {
    txData = 0x00;

    i2c->register_write(devAddress, regAddress, &txData, 1);
    state = OFF;
}

void led_expander::toggle() {
    if (state == ON) {
        off();
    } else {
        on();
    }
}