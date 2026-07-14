#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findFloorAndCeil(
    vector<int>& arr,
    int target
) {
    int low = 0;
    int high = arr.size() - 1;

    int floorValue = -1;
    int ceilValue = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            floorValue = arr[mid];
            ceilValue = arr[mid];
            return {floorValue, ceilValue};
        }
        else if (arr[mid] < target) {
            floorValue = arr[mid];
            low = mid + 1;
        }
        else {
            ceilValue = arr[mid];
            high = mid - 1;
        }
    }

    return {floorValue, ceilValue};
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

    pair<int, int> answer =
        findFloorAndCeil(arr, target);

    cout << "Floor: " << answer.first << endl;
    cout << "Ceil: " << answer.second;

    return 0;
}