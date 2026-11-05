#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

enum class Status { PASS, FAIL };

struct Student {
    string id;
    string name;
    double mark1, mark2, mark3;
    double average() const { return (mark1 + mark2 + mark3) / 3.0; }
    Status status() const { return average() >= 50 ? Status::PASS : Status::FAIL; }
};

bool validMark(double mark) { return mark >= 0 && mark <= 100; }

int findStudent(const vector<Student>& students, const string& id) {
    for (size_t i = 0; i < students.size(); ++i)
        if (students[i].id == id) return static_cast<int>(i);
    return -1;
}

void registerStudent(vector<Student>& students) {
    Student s;
    cout << "Student ID: ";
    getline(cin >> ws, s.id);
    if (findStudent(students, s.id) != -1) {
        cout << "That ID already exists.\n";
        return;
    }
    cout << "Full name: ";
    getline(cin, s.name);
    cout << "Enter three marks: ";
    cin >> s.mark1 >> s.mark2 >> s.mark3;
    if (!validMark(s.mark1) || !validMark(s.mark2) || !validMark(s.mark3)) {
        cout << "Marks must each be from 0 to 100. Student not registered.\n";
        return;
    }
    students.push_back(s);
    cout << "Student registered successfully.\n";
}

void listStudents(const vector<Student>& students) {
    if (students.empty()) { cout << "No students registered.\n"; return; }
    cout << "\nID | NAME | AVERAGE | STATUS\n";
    for (const Student& s : students)
        cout << s.id << " | " << s.name << " | "
             << fixed << setprecision(2) << s.average() << " | "
             << (s.status() == Status::PASS ? "PASS" : "FAIL") << '\n';
}

void searchStudent(const vector<Student>& students) {
    string id;
    cout << "Enter student ID: ";
    getline(cin >> ws, id);
    int index = findStudent(students, id);
    if (index == -1) cout << "Student not found.\n";
    else {
        const Student& s = students[index];
        cout << s.name << " (" << s.id << "), average "
             << s.average() << ", "
             << (s.status() == Status::PASS ? "PASS" : "FAIL") << '\n';
    }
}

void updateMarks(vector<Student>& students) {
    string id;
    cout << "Enter ID of student to update: ";
    getline(cin >> ws, id);
    int index = findStudent(students, id);
    if (index == -1) { cout << "Student not found.\n"; return; }
    double a, b, c;
    cout << "Enter new three marks: ";
    cin >> a >> b >> c;
    if (!validMark(a) || !validMark(b) || !validMark(c)) {
        cout << "Invalid marks. No changes made.\n";
        return;
    }
    students[index].mark1 = a;
    students[index].mark2 = b;
    students[index].mark3 = c;
    cout << "Marks updated.\n";
}

void statistics(const vector<Student>& students) {
    if (students.empty()) { cout << "No statistics: class is empty.\n"; return; }
    double total = 0;
    for (const Student& s : students) total += s.average();
    int passes = count_if(students.begin(), students.end(),
                          [](const Student& s) { return s.average() >= 50; });
    cout << "Number of students: " << students.size()
         << "\nClass average: " << total / students.size()
         << "\nPasses: " << passes
         << "\nFails: " << students.size() - passes << '\n';
}

void topStudent(const vector<Student>& students) {
    if (students.empty()) { cout << "No students registered.\n"; return; }
    auto best = max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            if (a.average() == b.average()) return a.name > b.name;
            return a.average() < b.average();
        });
    cout << "Top student: " << best->name << " - " << best->average() << '\n';
}

void passList(const vector<Student>& students) {
    bool any = false;
    for (const Student& s : students) {
        if (s.status() == Status::PASS) {
            cout << s.name << " (" << s.id << ") - " << s.average() << '\n';
            any = true;
        }
    }
    if (!any) cout << "There are no students who passed.\n";
}

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "\n===== STUDENT ACADEMIC MANAGEMENT SYSTEM =====\n"
             << "1. Register student\n2. List students\n3. Search by ID\n"
             << "4. Update marks\n5. Class statistics\n6. Top student\n"
             << "7. Pass list\n8. Exit\nChoose: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\\n');
            cout << "Please enter a number from 1 to 8.\n";
            continue;
        }
        switch (choice) {
            case 1: registerStudent(students); break;
            case 2: listStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateMarks(students); break;
            case 5: statistics(students); break;
            case 6: topStudent(students); break;
            case 7: passList(students); break;
            case 8: cout << "Goodbye.\n"; break;
            default: cout << "Invalid option. Choose 1 to 8.\n";
        }
    } while (choice != 8);
    return 0;
}