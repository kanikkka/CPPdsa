#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(
    vector<int>& arr,
    int low,
    int mid,
    int high
) {
    vector<int> temporary;

    int left = low;
    int right = mid + 1;

    long long inversionCount = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temporary.push_back(arr[left]);
            left++;
        }
        else {
            temporary.push_back(arr[right]);

            inversionCount += mid - left + 1;

            right++;
        }
    }

    while (left <= mid) {
        temporary.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temporary.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temporary[i - low];
    }

    return inversionCount;
}

long long mergeSort(
    vector<int>& arr,
    int low,
    int high
) {
    if (low >= high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += mergeAndCount(
        arr,
        low,
        mid,
        high
    );

    return count;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long answer =
        mergeSort(arr, 0, n - 1);

    cout << "Number of inversions: "
         << answer;

    return 0;
}