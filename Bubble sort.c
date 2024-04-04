#include<stdio.h>

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}

void bubble(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Before sorting array of elements\n");
    print(a, n);

    bubble(a, n);

    printf("\nAfter sorting array of elements\n");
    print(a, n);

    return 0;
}
