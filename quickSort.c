// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

int partition(int A[],int low,int high){
    int pivot=A[low];
    int temp;
    int i =low+1;
    int j =high;
    do{
        while(A[i]<=pivot){
            i++;
        }
       while(A[j]>pivot){
           j++;
       }
       if(i<j){
           temp=A[i];
           A[i]=A[j];
           A[j]=temp;
       }
       
    }
    while(i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
        
    
}

void quickSort(int A[] , int low , int high ){ 
    int partitionIndex; //index of pivot after partition
   if(low<high){
       partitionIndex = partition(A,low,high);
       quickSort(A,low,partitionIndex-1);
       quickSort(A,partitionIndex+1,high);
   }
        
    
    printf("Sorted!");
}



void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",A[i]);
    }
}

int main() {
    // Write C code here
    int A[5]={2,5,8,1,3};
    quickSort(A,0,1);
    display(A,5);
    return 0;
}
