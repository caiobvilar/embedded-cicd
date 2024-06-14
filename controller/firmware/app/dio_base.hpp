#ifndef __DIO_BASE_H
#define __DIO_BASE_H

#include <cstdint> // for std::uint32_t      

template <typename PortWidth = std::uint32_t>
class dio_base {
public:
    typedef enum {
        LOW = 0,
        HIGH = 1
    } dioState_t;

    typedef PortWidth dioPort_t;
    typedef PortWidth dioPin_t;

    // Constructors and Destructors
    dio_base() = default;
    virtual ~dio_base() = default;
    
    // Class methods
    virtual void write(dioPort_t port, dioPin_t pin, dioState_t state) = 0;
    virtual dioState_t read(dioPort_t port, dioPin_t pin) = 0;

private:
    // Delete the copy constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow copying of dio objects.
    dio_base(const dio_base &other) = delete;
    dio_base& operator=(const dio_base&) = delete;

    // Delete the move constructor and assignment operator.
    // This prevents the compiler from generating them.
    // We don't want to allow moving of dio objects.
    dio_base(dio_base &&other) = delete;
    dio_base &operator=(dio_base &&other) = delete;
};

#endif /* __DIO_BASE_HPP */
