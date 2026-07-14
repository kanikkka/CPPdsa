#include <iostream>
#include <vector>
using namespace std;

bool searchRotatedArray(
    vector<int>& arr,
    int target
) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[low] == arr[mid] &&
            arr[mid] == arr[high]) {

            low++;
            high--;
            continue;
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

    return false;
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

    bool found = searchRotatedArray(arr, target);

    if (found) {
        cout << "Target is present";
    }
    else {
        cout << "Target is not present";
    }

    return 0;
}