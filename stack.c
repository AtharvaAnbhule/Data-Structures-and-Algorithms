#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Not valid");
    }
    else{
        ptr->arr[ptr->top]=val;
        ptr->top++;
    }
}
void pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Not valid");
    }
    else{
       int val= ptr->arr[ptr->top];
        ptr->top--;
    }
}

int peek(struct stack *sp,int i){
    //top-i+1
    if(sp->top-i+1<0){
        printf("Invalid.");
    }
    else{
        return sp->arr[sp->top-i+1];
    }
}


void display(struct stack *sp){
    for(int i=-1;i<sp->top;i++){
        printf("%d",sp->arr[i]);
    }
}
int main(){
    struct stack *sp =(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    push(sp,7);
    push(sp,6);
    push(sp,9);
    display(sp);
    pop(sp);
    display(sp);
    return 0;
}
