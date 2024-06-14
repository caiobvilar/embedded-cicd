#ifndef __RELAY_BASE_H
#define __RELAY_BASE_H

#include <cstdint> // for std::uint32_t      

class relay_base {
public:
    typedef enum {
        CLOSED = 0,
        OPEN = 1
    } relayState_t;

    // Constructors and Destructors
    relay_base() = default;
    virtual ~relay_base() = default;
    
    // Class methods
    virtual void close() = 0;
    virtual void open() = 0;
    relayState_t getState() { return state; }

protected:
    relayState_t state;

private:
    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of Led objects.
    relay_base(const relay_base &other) = delete;
    relay_base& operator=(const relay_base&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of Led objects.
    relay_base(relay_base &&other) = delete;
    relay_base &operator=(relay_base &&other) = delete;
};

#endif /* __RELAY_BASE_HPP */
