#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int> &arr) {
    vector<int> ans;

    if (arr.size() == 0)
        return ans;

    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}