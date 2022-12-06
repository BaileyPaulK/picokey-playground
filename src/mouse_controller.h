#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "controller.h"
#include <stdint.h>
#include "tusb.h"

class mouse_controller: controller
{
private:
    int8_t right    = 0;
    int8_t left     = 0;
    int8_t scroll   = 0;
    int8_t pan      = 0;
public:
    mouse_controller(/* args */);
    ~mouse_controller();
    bool update(int packetType, int8_t packet[]);
    void sendReport();
};

mouse_controller::mouse_controller(/* args */)
{
}

mouse_controller::~mouse_controller()
{
}

#endif