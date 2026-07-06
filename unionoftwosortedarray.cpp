#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> ans;

    int i = 0, j = 0;

    while (i < n && j < m) {

        if (a[i] <= b[j]) {

            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);

            i++;
        }
        else {

            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);

            j++;
        }
    }

    while (i < n) {

        if (ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);

        i++;
    }

    while (j < m) {

        if (ans.empty() || ans.back() != b[j])
            ans.push_back(b[j]);

        j++;
    }

    cout << "Union Array: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}