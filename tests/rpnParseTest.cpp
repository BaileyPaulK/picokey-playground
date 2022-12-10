#include <iostream>
#include "../src/rpnParser.h"
#include <string.h>
#include <deque>
using namespace std;

const float AcceptedPercentageError = 0.001; 

bool test (string equation, deque<refernce> refernces, float expected)
{
    try
    {
        rpnParser eq(equation, refernces);
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        cout << "failed to make parser for '" << equation << "'\nRefs: ";
        for (refernce token: refernces)
        {
            cout << token.name << ", ";
        }
        cout << endl;
        return 1;
    }
    rpnParser eq(equation, refernces); //have to redefine because try is out of scope and to lazy to figure out better solution
    int8_t value;
    try
    {
        value = eq.eval();
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        cout << "failed to evaluate for '" << equation << "'\nRefs: ";
        for (refernce token: refernces)
        {
            cout << token.name << ", ";
        }
        cout << endl;
        return 1;
    }
    value = eq.eval(); // redo since try out of scope
    if (abs(value - expected) / expected > AcceptedPercentageError)
    {
        cout << "wrong solution for '" << equation << "', " << to_string(value) << " != " << to_string(expected) << " (expected)\nRefs: ";
        for (refernce token: refernces)
        {
            cout << token.name << ", ";
        }
        cout << endl;
        return 1;
    }
    return 0;
}

int main ()
{
    cout << "Testing rpnParser.cpp" << endl;
    float expected;
    //test simple parse

    expected = abs(-23);
    if (test("abs(-23)", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = abs(-23);
    if (test("abs -23", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = max(-23, 0);
    if (test("max(-23, 0)", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = min(-23, 0);
    if (test("min(-23, 0)", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = pow(2, 3);
    if (test("2 ^ 3", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = pow(-2, 3);
    if (test("-2 ^ 3", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 / 9;
    if (test("18 / 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = fmod(18.0, 9.0);
    if (test("18 % 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 3 + 4;
    if (test("3 + 4", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 3 - 4;
    if (test("3 - 4", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 < 9;
    if (test("18 < 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 > 9;
    if (test("18 > 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 <= 9;
    if (test("18 <= 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 >= 9;
    if (test("18 >= 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 == 9;
    if (test("18 == 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 9 == 9;
    if (test("9 == 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    for (int8_t a = 0; a <= 1; a++)
    {
        for (int8_t b = 0; b <= 1; b++)
        {
            deque<refernce> refernces = {
                {.name= "a", .address= &a},
                {.name= "b", .address= &b}
            };

            expected = a == b;
            if (test("a& == b&", refernces, expected))
            {
                return 1;
            }

            expected = a <= b;
            if (test("a& <= b&", refernces, expected))
            {
                return 1;
            }

            expected = a >= b;
            if (test("a& >= b&", refernces, expected))
            {
                return 1;
            }

            expected = a && b;
            if (test("a& && b&", refernces, expected))
            {
                return 1;
            }

            expected = a || b;
            if (test("a& || b&", refernces, expected))
            {
                return 1;
            }

            expected = a > b;
            if (test("a& > b&", refernces, expected))
            {
                return 1;
            }

            expected = a < b;
            if (test("a& < b&", refernces, expected))
            {
                return 1;
            }

            expected = a == b;
            if (test("a& == b&", refernces, expected))
            {
                return 1;
            }
        }
    }
    
    
    
    //order of operations tests
    expected = 3.0 + 4.0 * 2.0 / pow(pow(( 1.0 - 5.0 ), 2.0), 3.0);
    if (test("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3", deque<refernce> {}, expected))
    {
        return 1;
    }
    

    return 0; //succsess
}