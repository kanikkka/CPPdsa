#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a part of the array
void reverseArray(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate array left by d positions
void rotateArray(vector<int> &arr, int d) {
    int n = arr.size();

    // Agar d > n ho
    d = d % n;

    // Step 1: Reverse first d elements
    reverseArray(arr, 0, d - 1);

    // Step 2: Reverse remaining elements
    reverseArray(arr, d, n - 1);

    // Step 3: Reverse the whole array
    reverseArray(arr, 0, n - 1);
}

int main() {
    int n, d;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of rotations: ";
    cin >> d;

    rotateArray(arr, d);

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}