#include<iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    int result = dp[n][capacity];
    int w = capacity;
    for (int i = n; i > 0 && result > 0; i--) {
        if (result == dp[i - 1][w])
            continue;    
        else {
            cout<<" "<<weights[i - 1] ;
            result = result - values[i - 1];
            w = w - weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], values[n];

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (weight value): ";
        cin >> weights[i] >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsack(weights, values, n, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
