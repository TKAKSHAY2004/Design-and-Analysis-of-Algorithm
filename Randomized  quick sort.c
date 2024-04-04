#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the pivot element (last element in this case)
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to randomly choose a pivot element
int randomPartition(int arr[], int low, int high) {
    srand(time(NULL)); // Seed for random number generation
    int random = low + rand() % (high - low); // Generate a random index
    swap(arr[random], arr[high]); // Swap the random element with the last element
    return partition(arr, low, high); // Call the partition function
}

// Randomized Quick Sort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high); // Get the partitioning index
        randomizedQuickSort(arr, low, pi - 1); // Sort the left sub-array
        randomizedQuickSort(arr, pi + 1, high); // Sort the right sub-array
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
