#include <stdio.h>
int linear(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(a[i]== val)
            return i+1;

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
    scanf("%d",&val);
    int n = sizeof(a)/(sizeof(a[0]));
    int res = linear(a,n,val);
    printf("Elements:\n");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("Elements searched %d:\n",val);
    if (res== -1){
        printf("Element is not found");
    }else{
        printf("Elements found at %d\n",res);
    }

    return 0;
}
