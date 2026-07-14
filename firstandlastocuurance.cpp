#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(
    vector<int>& arr,
    int target
) {
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

int findLastOccurrence(
    vector<int>& arr,
    int target
) {
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

    int first = findFirstOccurrence(arr, target);
    int last = findLastOccurrence(arr, target);

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last;

    return 0;
}