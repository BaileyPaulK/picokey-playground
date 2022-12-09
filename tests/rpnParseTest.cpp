#include <iostream>
#include "../src/rpnParser.h"
#include <string.h>
#include <deque>
using namespace std;

bool test (string equation, deque<refernce> refernces, int8_t expected)
{
    try
    {
        rpnParser eq(equation, &refernces);
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
    rpnParser eq(equation, &refernces); //have to redefine because try is out of scope and to lazy to figure out better solution
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
    if (value != expected)
    {
        cout << "wrong solution for '" << equation << "'\nRefs: ";
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
    int8_t expected;
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

    expected = 18 / 9;
    if (test("18 / 9", deque<refernce> {}, expected))
    {
        return 1;
    }

    expected = 18 % 9;
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
                {.name= "a", .address= a},
                {.name= "b", .address= b}
            };

            expected = a == b;
            if (test("a == b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a <= b;
            if (test("a <= b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a >= b;
            if (test("a >= b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a && b;
            if (test("a && b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a || b;
            if (test("a || b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a > b;
            if (test("a > b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a < b;
            if (test("a < b", deque<refernce> {}, expected))
            {
                return 1;
            }

            expected = a == b;
            if (test("a == b", deque<refernce> {}, expected))
            {
                return 1;
            }
        }
    }
    
    
    
    //order of operations tests
    expected = 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3;
    if (test("3 + 4 * 2 ÷ ( 1 - 5 ) ^ 2 ^ 3", deque<refernce> {}, expected))
    {
        return 1;
    }
    

    return 0; //succsess
}