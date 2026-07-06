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

    int index = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(arr.begin(), arr.end());
    }
    else {
        for (int i = n - 1; i > index; i--) {
            if (arr[i] > arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        reverse(arr.begin() + index + 1, arr.end());
    }

    cout << "Next permutation: ";
    for (int x : arr) cout << x << " ";

    return 0;
}