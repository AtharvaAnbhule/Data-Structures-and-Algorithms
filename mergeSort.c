// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void merge(int A[],int mid,int low,int high){
    int i,j,k;
    int B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
        while(i<=mid){
            B[k]=A[i];
            k++;
            i++;
        }
        while(j<=high){
            B[k]=A[j];
            k++;
            j++;
        }
        for(int i=low;i<=high;i++){
            A[i]=B[i];
        }
    }
}

void MS(int A[],int low,int high){
    int mid;
    if(low<=high){
        mid=(high+low)/2;
        MS(A,low,mid);
        MS(A,mid+1,high);
        merge(A,mid,low,high);
    }
}
void display(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }
}

int main() {
    // Write C code here
    int A[5]={5,3,9,1,3};
    display(A,5);
    MS(A,0,4);
    display(A,5);

    return 0;
}
