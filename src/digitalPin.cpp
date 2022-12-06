#include "digitalPin.h"
bool digitalPin::get()
{
    return (gpio_get(_pin) != 0);
}