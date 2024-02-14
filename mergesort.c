#include <stdio.h>

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if (arr[j]<pivot){
            i++;
            Swap(arr[i],arr[j]);
        }
    }
    Swap(arr[i+1],arr[high]);
    return(i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",arr[i]);
    }
    quicksort(arr,0,size-1);
    printf("Sorted array:\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}


