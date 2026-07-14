#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinimum(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    int answer = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Current part already sorted hai
        if (arr[low] <= arr[high]) {
            answer = min(answer, arr[low]);
            break;
        }

        // Left part sorted hai
        if (arr[low] <= arr[mid]) {
            answer = min(answer, arr[low]);
            low = mid + 1;
        }

        // Right part sorted hai
        else {
            answer = min(answer, arr[mid]);
            high = mid - 1;
        }
    }

    return answer;
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

    cout << "Minimum element: "
         << findMinimum(arr);

    return 0;
}