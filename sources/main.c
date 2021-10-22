#include "calculate.h"

params getExpression(char *str)
{
    char *data = str;
    params res = 0.0;
    params sum = 0.0;

    while (*data)
    {
        strtold(data, &data);
        shiftNext(&data);
    }
    data = str;
    data = calloc(strlen(str) + 4, sizeof(char));
    char st[4] = " + ";
    strncpy(data, st, 4);
    strcpy(data + 3, str);
    char ** adds = split(data, "+-");
    char *getSign = strschr(data);
    int i = -1;
    while (adds[++i])
    {
        sum = (adds[i + 1]) ? getValue(adds[i + 1]) : 0.0;
        sum *= (getSign && *getSign == '-') ? -1 : 1;
        res += sum;
        getSign = (getSign) ? strschr(getSign + 1) : NULL;
    }
    vecstrdel(&adds);
    strdel(&data);
    return res;
}


int main(int argc, char **argv)
{
    if (argc != 2)
        print_error("invalid arguments");
    if (isEmpty(argv[1]))
        print_error("string is empty");
    if (isSign(*argv[1]))
        print_error("expression is invalid");
    char *av = strdup(argv[1]);
    params nums = getExpression(argv[1]);
    printf("res: %Lf\n", nums);
    strcpy(argv[1], av);
    strdel(&av);
    return 0;
}