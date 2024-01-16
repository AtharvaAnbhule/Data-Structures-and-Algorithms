// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
    
};

void createArray(struct myArray *a,int tsize,int usize){
    a->total_size=tsize;
    a->used_size=usize; 
    a->ptr = (int *) malloc(tsize*sizeof(int));
}

void show(struct myArray *a){
    for(int i=0;i<a->used_size;i++){
        printf("%d",(a->ptr)[i]);
    }
}
void setVal(struct myArray *a){
    for(int i=0;i<a->used_size;i++){
        printf("Enter the elements-:");
        scanf("%d\n",&(a->ptr)[i]);
    }
}

int insert(struct myArray *a,int usize,int element,int tsize,int index){
    if(usize>=tsize){
        return -1;
    }
    for(int i=tsize-1;i>=index;i--){
        (a->ptr)[i+1]=(a->ptr)[i];
    }
    (a->ptr)[index]=element;
    return 1;
}

int main() {
   struct myArray *n= (struct myArray *)malloc(sizeof(struct myArray));
   n->total_size=7;
   n->used_size=3;
   createArray(n,7,3);
   setVal(n);
   show(n);

    return 0;
}
