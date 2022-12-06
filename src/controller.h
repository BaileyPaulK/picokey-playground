#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tusb.h"
class controller
{
private:
    /* data */
public:
    void sendReport();
    bool update(int packetType, int8_t packet[]);
    controller(/* args */);
    ~controller();
};

controller::controller(/* args */)
{
}

controller::~controller()
{
}

#endif