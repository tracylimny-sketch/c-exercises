#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    double average;
};

int main() {
    vector<Student> students = {
        {"Ama", 72}, {"John", 85}, {"Peter", 49},
        {"Mary", 91}, {"David", 67}, {"Grace", 85}
    };

    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             if (a.average == b.average) return a.name < b.name;
             return a.average > b.average;
         });

    cout << "Students ordered by average (highest first):\n";
    for (const Student& s : students)
        cout << s.name << " - " << s.average << '\n';

    int passes = count_if(students.begin(), students.end(),
                          [](const Student& s) { return s.average >= 50; });
    cout << "Number of passes: " << passes << '\n';

    cout << "Top three students:\n";
    for (size_t i = 0; i < min<size_t>(3, students.size()); ++i)
        cout << i + 1 << ". " << students[i].name
             << " (" << students[i].average << ")\n";
    return 0;
}