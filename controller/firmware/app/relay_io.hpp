#ifndef __RELAY_IO_H
#define __RELAY_IO_H

#include "relay_base.hpp"  // For relay_base
#include "dio_base.hpp"    // For dio_base
#include <cstdint>         // For std::uint32_t

class relay_io final: public relay_base {
public:
    // Standard class constructors
    relay_io(dio_base<std::uint32_t> *dio, dio_base<std::uint32_t>::dioPort_t port, dio_base<std::uint32_t>::dioPin_t pin);

    // Destructor
    ~relay_io() = default;

    // Class methods
    void close() override;
    void open() override;

private:
    dio_base<std::uint32_t> * const dio;
    dio_base<std::uint32_t>::dioPort_t const port;
    dio_base<std::uint32_t>::dioPin_t const pin;
};

#endif /* __RELAY_IO_HPP */