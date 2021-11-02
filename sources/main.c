#include "calculator.h"

void print_error(int len, ...)
{
    va_list lst;
    int i = 0;

    va_start(lst, len);
    while (i < len)
    {
        const char *msg = va_arg(lst, const char *);
        if (!msg)
            return ;
        fprintf(stderr, "%s", msg);
        ++i;
    }
    fprintf(stderr, "\n");
    va_end(lst);
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

    while (exp[++i]) len += (isspace(exp[i])) ? 0 : 1;
    char *trim = (char *)calloc(len + 1, sizeof(char));

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

int main(int argc, char **argv)
{
    if (argc > 3)
        print_error(1, "invalid arguments");
    if (argc == 1)
        printf("Enter the expression: ");

    FILE *in = (argv[1]) ? fopen(argv[1], "r") : stdin;

    if (!in)
        print_error(4, "<", argv[1], ">", " file is not exists");

    FILE *out = (argc > 1 && argv[2]) ? fopen(argv[2], "w") : stdout;

    if (!out)
        print_error(4, "<", argv[2], ">", " file error");

    char *exp = readline(in);

    if (!exp || !*exp)
        print_error(1, "invalid expression");

    char *expression = parseExp(exp);

    if (!isValid(expression) || !isValidSubExp(expression)|| !isBalancedBrackets(expression))
        print_error(1, "invalid expression");
    ReaplaceAll(&expression);

    params res = evaluate(expression);

    if (floorl(res) == res)
        fprintf(out, "result: %ld\n", (long)res);
    else
        fprintf(out, "result: %Lg\n", res);
    fclose(in);
    fclose(out);
    memdel((void **)&exp);
    memdel((void **)&expression);
    return 0;
}