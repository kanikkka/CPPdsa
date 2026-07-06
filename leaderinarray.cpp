#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> leaders;

    int maxi = arr[n - 1];
    leaders.push_back(maxi);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxi) {
            leaders.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(leaders.begin(), leaders.end());

    cout << "Leaders: ";
    for (int x : leaders) cout << x << " ";

    return 0;
}