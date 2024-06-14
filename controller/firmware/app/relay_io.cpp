#include "relay_io.hpp"

relay_io::relay_io(dio_base<uint32_t> *dio, dio_base<uint32_t>::dioPort_t port, dio_base<uint32_t>::dioPin_t pin)
    : dio(dio), port(port), pin(pin) {
  state = CLOSED;
};

void relay_io::close() { 
    dio->write(port, pin, dio->HIGH); 
    state = CLOSED;
}

void relay_io::open() { 
    dio->write(port, pin, dio->LOW); 
    state = OPEN;
}
