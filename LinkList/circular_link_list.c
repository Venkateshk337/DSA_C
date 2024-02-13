

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front, *rear;

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        ptr->next = ptr;
        head = ptr;
        front = head;
        rear = head;
    }
    else
    {
        // struct node *p = head;
        // while (p->next != head)
        // {
        //     p = p->next;
        // }
        rear->next = ptr;
        ptr->next = head;
        rear = ptr;
    }
    return head;
}

struct node *insertInBetween(struct node *head, int ind, int data)
{
    int i = 0;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    p->data = data;
    while (i < ind - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    // while (p->next != NULL)
    // {
    //     p = p->next;
    // }
    ptr->next = head;
    p->next = ptr;
    head = ptr;
    front = head;
    return head;
}

// delete head
struct node *deleteHead(struct node *head)
{
    if (front == rear)
    {
        head = front = rear = NULL;
    }
    else
    {
        struct node *ptr = head;
        front = front->next;
        rear->next=front;
        head = front;
        free(ptr);
    }
    return head;
}

struct node *deleteRear(struct node *head)
{
    if (front == rear)
    {
        head = front = rear = NULL;
    }
    else
    {
        struct node *p = head;
        struct node *ptr = p->next;

        while (ptr->next != head)
        {
            p = p->next;
            ptr = ptr->next;
        }

        p->next = rear->next;
        rear = p;
        free(ptr);
    }
    return head;
}

void traverse(struct node *head)
{
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        do
        {
            printf("%d-->", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("NULL\n");
    }
}

int main()
{
    struct node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertInBetween(head, 2, 5);
    traverse(head);
    printf("After delete:\n");
    head = deleteHead(head);
    head = deleteRear(head);
    traverse(head);
}