// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void bubbleSort(int *A,int n){ // n is the size
    int i,j;
    int temp;
    int isSorted =0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
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
    bubbleSort(&A,5);
    display(&A,5);
    return 0;
}
