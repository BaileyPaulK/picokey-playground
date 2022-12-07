/*
using shunting yard algorythem to generate rpn
store modified version where output queue is all uint8_t and where operators are can be used as operator conditions
operator "stack" will rebuilt as a queue after parsing to include operator types and their locations (for speed and flexibility at the cost of some space/ more pre processing)
*/
#ifndef RPNPARSER_H
#define RPNPARSER_H
#include <deque>
#include <string>
#include <stdint.h>
using namespace std;

struct refernce
{
    string      name;
    int8_t&    address;
};

struct op
{
    int8_t code;       //defined value to represent op (for switch statments && queue)
    int8_t priority;   //higher value indicates higher priority
    int8_t value;      //value for numbers, index for refernces
};

const op NumOP      = {.code=-1, .priority=-1};// excluded from op switches, default for static numbers
const op DerefOP    = {.code=0, .priority=10}; // & derefrence
const op AbsOP      = {.code=1, .priority=6};  // abs absolute value
const op MaxOP      = {.code=2, .priority=6};  // max  max
const op MaxOP      = {.code=3, .priority=6};  // min  min
const op PowOP      = {.code=4, .priority=5};  // ^
const op MultOP     = {.code=5, .priority=4};  // *
const op DividOP    = {.code=6, .priority=4};  // /
const op ModOP      = {.code=7, .priority=4};  // %
const op AddOP      = {.code=8, .priority=3};  // +
const op SubOP      = {.code=9, .priority=3};  // -
const op LessOP     = {.code=10, .priority=2};  // <
const op GreatOP    = {.code=11, .priority=2}; // >
const op LessOrOP   = {.code=12, .priority=2}; // <=
const op GreatOrOP  = {.code=13, .priority=2}; // >=
const op EqualOP    = {.code=14, .priority=2}; // ==
const op AndOP      = {.code=15, .priority=1}; // &&
const op OrOP       = {.code=16, .priority=1}; // ||

class rpnParser
{
private:
    deque<op>       parsed;
    deque<refernce> refernces;
public:
    rpnParser(/* args */);
    ~rpnParser();
};

rpnParser::rpnParser(/* args */)
{
}

rpnParser::~rpnParser()
{
}

#endif