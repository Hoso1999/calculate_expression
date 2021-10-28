#include "calculator.h"

void print_error(const char *msg)
{
    if (!msg)
        return ;
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

bool isValid(const char *exp)
{
    if (!exp || !*exp || !hasNumber(exp) || !isOnlyExpression(exp))
        return false;
    return true;
}

 char *parseExp(const char *exp)
{
    int len = 0;
    int i = -1;
    char *trim;
    while (exp[++i]) len += (isspace(exp[i])) ? 0 : 1;
    trim = (char *)calloc(len + 1, sizeof(char));
    i = -1;
    len = 0;
    while (exp[++i])
    {
        if (isspace(exp[i]))
            continue ;
        else
        {
            trim[len] = exp[i];
            ++len;
        }
    }
    return trim;
}

int main(void)
{
    printf("Put expression: ");
    char *exp = readline(stdin);
    if (!exp || !*exp)
        print_error("invalid expression");
    char *expression = parseExp(exp);
    // printf("exp: %s\n", expression);
    if (!isValid(expression) || !isValidSubExp(expression)|| !isBalancedBrackets(expression))
        print_error("invalid expression");
    ReaplaceAll(&expression);
    params res = evaluate(expression);
    if (floorl(res) == res)
        printf("result: %ld\n", (long)res);
    else
        printf("result: %Lf\n", res);
    memdel((void **)&exp);
    memdel((void **)&expression);
    return 0;
}