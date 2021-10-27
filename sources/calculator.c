#include "calculator.h"

bool isOnlyExpression(const char *exp)
{
    int i = -1;
    while (exp[++i])
    {
        if (!InputCheck(exp[i]))
            return false;
    }
    return true;
}

bool hasNumber(const char *exp)
{
    int i = -1;
    while (exp[++i])
        if (isdigit(exp[i]))
            return true;
    return false;
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

params doOperation(params a, params b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

bool isValidSubExp(const char *exp)
{
    char **sp = split(exp, "()");
    if (!strcmp(exp, sp[0]))
    {
        vecstrdel(&sp);
        if(!isnDoubleSign(exp))
            return false;
        return true;
    }
    int i = -1;
    int j;
    while (sp[++i])
    {
        j = 0;
        while (sp[i][j] && isspace(sp[i][j])) ++j;
        if (sp[i][j] && (sp[i][j] == '+' || sp[i][j] == '-' || sp[i][j] == '*' || sp[i][j] == '/'))
            ++j;
        if (sp[i][j] && (sp[i][j] == '+' || sp[i][j] == '-' || sp[i][j] == '*' || sp[i][j] == '/'))
            print_error("invalid expression");
        if (!isnDoubleSign(sp[i] + j))
        {
            vecstrdel(&sp);
            return false;
        }
    }
    vecstrdel(&sp);
    return true;
}