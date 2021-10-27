#include "list.h"

list    listConstructor(void)
{
    return (list){NULL, 0};
}

Node*   createNode(void *data, int size)
{
    if (size <= 0 || !data)
        return NULL;
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = malloc(size);
    memmove(node->data, data, size);
    return node;
}

void    memdel(void **mem)
{
    if (!mem || !*mem)
        return ;
    free(*mem);
    *mem = NULL;
}

void    pop_front(list *lst)
{
    Node *head = lst->head;
    if (!head)
        return ;
    lst->head = lst->head->next;
    memdel((void **)&head->data);
    memdel((void **)&head);
    --lst->size;
}

void    push_front(list *lst, void *data, int size)
{
    Node *head = lst->head;
    if (!head)
    {
        lst->head = createNode(data, size);
    }
    else
    {
        lst->head = createNode(data, size);
        lst->head->next = head;
    }
    ++lst->size;
}

void    listDestructor(list *lst)
{
    Node *head = lst->head;
    Node *next = NULL;

    while (head)
    {
        next = head->next;
        memdel((void **)&head->data);
        memdel((void **)&head);
        head = next;
    }
    lst->head = NULL;
}