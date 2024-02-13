#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
struct Node *insertAtBegining(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;

}
struct Node* insertInBetween(struct Node* head, int data,int node){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    int i=0;
    while(i<node-1){
p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
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
void traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* deleteAtBeginning(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node* deleteAtEnd(struct Node *head){
    struct Node *ptr=head;
    struct Node *q=ptr->next;
    while(q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    
    // printf("%d ",q->data);
    ptr->next=NULL;
    free(q);
    return head;

}

int main()
{
    struct Node *head = NULL;
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    head=insertAtBegining(head,10);
    head=insertInBetween(head,20,1);

    traverse(head);
    printf("\n After delete\n");
    head=deleteAtBeginning(head);
    head=deleteAtEnd(head);
    traverse(head);
    
}
