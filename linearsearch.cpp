#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> target;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index " << i;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found";
    }

    return 0;
}