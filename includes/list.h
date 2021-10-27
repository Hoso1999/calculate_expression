#ifndef LIST_H
#define LIST_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list list;
typedef struct Node Node;

struct Node
{
    void *data;
    Node *next;
};


struct list
{
    Node *head;
    int size;
};

list    listConstructor(void);
Node*   createNode(void *data, int size);
void    memdel(void **mem);
void    pop_front(list *lst);
void    push_front(list *lst, void *data, int size);
void    listDestructor(list *lst);

#endif