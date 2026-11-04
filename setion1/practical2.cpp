#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    string name, department;
    int age, id;
    double fee;
    bool paid;

    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Registration Fee: ";
    cin >> fee;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Have you paid your fees? (1 for Yes, 0 for No): ";
    cin >> paid;

    cout << "\n========== STUDENT RECEIPT ==========" << endl;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Department: " << department << endl;
    cout << "Registration Fee: "
         << fixed << setprecision(2) << fee << " FCFA" << endl;
    cout << "Student ID: " << id << endl;
    cout << "Fees Paid: " << (paid ? "Yes" : "No") << endl;

    cout << "=====================================" << endl;

    return 0;
}
