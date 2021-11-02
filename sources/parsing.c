#include "calculator.h"

void skip(const char *str, int *i)
{
    while (str[*i] && isdigit(str[*i])) ++(*i);
    if (str[*i] && str[*i] != '.') return ;
    if (str[*i] && str[*i + 1] && str[*i] == '.' && str[*i + 1] == '.')
        print_error(1, "invalid expression");
    ++(*i);
    while (str[*i] && isdigit(str[*i])) ++(*i);
}

bool matchingPair(char start, char end)
{
    if (start == '(' && end == ')') return true;
    return false;
}

bool isBalancedBrackets(char *exp)
{
    stack   st = stackConstructor();
    int     i = -1;

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

char checkMinus(const char *exp, int i)
{
    int index = i;

    while(--i != -1)
    {
        if(exp[i] == '(')
            return exp[index];
        if(exp[i] == ')' || isdigit(exp[i]))
            return '\0';
    }
    return exp[index];
}

bool isnDoubleSign(const char *exp)
{
    int i = 0;

    if (exp[i] && (exp[i] == '-' || exp[i] == '+')) ++i;
    if (exp[i] && (exp[i] == '-' || exp[i] == '+' || !isdigit(exp[i]))) return false;
    skip(exp, &i);
    if (exp[i] && isdigit(exp[i]))
        return false;
    if (exp[i] && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
        ++i;
    if (exp[i] && (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'))
        return false;
    skip(exp, &i);
    if (exp[i] && isdigit(exp[i]))
        return false;
    return true;
}
