#ifndef BUTTON
#define BUTTON

#include "input.h"
#include "controller.h"
#include "gamepad_controller.h"
#include "digitalPin.h"
class button: public input
{
private:
    controller _controller;
    digitalPin _pin;
    int _reportType;
    int _report[3];
    bool _isPressed;
public:
    button(int, controller&, const int&, int, int ,int);//controller to send report to, report Type, report
    button(int, gamepad_controller&, const int&, int, int, int);//controller to send report to, report Type, report
    ~button();
    void pull();
    void resolve();
};

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

#endif