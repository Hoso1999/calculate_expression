#ifndef STACK_H
#define STACK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

typedef struct stack stack;


struct stack
{
    list values;
};

stack   stackConstructor(void);
void    push(stack *st, void *data, int size);
void    pop(stack *st);
void*   top(stack st);
bool    isEmpty(stack st);
void    stackDestructor(stack *st);


#endif