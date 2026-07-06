#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter binary array: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] == 1) {
            count++;
            maxi = max(maxi, count);
        }
        else {
            count = 0;
        }
    }

    cout << "Maximum Consecutive Ones = " << maxi;

    return 0;
}