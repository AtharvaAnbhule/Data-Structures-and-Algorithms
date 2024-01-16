#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

struct node *insertbeg(struct node *head,int data){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr->next =head;
    ptr->data =data;
    head=ptr;
    return ptr;
    
}
struct node *insertatindex(struct node *head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p =head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return ptr;
}

int main(){
    struct node *head =(struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=NULL;
    insertatindex(head,8,2);
    insertbeg(head,5);
    traversal(head);
    return 0;
}
