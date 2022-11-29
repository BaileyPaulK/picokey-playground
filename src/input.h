#ifndef INPUT
#define INPUT

class input
{
private:
    /* data */
public:
    input(/* args */);
    ~input();
    void zero();    //can be empty, used to reset controlls (like zeroing joystick)
    void pull();    //first stage of input, gets own normaled value
    void resolve(); //2nd stage, applies mapping and handles any interaction, then adds values to reports
};

input::input(/* args */)
{
}

input::~input()
{
}

#endif