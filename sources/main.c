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
    if (!exp || !*exp || !hasNumber(exp) || !isOnlyExpression(exp) || !isSignValid(exp))
        return false;
    return true;
}

int main(void)
{
    printf("Put expression: ");
    char *exp = readline();
    if (!exp || !*exp)
        print_error("invalid expression");
    if (!isValidSubExp(exp) || !isValid(exp) || !isBalancedBrackets(exp))
        print_error("invalid expression");
    printf("result: %Lf\n", evaluate(exp));
    memdel((void **)&exp);
    return 0;
}