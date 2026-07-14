#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int answer = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
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

    int index = lowerBound(arr, target);

    if (index == n) {
        cout << "No element is greater than or equal to target";
    }
    else {
        cout << "Lower bound index: " << index << endl;
        cout << "Lower bound element: " << arr[index];
    }

    return 0;
}