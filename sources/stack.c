#include "stack.h"

stack   stackConstructor(void)
{
    return (stack){listConstructor()};
}

void    push(stack *st, void *data, int size)
{
    push_front(&st->values, data, size);
}

void    pop(stack *st)
{
    pop_front(&st->values);
}

void*   top(stack st)
{
    if (isEmpty(st))
        return NULL;
    return st.values.head->data;
}

bool    isEmpty(stack st)
{
   return (!st.values.size);
}

void    stackDestructor(stack *st)
{
    listDestructor(&st->values);
}

void printStack(stack st, bool isSign)
{
    if (isSign)
    {
        while (!isEmpty(st))
        {
            char s = *(char *)top(st);
            printf("%c ", s);
            pop(&st);
        }
        printf("\n");   
    }  
    else
    {
        while (!isEmpty(st))
        {
            long double num = *(long double *)top(st);
            printf("%Lf ", num);
            pop(&st);
        }
        printf("\n");   
    }
}