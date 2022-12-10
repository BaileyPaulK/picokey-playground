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
#include <iostream>
#include <math.h>
using namespace std;

struct refernce
{
    string      name;
    int8_t*    address;
};

struct op
{
    int8_t code;       //defined value to represent op (for switch statments && queue)
    int8_t priority;   //higher value indicates higher priority
    float value;      //value for numbers, index for refernces
};

static constexpr op NumOP      = {.code=-1, .priority=-1};// excluded from op switches, default for static numbers
static constexpr op RefOP      = {.code=0, .priority=10}; // & derefrence
static constexpr op AbsOP      = {.code=1, .priority=6};  // abs absolute value
static constexpr op MaxOP      = {.code=2, .priority=6};  // max  max
static constexpr op MinOP      = {.code=3, .priority=6};  // min  min
static constexpr op PowOP      = {.code=4, .priority=5};  // ^
static constexpr op MultOP     = {.code=5, .priority=4};  // *
static constexpr op DividOP    = {.code=6, .priority=4};  // /
static constexpr op ModOP      = {.code=7, .priority=4};  // %
static constexpr op AddOP      = {.code=8, .priority=3};  // +
static constexpr op SubOP      = {.code=9, .priority=3};  // -
static constexpr op LessOP     = {.code=10, .priority=2}; // <
static constexpr op GreatOP    = {.code=11, .priority=2}; // >
static constexpr op LessOrOP   = {.code=12, .priority=2}; // <=
static constexpr op GreatOrOP  = {.code=13, .priority=2}; // >=
static constexpr op EqualOP    = {.code=14, .priority=2}; // ==
static constexpr op AndOP      = {.code=15, .priority=1}; // &&
static constexpr op OrOP       = {.code=16, .priority=1}; // ||
static constexpr op LParenOP   = {.code=17, .priority=0};// ( special conditions
static constexpr op RParenOP   = {.code=18, .priority=0};// ) special conditions

class rpnParser
{
private:
    deque<op>       parsed;
    deque<refernce> refernces;
    void parseToOps(string equation); //parse equation string into ops in parsed
    void rpnParse();                  //take parsed ops and parse into rpn
    op findOp(string token);
    int8_t getRefIndex(string token);
public:
    rpnParser(string equation, deque<refernce>& refsPtr);
    ~rpnParser();
    float eval();
};
#endif