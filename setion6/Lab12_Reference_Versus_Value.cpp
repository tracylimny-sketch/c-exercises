#include <iostream>
using namespace std;

void addBonusByValue(int mark) { mark += 10; }
void addBonusByReference(int& mark) { mark += 10; }
void swapValues(int& a, int& b) {
    int temp = a; a = b; b = temp;
}

int main() {
    int mark = 60;
    addBonusByValue(mark);
    cout << "After pass by value: " << mark << '\n';
    addBonusByReference(mark);
    cout << "After pass by reference: " << mark << '\n';

    int first = 10, second = 20;
    cout << "Before swap: " << first << ", " << second << '\n';
    swapValues(first, second);
    cout << "After swap: " << first << ", " << second << '\n';
    return 0;
}