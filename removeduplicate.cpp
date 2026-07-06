#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5};

    int n = arr.size();

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    cout << "Array after removing duplicates: ";

    for (int k = 0; k <= i; k++) {
        cout << arr[k] << " ";
    }

    return 0;
}