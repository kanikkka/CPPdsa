#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumProductSubarray(
    vector<int>& arr
) {
    long long maximumProduct = arr[0];
    long long minimumProduct = arr[0];

    long long answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        long long current = arr[i];

        if (current < 0) {
            swap(
                maximumProduct,
                minimumProduct
            );
        }

        maximumProduct =
            max(
                current,
                maximumProduct * current
            );

        minimumProduct =
            min(
                current,
                minimumProduct * current
            );

        answer =
            max(answer, maximumProduct);
    }

    return answer;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array cannot be empty";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum product: "
         << maximumProductSubarray(arr);

    return 0;
}