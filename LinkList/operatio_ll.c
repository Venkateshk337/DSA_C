#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Insert the node at beginning
struct node* insertAtBeginning(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return ptr;
}

// Insert the node at between
struct node* insertNodeBetween(struct node* head,int data,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p;
    p=head;
    int i=0;
    while(i<index-1){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}

// Insert at end and create node
struct node* insertAtEnd(struct node* head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
    }
    else{
        struct node *p=head;
        while(p->next !=NULL){
            p=p->next;
        }
        p->next=ptr;
    }
    return head;
}


// printing the element of Link List
void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//Delete between node
struct node* deleteBetween(struct node* head,int index){
    struct node *ptr,*p;
    int i=0;
    ptr=head;
    p=ptr->next;
    while(i<index-1){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return head;



}

// Delete last node
struct node* deleteLastNode(struct node* head){
    struct node *ptr,*p;
    p=head;
    ptr=p->next;
    while(ptr->next !=NULL){
        p=p->next;
        ptr=ptr->next;
    }
p->next=NULL;
free(ptr);

return head;

}

// deleting the haed
struct node* deleteHead(struct node *head){
    struct node *p,*ptr=head;
    p=head->next;
    head=p;
    return head;


}




int main(){
    struct node *head=NULL;

    head=insertAtEnd(head,12);
    head=insertAtEnd(head,123);
    head=insertAtBeginning(head,1);
    head=insertAtEnd(head,1234);
    head=insertAtEnd(head,12345);
    head=insertNodeBetween(head,35,1);
    traverse(head);
    printf("\nAfter the delete\n");
    head=deleteHead(head);
    head=deleteLastNode(head);
    head=deleteBetween(head,1);
    traverse(head);


}