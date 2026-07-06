#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxSum)
            maxSum = sum;

        if (sum < 0)
            sum = 0;
    }

    cout << "Maximum Subarray Sum = " << maxSum;

    return 0;
}