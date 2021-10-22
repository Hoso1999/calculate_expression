#include "calculate.h"

void vecstrdel(char ***str)
{
    int i = -1;
    if (!str || !*str)
        return ;
    while ((*str)[++i])
    {
        strdel(&(*str)[i]);
    }
    free(*str);
    *str = NULL;
}

char *strschr(char *str)
{
    while (str && *str)
    {
        if (*str == '+' || *str == '-')
            return str;
        ++str;
    }
    return NULL;
}

params getValue(const char *str)
{
    char *data = (char *)str;
    char *d;
    char sign;
    params res = strtold(data, &d);
    while (*d)
    {
        sign = shiftNext(&d);
        if (sign == '*')
            res *= strtold(d, &d);
        if (sign == '/')
            res /= strtold(d, &d);
    }
    return res;
}