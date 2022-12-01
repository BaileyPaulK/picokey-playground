/*
gpio pin that can do binary in and out
*/
#ifndef DIGITAL_PIN
#define DIGITAL_PIN
#include "pico/stdlib.h"
class digitalPin
{
private:
    int _pin;
    bool _isInput;
public:
    digitalPin(int);
    ~digitalPin();
    void inputPin();
    bool get();
    void outputPin();
    bool set(bool);

};

digitalPin::digitalPin(int pin)
{
    _pin = pin;
    gpio_init(_pin);
}

digitalPin::~digitalPin()
{
}

#endif