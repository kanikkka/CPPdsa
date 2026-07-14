#include <iostream>
#include <vector>
using namespace std;

int searchRotatedArray(
    vector<int>& arr,
    int target
) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // Left part sorted hai
        if (arr[low] <= arr[mid]) {

            if (arr[low] <= target &&
                target < arr[mid]) {

                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right part sorted hai
        else {
            if (arr[mid] < target &&
                target <= arr[high]) {

                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int index = searchRotatedArray(arr, target);

    if (index == -1) {
        cout << "Target not found";
    }
    else {
        cout << "Target found at index: " << index;
    }

    return 0;
}