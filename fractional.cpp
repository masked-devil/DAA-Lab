#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // Value per unit weight
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (items[i].ratio * remainingCapacity);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i+1 << " (weight value): ";
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
