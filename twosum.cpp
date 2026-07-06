#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, target;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int need = target - arr[i];

        if (mp.find(need) != mp.end()) {
            cout << "Pair found at index " << mp[need] << " and " << i;
            return 0;
        }

        mp[arr[i]] = i;
    }

    cout << "Pair not found";
    return 0;
}