#include "calculator.h"

static void closeBracketPart(stack *values, stack *ops)
{
    while (!isEmpty(*ops) && *(char *)top(*ops) != '(')
    {
        params val2 = (top(*values) ? *(params *)top(*values) : 0);
        pop(values);

        params val1 = (top(*values) ? *(params *)top(*values) : 0);
        pop(values);

        char op = (top(*ops) ? *(char *)top(*ops) : '+');
        pop(ops);

        params push_val = doOperation(val1, val2, op);
        push(values, &push_val, sizeof(params));
    }
    if (!isEmpty(*ops))
        pop(ops);
}

static void operationsPart(stack *values, stack *ops, const char *exp, char *isMinus, int i)
{
    while (!isEmpty(*ops) && priority(*(char *)top(*ops)) >= priority(exp[i]))
    {
        params val2 = (top(*values) ? *(params *)top(*values) : 0);
        pop(values);

        params val1 = (top(*values) ? *(params *)top(*values) : 0);
        pop(values);

        char op = (top(*ops) ? *(char *)top(*ops) : '+');
        pop(ops);

        params push_val = doOperation(val1, val2, op);
        push(values, &push_val, sizeof(params));
    }
    char op = exp[i];

    if (!checkMinus(exp, i))
        push(ops, &op, sizeof(char));
    *isMinus = checkMinus(exp, i);
}

params evaluate(const char *expression)
{
    char    *exp = strdup(expression);
    char    isMinus = '\0';
    int     i = -1;
    stack   values = stackConstructor();
    stack   ops = stackConstructor();

    while (exp[++i])
    {
        if (exp[i] == '(')
            push(&ops, &exp[i], sizeof(char));
        else if (isdigit(exp[i]))
        {
            char *k = NULL;
            params val = strtold(exp + i, &k);

            if (isMinus == '-')
                val *= -1;
            if (!k)
                break ;
            i += strlen(exp + i) - strlen(k) - 1;
            push(&values, &val, sizeof(params));
        }
        else if (exp[i] == ')')
            closeBracketPart(&values, &ops);
        else
           operationsPart(&values, &ops, exp, &isMinus, i);
    }
    while (!isEmpty(ops))
    {
        params val2 = (top(values) ? *(params *)top(values) : 0);
        pop(&values);

        params val1 = (top(values) ? *(params *)top(values) : 0);
        pop(&values);

        char op = (top(ops) ? *(char *)top(ops) : '+');
        pop(&ops);

        params push_val = doOperation(val1, val2, op);
        push(&values, &push_val, sizeof(params));
    }
    params res = (top(values) ? *(params *)top(values) : 0);

    stackDestructor(&values);
    stackDestructor(&ops);
    memdel((void **)&exp);
    return res;
}