#include <iostream>
#include <vector>
using namespace std;

int findRotationCount(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array is rotated "
         << findRotationCount(arr)
         << " times";

    return 0;
}