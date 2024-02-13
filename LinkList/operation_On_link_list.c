#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

struct Node *insertAtBeginnig(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return ptr;
}

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

struct Node *deleteAtbegining(struct Node *head)
{
    struct Node *ptr = head;
    ptr = ptr->next;
    head = ptr;
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr, *p;
    ptr = head;
    p = ptr->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct Node *deleteInBetween(struct Node *head, int term)
{
    struct Node *ptr, *p;
    p = head;
    ptr = p->next;
    if (p->data == term)
    {
        head = p->next;
    }
    while (ptr->data != term && ptr != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        p->next = ptr->next;
    }
    else
    {
        return head;
    }
    free(ptr);
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginnig(head, 100);
    head = insertInBetween(head, 120, 2);
    traverse(head);
    printf("\nAfter Delete\n");
    head = deleteAtbegining(head);
    head = deleteAtEnd(head);
    head = deleteInBetween(head, 20);
    traverse(head);
}
