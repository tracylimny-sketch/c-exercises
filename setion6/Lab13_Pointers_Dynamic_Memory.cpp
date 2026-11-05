#include <iostream>
using namespace std;

int main() {
    int number = 25;
    int* pointer = &number;
    cout << "Value: " << number << '\n';
    cout << "Address: " << pointer << '\n';
    cout << "Value through pointer: " << *pointer << '\n';

    int size;
    cout << "How many numbers? ";
    cin >> size;
    if (size <= 0) {
        cout << "Size must be positive.\n";
        return 1;
    }

    int* values = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];
    }
    cout << "Values entered: ";
    for (int i = 0; i < size; ++i) cout << values[i] << " ";

    delete[] values; // Release dynamically allocated array once.
    values = nullptr;
    cout << "\nMemory released.\n";
    return 0;
}