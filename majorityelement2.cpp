#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& arr) {
    int n = arr.size();

    int element1 = 0;
    int element2 = 0;

    int count1 = 0;
    int count2 = 0;

    for (int num : arr) {
        if (count1 == 0 && num != element2) {
            element1 = num;
            count1 = 1;
        }
        else if (count2 == 0 && num != element1) {
            element2 = num;
            count2 = 1;
        }
        else if (num == element1) {
            count1++;
        }
        else if (num == element2) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int num : arr) {
        if (num == element1) {
            count1++;
        }

        if (num == element2) {
            count2++;
        }
    }

    vector<int> answer;

    if (count1 > n / 3) {
        answer.push_back(element1);
    }

    if (count2 > n / 3) {
        answer.push_back(element2);
    }

    return answer;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> answer = majorityElement(arr);

    if (answer.empty()) {
        cout << "No majority element";
    }
    else {
        cout << "Majority elements: ";

        for (int num : answer) {
            cout << num << " ";
        }
    }

    return 0;
}