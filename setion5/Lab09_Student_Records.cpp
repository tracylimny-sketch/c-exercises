#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

enum class Status { PASS, FAIL };

struct Student {
    string id;
    string name;
    double mark;
    Status status;
};

int main() {
    vector<Student> students;
    for (int i = 0; i < 5; ++i) {
        Student s;
        cout << "\nStudent " << i + 1 << " ID: ";
        getline(cin >> ws, s.id);
        cout << "Name: ";
        getline(cin, s.name);
        cout << "Mark: ";
        cin >> s.mark;
        if (s.mark < 0 || s.mark > 100) {
            cout << "Invalid mark. Enter again: ";
            cin >> s.mark;
        }
        s.status = (s.mark >= 50) ? Status::PASS : Status::FAIL;
        students.push_back(s);
    }

    double total = 0;
    cout << "\n===== STUDENT REPORT =====\n";
    for (const Student& s : students) {
        total += s.mark;
        cout << s.id << " | " << s.name << " | " << s.mark << " | "
             << (s.status == Status::PASS ? "PASS" : "FAIL") << '\n';
    }
    cout << "Class average: " << total / students.size() << '\n';

    string searchID;
    cout << "Enter ID to search: ";
    cin >> searchID;
    bool found = false;
    for (const Student& s : students) {
        if (s.id == searchID) {
            cout << "Found: " << s.name << ", mark " << s.mark << '\n';
            found = true;
        }
    }
    if (!found) cout << "Student not found.\n";
    return 0;
}