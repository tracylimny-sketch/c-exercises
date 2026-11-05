#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<int> marks = {45, 78, 90, 32, 67, 88, 54, 73};
    int total = accumulate(marks.begin(), marks.end(), 0);
    double average = static_cast<double>(total) / marks.size();
    auto minMark = min_element(marks.begin(), marks.end());
    auto maxMark = max_element(marks.begin(), marks.end());
    int passes = count_if(marks.begin(), marks.end(),
                          [](int mark) { return mark >= 50; });

    cout << "Class results\n";
    cout << "Total = " << total << "\nAverage = " << average
         << "\nLowest = " << *minMark << "\nHighest = " << *maxMark
         << "\nNumber of passes = " << passes << '\n';

    cout << "Failing student indexes: ";
    for (size_t i = 0; i < marks.size(); ++i)
        if (marks[i] < 50) cout << i << " ";
    cout << "\nEnter a mark to search for: ";
    int target;
    cin >> target;
    auto found = find(marks.begin(), marks.end(), target);
    if (found != marks.end())
        cout << "Mark found at index " << distance(marks.begin(), found) << '\n';
    else cout << "Mark not found.\n";
    return 0;
}