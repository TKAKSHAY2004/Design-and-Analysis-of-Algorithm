#include<stdio.h>
void print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void bubble(int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void main(){
    int i,j,temp;
    int a[5]={10,65,23,7,57};
    int b[5]={10,65,23,7,57};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    printf("Before sorting array of elements\n");
    print(a,n);
    bubble(a,n);
    printf("\nAfter sorting array of elements  are\n");
    print(a,n);
}


/* Before sorting array of elements
10	65	23	7	57	
After sorting array of elements  are
7	10	23	57	65	*/
