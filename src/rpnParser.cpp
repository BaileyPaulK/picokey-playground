#include "rpnParser.h"
rpnParser::rpnParser(string equation, deque<refernce>* refsPtr)
{
    this->refernces = refsPtr;
    parseToOps(equation);
    rpnParse();
}
rpnParser::~rpnParser()
{
}
int8_t rpnParser::eval()
{
    deque<op> output = this->parsed;
    int index = 0;
    while (output.size() > 1)
    {
        switch (output[index].code)
        {
        case NumOP.code: //number
            index++;
            continue;
            break;
        case RefOP.code: //refrence
            output[index].value = (*this->refernces)[output[index].value].address;
            output[index].code = -1;
            index++;
            continue;
            break;
        case AbsOP.code: //abs
            output[index - 1].value = abs(output[index - 1].value);
            output.erase(output.begin() + index);
            continue;
            break;
        case MaxOP.code: //max
            if (output[index - 1].value > output[index - 2].value)
            {
                output[index - 2].value = output[index - 1].value;
            }
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            continue;
            break;
        case MinOP.code: //min
            if (output[index - 1].value < output[index - 2].value)
            {
                output[index - 2].value = output[index - 1].value;
            }
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            continue;
            break;
        case PowOP.code: //^
            output[index-2].value = pow(output[index-2].value, output[index-1].value);
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
        case MultOP.code: //*
            output[index-2].value = output[index-2].value * output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case DividOP.code: ///
            output[index-2].value = output[index-2].value / output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case ModOP.code: //%
            output[index-2].value = output[index-2].value % output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case AddOP.code: //+
            output[index-2].value = output[index-2].value + output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case SubOP.code: //-
            output[index-2].value = output[index-2].value - output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case LessOP.code: //<
            output[index-2].value = output[index-2].value < output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case GreatOP.code: //>
            output[index-2].value = output[index-2].value > output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case LessOrOP.code: //<=
            output[index-2].value = output[index-2].value <= output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case GreatOrOP.code: //>=
            output[index-2].value = output[index-2].value >= output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case EqualOP.code: //==
            output[index-2].value = output[index-2].value == output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case AndOP.code: //&&
            output[index-2].value = output[index-2].value && output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        case OrOP.code: //||
            output[index-2].value = output[index-2].value || output[index-1].value;
            output.erase(output.begin() + index - 1, output.begin() + index);
            index--; //2 ops were erased so decrament 1 to traverse by 1 (to next unseen)
            break;
            continue;
            break;
        default:
            break;
        }
    }
    return output[0].value;
}
void rpnParser::rpnParse()
{
    deque<op> input = this->parsed;
    deque<op> opStack;
    this->parsed = opStack; //quick empty parsed
    for (op token: input)
    {
        switch (token.code)
        {
        case NumOP.code: //number
            this->parsed.push_back(token);
            continue;
            break;
        case RefOP.code:  //refrence
            this->parsed.push_back(token);
            continue;
            break;
        case LParenOP.code: // (
            opStack.push_front(token);
            continue;
            break;
        case RParenOP.code: // )
            while (opStack.front().code != 17)
            {
                this->parsed.push_back(opStack.front());
                opStack.pop_front();
            }
            opStack.pop_front(); //remove )
            continue;
            break;
        default:
            if (opStack.empty() || token.priority >= opStack.front().priority)
            {
                opStack.push_front(token);
                continue;
            } else {
                while (!opStack.empty() && opStack.front().code != 17) //go until end of stack or start of ()
                {
                    this->parsed.push_back(opStack.front());
                    opStack.pop_front();
                }
                opStack.push_front(token);
                continue;
            }
            break;
        }
    }
    while (!opStack.empty()) //empty stack
    {
        this->parsed.push_back(opStack.front());
        opStack.pop_front();
    }
}
void rpnParser::parseToOps(string equation)
{
    string buildToken;
    for (size_t index = 0; index < equation.size(); index++)
    {
        switch (equation[index])
        {
        case '^':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first repeted but some cases use build token
            buildToken = "";
            this->parsed.push_back(PowOP);
            continue;
            break;
        case '*':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            this->parsed.push_back(MultOP);
            continue;
            break;
        case '/':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            this->parsed.push_back(DividOP);
            continue;
            break;
        case '%':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            this->parsed.push_back(ModOP);
            continue;
            break;
        case '+':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            this->parsed.push_back(AddOP);
            continue;
            break;
        case '-':
            if (buildToken.size() > 0 || this->parsed.back().code <= 0)  //if the previous was a number than is subtraction not negative
            { 
                this->parsed.push_back(findOp(buildToken)); //empty build token first
                buildToken = "";
                this->parsed.push_back(SubOP);
                continue;
            } else
            {
                //just let it continue to end of loop to build number
            }
            break;
        case '<': //also test <=
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            if (equation[index+1] != '=')
            {
                this->parsed.push_back(LessOP);
                continue;
            } else {
                index++; //consume =
                this->parsed.push_back(LessOrOP);
                continue;
            }
            break;
        case '>': //also test >=
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            if (equation[index+1] != '=')
            {
                this->parsed.push_back(GreatOP);
                continue;
            } else {
                index++; //consume =
                this->parsed.push_back(GreatOrOP);
                continue;
            }
            break;
        case '=': //should be ==? or maybe just keep as = sice there is no assinment operator
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            if (equation[index+1] == '=')
            {
                index++; //consume extra =
            }
            this->parsed.push_back(EqualOP);
            continue;
            break;
        case '&': //also test for &&
            if (equation[index+1] != '&')
            {
                op ref = RefOP;             
                ref.value = getRefIndex(buildToken);
                this->parsed.push_back(ref);
                buildToken = "";
                continue;
            } else {
                if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
                buildToken = "";
                index++; //consume &
                this->parsed.push_back(AndOP);
                continue;
            }
            break;
        case '|': //should be ||
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first
            buildToken = "";
            if (equation[index+1] == '|')
            {
                index++; //consume |
            }
            this->parsed.push_back(OrOP);
            continue;
            break;
        case '(':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first repeted but some cases use build token
            buildToken = "";
            this->parsed.push_back(LParenOP);
            continue;
            break;
        case ')':
            if (buildToken.size() > 0) { this->parsed.push_back(findOp(buildToken)); } //empty build token first repeted but some cases use build token
            buildToken = "";
            this->parsed.push_back(RParenOP);
            continue;
            break;
        default:
            break;
        }
        buildToken += equation[index];
    }
    
}
op rpnParser::findOp(string token) //mainly for finding non reserved char ops, and identifying numbers
{
    if (token == "max")
    {
        return MaxOP;
    }
    if (token == "min")
    {
        return MinOP;
    }
    if (token == "abs")
    {
        return AbsOP;
    }
    
    if (isdigit(token[0])) //if first is number then SHOULD be number
    {
        op number = NumOP;
        number.value = stoi(token);
        return number;
    }
    cout << "you shouldn't be here...\nether you forgot to indicate a ref with &, or you did some dumb shit\n";
    //should not be here I'll acomidate the user with refs... but you're on thin ice here missy
    if (token.size() > 1)
    {
        op thinIceMissy = RefOP;
        thinIceMissy.value = getRefIndex(token);
        return thinIceMissy;
    }
    cout << "NO!";
    exit(6);
}
int8_t rpnParser::getRefIndex(string token)
{
    for (int8_t index = 0; index < (*refernces).size(); index++)
    {
        if((*refernces)[index].name == token)
        {
            return index;
        }
    }
    cout << "hey dummy, that refrence doesn't exist\n";
    exit(7);
}