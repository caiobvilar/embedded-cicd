#ifndef __LED_H
#define __LED_H

#include "stm32l475xx.h"   // For GPIO_TypeDef
#include "stm32l4xx_hal.h" // For HAL_GPIO_TogglePin
#include <cstdint>         // For std::uint32_t

class Led {
public:
    typedef enum {
        OFF = 0,
        ON = 1
    } LedState_t;

    typedef GPIO_TypeDef * port_t;
    typedef std::uint32_t pin_t;

    // Standard class constructors
    Led();
    Led(port_t port,
        const pin_t pin);

    // Destructor
    ~Led() = default;

    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of Led objects.
    Led(const Led &other) = delete;
    Led& operator=(const Led&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of Led objects.
    Led(Led &&other) = delete;
    Led &operator=(Led &&other) = delete;
    
    // Class methods
    virtual void on();
    virtual void off();
    virtual void toggle();
    LedState_t getState() const;

protected:
    LedState_t state;
    const port_t port;
    const pin_t pin;
private:

};

class LedBlue : public Led {
public:
    LedBlue(port_t port, const pin_t pin) : Led(port, pin){state = OFF;};
    ~LedBlue() = default;

    void toggle() override {
        HAL_GPIO_TogglePin(port, pin);
    };

    void setBrightness(const std::uint32_t brightness){
        this->brightness = brightness;
    };

private:
    std::uint32_t brightness;
};



#endif /* __LED_HPP */