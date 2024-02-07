#include <stdio.h>
int binary(int a[],int beg,int end,int val){
    int mid;
    if(end>-beg){
        mid = (end+beg)/2;
    }
    if(a[mid]==val){
        return mid+1;
    }
    else if(a[mid]<val){
        return binary(a,mid+1,end,val);
    }
    else{
        return binary(a,beg,mid+1,val);
    }
    return -1;
}

int main(){
    int a[9];
    printf("Enter 5 integers: ");
    for(int i = 0; i < 6; ++i) {
     scanf("%d ", &a[i]);
    }
    int val;
    printf("Enter the value need to be searched: ");
    scanf("%d ",&val);
    int n = sizeof(a)/(sizeof(a[0]));
    int res = binary(a,0,n-1,val);
    printf("Elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("Elements searched %d:\n",val);
    if (res== -1){
        printf("Element is not found");
    }else{
        printf("Elements found at %d\n",res);
    }

    return 0;
}

