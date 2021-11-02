#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdarg.h>

typedef long double params;
#define BUFFER_SIZE 32
#define NEGARTHMSTR "+(-1)*"
#define InputCheck(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '.' || c == '(' || c == ')' || isdigit(c))

char**  split(const char *str, char *charset);
int     priority(char op);
params  doOperation(params a, params b, char op);
void    print_error(int len, ...);
void    skip(const char *str, int *i);
bool    matchingPair(char start, char end);
bool    isBalancedBrackets(char *exp);
char    checkMinus(const char *exp, int i);
bool    isnDoubleSign(const char *exp);
char*   readline(FILE * fp);
bool    isSignValid(const char *exp);
bool    isValid(const char *exp);
void    vecstrdel(char ***vec);
bool    hasNumber(const char *exp);
bool    isValidSubExp(const char *exp);
params  evaluate(const char *expression);
bool    isOnlyExpression(const char *exp);
int     findStr(char *str, char *needle, int n);
void    ReaplaceAll(char **str);



#endif