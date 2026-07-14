#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return first;
}

int findLast(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return last;
}

int countOccurrences(
    vector<int>& arr,
    int target
) {
    int first = findFirst(arr, target);

    if (first == -1) {
        return 0;
    }

    int last = findLast(arr, target);

    return last - first + 1;
}

int main() {
    int n, target;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    cout << "Total occurrences: "
         << countOccurrences(arr, target);

    return 0;
}