#include "calculate.h"

void print_error(const char *str)
{
    write(STDERR_FILENO, str, strlen(str));
    write(STDERR_FILENO, "\n", 1);
    exit(1);
}

bool isEmpty(const char *str)
{
    while (str && *str)
    {
        if (!isspace(*str))
            return false;
        ++str;
    }
    return true;  
}

void strdel(char **str)
{
    if (!str || !*str)
        return ;
    free(*str);
    *str = NULL;
}

char shiftNext(char **str)
{
    char sign = '\0';
    while (**str && isspace(**str)) ++(*str);
    if (**str && !isSign(**str))
        print_error("argument is invalid");
    if (**str && *(*str + 1) && isSign(**str) && isSign(*(*str + 1)))
        print_error("argument is invalid");
    if (**str && isSign(**str))
    {
        sign = **str;
        ++(*str);
        while (**str && isspace(**str)) ++(*str);
        if (**str && isSign(**str))
            print_error("argument is invalid");
    }
    while (**str && isspace(**str)) ++(*str);
    return sign;
}
