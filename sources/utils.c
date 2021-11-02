#include "calculator.h"

char *readline(FILE *fp)
{
    size_t  size = BUFFER_SIZE;
    size_t  pos = 0;
    char    *line = (char *)malloc(BUFFER_SIZE * sizeof(char));
    char    c;

    while((c = fgetc(fp)) != '\n' && c != '\r' && c != EOF)
    {
        line[pos] = c;
        ++pos;
        if(pos == size)
        {
            size += BUFFER_SIZE;
            line = (char *)realloc(line, size);
        }
    }
    line[pos] = '\0';
    return line;
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