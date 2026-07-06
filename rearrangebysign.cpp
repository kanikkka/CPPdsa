#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter equal positive and negative elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    cout << "Rearranged array: ";
    for (int x : ans) cout << x << " ";

    return 0;
}