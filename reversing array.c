#include <stdio.h>

void reverse(int *arr, int LENGTH) {
    int start = 0, end = LENGTH - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int LENGTH;
    scanf("%d", &LENGTH);

    int arr[LENGTH];

    for (int i = 0; i < LENGTH; i++) {
        scanf("%d", &arr[i]);
    }
    
    reverse(arr, LENGTH);

    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
