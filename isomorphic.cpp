#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {

    if (s.length() != t.length())
        return false;

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.length(); i++) {

        if (mp1.count(s[i]) && mp1[s[i]] != t[i])
            return false;

        if (mp2.count(t[i]) && mp2[t[i]] != s[i])
            return false;

        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter First String: ";
    cin >> s;

    cout << "Enter Second String: ";
    cin >> t;

    if (isIsomorphic(s, t))
        cout << "Isomorphic";
    else
        cout << "Not Isomorphic";

    return 0;
}