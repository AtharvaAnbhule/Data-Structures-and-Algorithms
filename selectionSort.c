// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void selectionSort(int *A,int n){ // n is the size
    int indexofMin;
    int temp;
    int isSorted =0;
    for(int i=0;i<n-1;i++){ //for all the passes
          indexofMin=i;
          for(int j=i+1;j<n;j++){
              if(A[j]<A[indexofMin]){
                  indexofMin=j;
              }
          }
          //swapping A[i] and A[indexofMin];
          temp=A[i];
          A[i]=A[indexofMin];
          A[indexofMin]=temp;
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
    selectionSort(&A,5);
    display(&A,5);
    return 0;
}
