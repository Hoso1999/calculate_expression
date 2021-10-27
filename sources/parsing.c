#include "calculator.h"

void skip(const char *str, int *i)
{
    while (str[*i] && isdigit(str[*i])) ++(*i);
    if (str[*i] && str[*i] != '.')
        return ;
    if (str[*i] && str[*i + 1] && str[*i] == '.' && str[*i + 1] == '.')
        print_error("invalid expression");
    ++(*i);
    while (str[*i] && isdigit(str[*i])) ++(*i);
}

bool matchingPair(char start, char end)
{
    if (start == '(' && end == ')')
        return true;
    return false;
}

bool isBalancedBrackets(char *exp)
{
    stack st = stackConstructor();
    int i = -1;
    while (exp[++i])
    {
        if (exp[i] == '(')
            push(&st, &exp[i], sizeof(char));
        if (exp[i] == ')')
        {
            if (isEmpty(st))
                return false;
            char bracket = *(char *)top(st);
            pop(&st);
            if (!matchingPair(bracket, exp[i]))
            {
                stackDestructor(&st);
                return false;
            }
        }
    }
    if (isEmpty(st))
        return true;
    stackDestructor(&st);
    return false;
}

bool checkMinus(const char *exp, int i)
{
    while(--i != -1)
    {
        if(isspace(exp[i]))
            continue;
        if(exp[i] == '(')
            return false;
        if(exp[i] == ')' || isdigit(exp[i]))
            return true;   
    }
    return false;
}

bool isnDoubleSign(const char *exp)
{
    int i = 0;
    while (exp[i] && isspace(exp[i])) ++i;
    if (exp[i] && exp[i] == '-') ++i;
    if (exp[i] && (exp[i] == '-' || !isdigit(exp[i]))) return false;
    skip(exp, &i);
    while (exp[i] && isspace(exp[i])) ++i;
    if (exp[i] && isdigit(exp[i]))
        print_error("invalid expression");
    if (exp[i] && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
        ++i;
    while (exp[i] && isspace(exp[i])) ++i;
    if (exp[i] && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
        return false;
    skip(exp, &i);
    while (exp[i] && isspace(exp[i])) ++i;
    if (exp[i] && isdigit(exp[i]))
        print_error("invalid expression");
    return true;
}