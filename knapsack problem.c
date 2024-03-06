#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }

        }

    }
    return dp[n][W];
}
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int weights[n];
    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    int values[n];
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    cout << "Enter the knapsack capacity: ";
    cin >> W;
    int result = knapsack(W, weights, values, n);
    cout << "Maximum value in the knapsack: " << result << endl;
    return 0;

}

/*
Enter the number of items: 4
Enter the weights of items: 2 3 1 4
Enter the values of items: 5 2 8 6
Enter the knapsack capacity: 5
Maximum value in the knapsack: 14 */
