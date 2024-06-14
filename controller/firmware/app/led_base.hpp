#ifndef __LED_BASE_H
#define __LED_BASE_H

class led_base {
public:
    typedef enum {
        OFF = 0,
        ON = 1
    } LedState_t;

    // Constructors and Destructors
             led_base() = default;
    virtual ~led_base() = default;
    
    // Class methods
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;

    LedState_t getState() const;

protected:
    LedState_t state;

private:
    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of Led objects.
    led_base(const led_base &other) = delete;
    led_base& operator=(const led_base&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of Led objects.
    led_base(led_base &&other) = delete;
   led_base &operator=(led_base &&other) = delete;
};

#endif /* __LED_BASE_HPP */
