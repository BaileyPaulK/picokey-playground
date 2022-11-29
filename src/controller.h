#ifndef CONTROLLER
#define CONTROLLER

#include "tusb.h"
class controller
{
private:
    /* data */
public:
    void sendReport();
    void set();
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