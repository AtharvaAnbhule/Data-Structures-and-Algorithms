// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void insertionSort(int *A,int n){ // n is the size
    int i,j;
    int key;
    int isSorted =0;
    for(i=1;i<n-1;i++){ //for all the passes
           key=A[i];
           j=i-1;
           while(A[j]>key && j>=0){
               A[j+1]=A[j];
               j--;
           }
           A[j+1]=key;
    }
        
    
    printf("Sorted!");
}

void display(int *A,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",A[i]);
    }
}

int main() {
    // Write C code here
    int A[5]={2,5,8,1,3};
    insertionSort(&A,5);
    display(&A,5);
    return 0;
}
