#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> st;

    for (int x : arr) {
        st.insert(x);
    }

    int longest = 0;

    for (int x : st) {
        if (st.find(x - 1) == st.end()) {
            int count = 1;
            int num = x;

            while (st.find(num + 1) != st.end()) {
                count++;
                num++;
            }

            longest = max(longest, count);
        }
    }

    cout << "Longest consecutive subsequence length: " << longest;

    return 0;
}