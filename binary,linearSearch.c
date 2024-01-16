// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>



int linearSearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
       if(arr[i]==element){
           return i;
       }
       return -1;
    }
}

int binarySearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}
int main() {
   int arr[7]={1,2,6,5,43,7,8};
   binarySearch(arr[],7,43);

    return 0;
}
