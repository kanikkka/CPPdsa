#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    int n, k;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    unordered_map<int, int> mp;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        if (mp.find(sum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    cout << "Longest Subarray Length = " << maxLen;

    return 0;
}