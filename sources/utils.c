#include "calculator.h"

char *readline(void)
{
    size_t csize = BUFFER_SIZE;
    size_t cpos = 0;
    char *str = malloc(BUFFER_SIZE);
    char c;
    while((c = fgetc(stdin)) != '\n' && c != '\r')
    {
        str[cpos] = c;
        ++cpos;
        if(cpos == csize)
        {
            csize += BUFFER_SIZE;
            str = realloc(str, csize);
        }
    }
    str[cpos] = '\0';
    return str;
}

bool isSignValid(const char *exp)
{
    int i = -1;
    while (exp[++i] && isspace(exp[i])) ;
    if (exp[i] && exp[i + 1] && (exp[i] == '-' || exp[i] == '+') && !isdigit(exp[i + 1]) && exp[i] != '(')
        return false;
    return true;
}

void vecstrdel(char ***vec)
{
    if (!vec || !*vec)
        return;
    int i = -1;
    while ((*vec)[++i])
       memdel((void **)&(*vec)[i]);
    free(*vec);
    *vec = NULL;
}