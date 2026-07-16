#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main() {

    string s, t;

    cout << "Enter First String: ";
    cin >> s;

    cout << "Enter Second String: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "Anagram";
    else
        cout << "Not Anagram";

    return 0;
}