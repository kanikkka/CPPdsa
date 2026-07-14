#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(
    vector<vector<int>>& intervals
) {
    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answer;

    answer.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        int lastIndex = answer.size() - 1;

        if (intervals[i][0] <=
            answer[lastIndex][1]) {

            answer[lastIndex][1] =
                max(
                    answer[lastIndex][1],
                    intervals[i][1]
                );
        }
        else {
            answer.push_back(intervals[i]);
        }
    }

    return answer;
}

int main() {
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(
        n,
        vector<int>(2)
    );

    cout << "Enter start and end of intervals:\n";

    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0]
            >> intervals[i][1];
    }

    vector<vector<int>> answer =
        mergeIntervals(intervals);

    cout << "Merged intervals:\n";

    for (vector<int>& interval : answer) {
        cout << interval[0]
             << " "
             << interval[1]
             << endl;
    }

    return 0;
}