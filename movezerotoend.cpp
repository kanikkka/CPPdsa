#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 0, 2, 0, 3, 4, 0, 5};

    int j = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "Array after moving zeros to end: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}