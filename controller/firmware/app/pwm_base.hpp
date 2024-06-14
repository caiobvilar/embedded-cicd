#ifndef __PWM_BASE_H
#define __PWM_BASE_H

#include <cstdint> // for std::uint32_t      

class pwm_base {
public:
    typedef enum {
        PWM_CHANNEL_1 = 0U,
        PWM_CHANNEL_2 = 4U,
        PWM_CHANNEL_3 = 8U,
    } pwmChannel_t;

    // Constructors and Destructors
    pwm_base() = default;
    virtual ~pwm_base() = default;
    
    // Class methods
    virtual void setDutyCycle(pwmChannel_t Channel, std::uint16_t DutyCycleInTenths) = 0;

protected:
    uint16_t dutyCycleInTenths;

private:
    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of pwm objects.
    pwm_base(const pwm_base &other) = delete;
    pwm_base& operator=(const pwm_base&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of pwm objects.
    pwm_base(pwm_base &&other) = delete;
    pwm_base &operator=(pwm_base &&other) = delete;
};

#endif /* __PWM_BASE_HPP */
