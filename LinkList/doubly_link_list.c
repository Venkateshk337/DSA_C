#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Space not allocated");
    }
    else
    {
        temp->next = NULL;
        temp->data = data;
        if (head == NULL)
        {
            temp->pre = NULL;
            head = temp;
        }
        else
        {

            struct node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->pre = ptr;
        }
    }
    return head;
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->pre = NULL;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    return temp;
}
struct node *insertInBetween(struct node *head, int data, int index)
{
    struct node *ptr, *p;
    ptr = head;
    p = ptr->next;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = p;
    temp->data = data;
    temp->pre = ptr;
    ptr->next = temp;
    p->pre = temp;
    return head;
}

// delete head
struct node *deleteHead(struct node *head)
{
    if (head->next == NULL)
    {
        printf("Head can't delete\n");
    }
    else
    {
        struct node *ptr = head;
        ptr = ptr->next;
        ptr->pre = NULL;
        head = ptr;
        // free(ptr);
    }
    return head;
}

// delete rear
struct node *deleteRear(struct node *head)
{
    struct node *ptr = head;
    struct node *p = ptr->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    if (p->pre == NULL)
    {
        printf("Rear end can't delete");
    }
    else
    {
        ptr->next = NULL;
        free(p);
    }
    return head;
}

//delete the between the list
struct node* deleteBetween(struct node *head,int index){
    struct node* ptr=head;
    int i=0;
    while(i<index && ptr!=NULL){
        ptr=ptr->next;
        i++;
    }
    if(ptr==NULL || ptr->next==NULL){
        printf("Node can't be delete\n");
    }
    else{
ptr->pre->next=ptr->next;
ptr->next->pre=ptr->pre;
free(ptr);
    }
    return head;
}



void traverseFront(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void traverseBack(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->pre;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 12);
    head = insertAtBeginning(head, 30);
    head = insertInBetween(head, 40, 3);
    traverseFront(head);
    traverseBack(head);
    printf("After delete\n");
    head = deleteHead(head);
    // head = deleteRear(head);
    head=deleteBetween(head,2);
    traverseFront(head);
    traverseBack(head);
}