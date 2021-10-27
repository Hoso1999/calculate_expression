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