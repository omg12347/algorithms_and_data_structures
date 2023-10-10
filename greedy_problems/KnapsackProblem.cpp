#include <iostream>
using namespace std;

// Function to calculate the maximum of two integers
int maximum(int x, int y) {
    return (x > y) ? x : y;
}

// Function to solve the 0/1 Knapsack problem
int knapSack(int capacity, int weights[], int values[], int n) {
    int i, wt;
    int K[n + 1][capacity + 1];

    // Build a table K[][] to store the maximum value for each subproblem
    for (i = 0; i <= n; i++) {
        for (wt = 0; wt <= capacity; wt++) {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (weights[i - 1] <= wt)
                K[i][wt] = maximum(values[i - 1] + K[i - 1][wt - weights[i - 1]], K[i - 1][wt]);
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[n][capacity];
}

int main() {
    cout << "Enter the number of items in the Knapsack: ";
    int n, capacity;
    cin >> n;

    int values[n], weights[n];

    // Input values and weights for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i << ": ";
        cin >> values[i];
        cin >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Calculate and display the maximum value that can be obtained
    int maxValue = knapSack(capacity, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
