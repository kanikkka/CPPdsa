#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) cin >> price[i];

    int minPrice = price[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        int profit = price[i] - minPrice;

        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, price[i]);
    }

    cout << "Maximum profit: " << maxProfit;
    return 0;
}