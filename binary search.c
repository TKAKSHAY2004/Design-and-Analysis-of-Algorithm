#include <stdio.h>

int binary(int a[], int beg, int end, int val) {
    if (beg <= end) {
        int mid = beg + (end - beg) / 2; // Calculate mid index
        if (a[mid] == val) {
            return mid + 1;
        } else if (a[mid] < val) {
            return binary(a, mid + 1, end, val);
        } else {
            return binary(a, beg, mid - 1, val);
        }
    }
    return -1; // Element not found
}

int main() {
    int a[5]; // Change size to 5
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &a[i]);
    }
    int val;
    printf("Enter the value need to be searched: ");
    scanf("%d", &val);
    int n = sizeof(a) / sizeof(a[0]);
    int res = binary(a, 0, n - 1, val);
    printf("Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nElement searched: %d\n", val);
    if (res == -1) {
        printf("Element is not found\n");
    } else {
        printf("Element found at position: %d\n", res);
    }

    return 0;
}


*/
Enter 5 integers: 4 5 8 1 7
Enter the value need to be searched: 4
Elements: 4 5 8 1 7 
Element searched: 4
Element found at position: 1

*/
