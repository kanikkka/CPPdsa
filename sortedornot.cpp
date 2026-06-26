#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr)) {
        cout << "Array is Sorted";
    } else {
        cout << "Array is Not Sorted";
    }

    return 0;
}