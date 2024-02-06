#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,j,i,temp;
    int arr[64];
    printf("Enter no.of elements: ");
    scanf("%d",&n);
    
    printf("Enter %d integers\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
    printf("Sorted list in ascending order:\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);  
    }
    return 0;
}



/*
Enter no.of elements: 5
Enter 5 integers
2 1 6 3 8
Sorted list in ascending order:
1	2	3	6	8	  */
