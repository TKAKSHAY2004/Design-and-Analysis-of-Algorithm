#include <stdio.h>

int linear(int a[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (a[i] == val)
            return i + 1;
    }
    return -1;
}

int main() {
    int a[5]; // Change size to 5
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; ++i) { // Correct loop condition
        scanf("%d", &a[i]); // Removed space
    }
    int val;
    printf("Enter the value need to be searched: ");
    scanf("%d", &val);
    int n = sizeof(a) / sizeof(a[0]);
    int res = linear(a, n, val);
    printf("Elements:\n");
    for (int i = 0; i < 5; i++) { // Print only entered elements
        printf("%d\t", a[i]);
    }
    printf("\nElement searched: %d\n", val); // Changed wording
    if (res == -1) {
        printf("Element is not found");
    } else {
        printf("Element found at position: %d\n", res);
    }

    return 0;
}


*/output:
Enter 5 integers: 5 4 7 8 1
Enter the value need to be searched: 8
Elements:
5	4	7	8	1	
Element searched: 8
Element found at position: 4
*/
