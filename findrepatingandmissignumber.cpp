#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMissingRepeating(
    vector<int>& arr
) {
    long long n = arr.size();

    long long expectedSum =
        n * (n + 1) / 2;

    long long expectedSquareSum =
        n * (n + 1) * (2 * n + 1) / 6;

    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (long long num : arr) {
        actualSum += num;
        actualSquareSum += num * num;
    }

    long long difference =
        actualSum - expectedSum;

    long long squareDifference =
        actualSquareSum - expectedSquareSum;

    long long sumOfNumbers =
        squareDifference / difference;

    long long repeating =
        (difference + sumOfNumbers) / 2;

    long long missing =
        sumOfNumbers - repeating;

    return {
        (int)repeating,
        (int)missing
    };
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

    pair<int, int> answer =
        findMissingRepeating(arr);

    cout << "Repeating number: "
         << answer.first << endl;

    cout << "Missing number: "
         << answer.second;

    return 0;
}