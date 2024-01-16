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

struct node *deletefirst(struct node *head){
    struct node *ptr =head;
    head=head->next;
    free(ptr);
    return head;
    
}
struct node *deleteatindex(struct node *head , int index){
    struct node *q=head->next;
    struct node *p =head;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

int main(){
    struct node *head =(struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=NULL;
    deleteatindex(head,2);
    deletefirst(head);
    traversal(head);
    return 0;
}
