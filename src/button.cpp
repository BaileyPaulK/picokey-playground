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
