#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> answer;

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long sum =
                (long long)arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                answer.push_back(
                    {arr[i], arr[left], arr[right]}
                );

                left++;
                right--;

                while (left < right &&
                       arr[left] == arr[left - 1]) {
                    left++;
                }

                while (left < right &&
                       arr[right] == arr[right + 1]) {
                    right--;
                }
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return answer;
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

    vector<vector<int>> answer = threeSum(arr);

    if (answer.empty()) {
        cout << "No triplet found";
    }
    else {
        cout << "Triplets are:\n";

        for (vector<int>& triplet : answer) {
            cout << triplet[0] << " "
                 << triplet[1] << " "
                 << triplet[2] << endl;
        }
    }

    return 0;
}