#include "calculator.h"

static void closeBracketPart(stack *values, stack *ops)
{
    while (!isEmpty(*ops) && *(char *)top(*ops) != '(')
    {
        params val2 = *(params *)top(*values);
        pop(values);
        params val1 = *(params *)top(*values);
        pop(values);
        char op = *(char *)top(*ops);
        pop(ops);
        params push_val = doOperation(val1, val2, op);
        push(values, &push_val, sizeof(params));
    }
    if (!isEmpty(*ops))
        pop(ops);
}

static void operationsPart(stack *values, stack *ops, const char *exp, bool *isMinus, int i)
{
    while (!isEmpty(*ops) && priority(*(char *)top(*ops)) >= priority(exp[i]))
    {
        params val2 = *(params *)top(*values);
        pop(values);
        params val1 = *(params *)top(*values);
        pop(values);
        char op = *(char *)top(*ops);
        pop(ops);
        params push_val = doOperation(val1, val2, op);
        push(values, &push_val, sizeof(params));
    }
    char op = exp[i];
    if (checkMinus(exp, i))
        push(ops, &op, sizeof(char));
    *isMinus = checkMinus(exp, i);
}

params evaluate(const char *expression)
{
    char *exp = strdup(expression);
    int i = -1;
    stack values = stackConstructor();
    stack ops = stackConstructor();
    bool isMinus = true;
    while (exp[++i])
    {
        if (isspace(exp[i]))
            continue ;
        else if (exp[i] == '(')
            push(&ops, &exp[i], sizeof(char));
        else if (isdigit(exp[i]))
        {
            params val = strtold(exp + i, NULL);
            if (!isMinus)
                val *= -1;
            skip(exp, &i);
            push(&values, &val, sizeof(params));
            --i;
        }
        else if (exp[i] == ')')
            closeBracketPart(&values, &ops);
        else
           operationsPart(&values, &ops, exp, &isMinus, i);
    }
    while (!isEmpty(ops))
    {
        params val2 = *(params *)top(values);
        pop(&values);
        params val1 = *(params *)top(values);
        pop(&values);
        char op = *(char *)top(ops);
        pop(&ops);
        params push_val = doOperation(val1, val2, op);
        push(&values, &push_val, sizeof(params));
    }
    params res = *(params *)top(values);
    stackDestructor(&values);
    stackDestructor(&ops);
    memdel((void **)&exp);
    return res;
}