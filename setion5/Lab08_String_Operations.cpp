#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string name, username, studentID, other;
    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Name length: " << name.length() << '\n';
    if (!name.empty()) cout << "First character: " << name[0] << '\n';
    cout << "Contains a space: "
         << (name.find(' ') != string::npos ? "Yes" : "No") << '\n';

    cout << "Enter student ID: ";
    getline(cin, studentID);
    username = name.substr(0, min<size_t>(3, name.length())) + studentID;
    cout << "Generated username: " << username << '\n';

    cout << "Enter another name to compare: ";
    getline(cin, other);
    cout << (name == other ? "The names are equal.\n" :
                             "The names are different (case-sensitive).\n");

    transform(name.begin(), name.end(), name.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    cout << "Name in lowercase: " << name << '\n';
    return 0;
}