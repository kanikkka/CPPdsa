#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(
    vector<int>& arr,
    int target
) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> answer;

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum =
                    (long long)arr[i] +
                    arr[j] +
                    arr[left] +
                    arr[right];

                if (sum == target) {
                    answer.push_back(
                        {
                            arr[i],
                            arr[j],
                            arr[left],
                            arr[right]
                        }
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
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return answer;
}

int main() {
    int n;
    int target;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> answer =
        fourSum(arr, target);

    if (answer.empty()) {
        cout << "No quadruplet found";
    }
    else {
        cout << "Quadruplets are:\n";

        for (vector<int>& group : answer) {
            for (int num : group) {
                cout << num << " ";
            }

            cout << endl;
        }
    }

    return 0;
}