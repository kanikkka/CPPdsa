#include <iostream>
using namespace std;

long long findElement(int r, int c) {
    long long result = 1;

    int n = r - 1;
    int k = c - 1;

    for (int i = 0; i < k; i++) {
        result = result * (n - i);
        result = result / (i + 1);
    }

    return result;
}

int main() {
    int row, column;

    cout << "Enter row number: ";
    cin >> row;

    cout << "Enter column number: ";
    cin >> column;

    if (column > row || row <= 0 || column <= 0) {
        cout << "Invalid row or column";
        return 0;
    }

    cout << "Element: " << findElement(row, column);

    return 0;
}