#include "gamepad_controller.h"

void gamepad_controller::set(int type, int input [3])
{
    switch (type)
    {
    case LEFT_STICK:
        _report.x += input[0];
        _report.y += input[1];
        //handle hat
        break;
    case RIGHT_STICK:
        _report.rx += input[0];
        _report.ry += input[1];
        //handle hat
        break;
    case LEFT_TRIGGER:
        _report.z += input[0];
        break;
    case RIGHT_TRIGGER:
        _report.rz += input[0];
        break;
    case BUTTON:
        //need to handle button
        break;
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
}

void gamepad_controller::sendReport()
{
    if (_lastzero != 0 || _report != _zeroreport)
    {
        tud_hid_report(REPORT_ID_GAMEPAD, &_report, sizeof(_report));
        zeroReport();
    }
}

void gamepad_controller::zeroReport()
{
    if (_report == _zeroreport)
    {
        _lastzero = 1;
    }
    _report = _zeroreport
}
