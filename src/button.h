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
#endif