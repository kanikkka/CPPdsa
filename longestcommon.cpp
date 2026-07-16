#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    string ans = "";

    for (int i = 0; i < first.length(); i++) {

        if (first[i] == last[i])
            ans += first[i];
        else
            break;
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter Number of Strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter Strings:\n";

    for (int i = 0; i < n; i++)
        cin >> strs[i];

    cout << "Longest Common Prefix: "
         << longestCommonPrefix(strs);

    return 0;
}