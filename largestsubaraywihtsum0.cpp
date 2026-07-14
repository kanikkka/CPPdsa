#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int largestZeroSumSubarray(vector<int>& arr) {
    unordered_map<long long, int> firstIndex;

    long long prefixSum = 0;
    int maximumLength = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maximumLength = i + 1;
        }

        if (firstIndex.find(prefixSum) !=
            firstIndex.end()) {

            int length = i - firstIndex[prefixSum];

            maximumLength =
                max(maximumLength, length);
        }
        else {
            firstIndex[prefixSum] = i;
        }
    }

    return maximumLength;
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

    cout << "Largest length: "
         << largestZeroSumSubarray(arr);

    return 0;
}