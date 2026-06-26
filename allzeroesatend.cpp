#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int>& arr) {
    int j = 0;   // Position for next non-zero element

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pushZerosToEnd(arr);

    cout << "Array after pushing zeros to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}