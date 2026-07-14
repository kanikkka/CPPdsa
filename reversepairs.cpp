#include <iostream>
#include <vector>
using namespace std;

long long countPairs(
    vector<int>& arr,
    int low,
    int mid,
    int high
) {
    int right = mid + 1;

    long long count = 0;

    for (int i = low; i <= mid; i++) {
        while (
            right <= high &&
            (long long)arr[i] >
            2LL * arr[right]
        ) {
            right++;
        }

        count += right - (mid + 1);
    }

    return count;
}

void mergeArray(
    vector<int>& arr,
    int low,
    int mid,
    int high
) {
    vector<int> temporary;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temporary.push_back(arr[left]);
            left++;
        }
        else {
            temporary.push_back(arr[right]);
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

    count += countPairs(
        arr,
        low,
        mid,
        high
    );

    mergeArray(
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

    cout << "Number of reverse pairs: "
         << answer;

    return 0;
}