#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name, studentID, course;
    int age;
    double fee;
    bool registered = true;

    cout << "Enter full name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    getline(cin, studentID);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter course: ";
    getline(cin, course);
    cout << "Enter school fee (FCFA): ";
    cin >> fee;

    cout << "\n========== STUDENT RECEIPT ==========\n";
    cout << "Name: " << name << "\nID: " << studentID
         << "\nAge: " << age << "\nCourse: " << course
         << "\nRegistered: " << boolalpha << registered
         << "\nFee: " << fixed << setprecision(2) << fee << " FCFA\n";
    cout << "=====================================\n";
    return 0;
}