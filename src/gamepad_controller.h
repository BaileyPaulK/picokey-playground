/*
handles gamepad inputs from controlls and manages report
*/
#ifndef GAMEPAD_CONTROLLER
#define GAMEPAD_CONTROLLER

#include "tusb.h"
const int LEFT_STICK    = 0;
const int RIGHT_STICK   = 1;
const int LEFT_TRIGGER  = 2;
const int RIGHT_TRIGGER = 3;
const int BUTTON        = 4;


class gamepad_controller
{
private:
    /* data */
    void zeroReport();
    bool _lastzero = 0;
    hid_gamepad_report_t _report;
    const hid_gamepad_report_t _zeroreport =
      {
        .x   = 0, .y = 0, .z = 0, .rz = 0, .rx = 0, .ry = 0,
        .hat = 0, .buttons = 0
      };
public:
    gamepad_controller(/* args */);
    ~gamepad_controller();
    void set(int, int[3]);
    void sendReport();
};

gamepad_controller::gamepad_controller(/* args */)
{
    zeroReport();
}

gamepad_controller::~gamepad_controller()
{
}

#endif