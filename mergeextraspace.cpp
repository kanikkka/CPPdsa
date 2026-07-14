#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArrays(
    vector<int>& arr1,
    vector<int>& arr2
) {
    int i = arr1.size() - 1;
    int j = 0;

    while (i >= 0 && j < arr2.size()) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);

            i--;
            j++;
        }
        else {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {
    int n;
    int m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter first sorted array:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter second sorted array:\n";

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    mergeArrays(arr1, arr2);

    cout << "First array: ";

    for (int num : arr1) {
        cout << num << " ";
    }

    cout << "\nSecond array: ";

    for (int num : arr2) {
        cout << num << " ";
    }

    return 0;
}