#include "button.h"
void button::pull()
{
    _isPressed = _pin.get();
}

void button::resolve()
{
    if (_isPressed)
    {
        _controller.set(_reportType, _report);
    }
}

button::button(int pin, controller& handler, const int& reportType, int a = 0, int b = 0, int c = 0)
{
    _pin = digitalPin(pin);
    _controller = handler;
    _reportType = reportType;
    _report[0] = a;
    _report[1] = b;
    _report[2] = c;
}
button::button(int pin, gamepad_controller& handler, const int& reportType, int a = 0, int b = 0, int c = 0)
{
    _pin = digitalPin(pin);
    _controller = handler;
    _reportType = reportType;
    _report[0] = a;
    _report[1] = b;
    _report[2] = c;
}

button::~button()
{
}