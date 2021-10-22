#ifndef CALCULATE_H
#define CALCULATE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

#define isSign(c) (c == '+' || c == '-' || c == '*' || c == '/')
#define SIGNS "+-*/"
typedef long double params;

void    print_error(const char *str);
bool    isEmpty(const char *str);
void    strdel(char **str);
char    shiftNext(char **str);
void    vecstrdel(char ***str);
char    *strschr(char *str);
params  getValue(const char *str);
char    **split(char *str, char *charset);

#endif