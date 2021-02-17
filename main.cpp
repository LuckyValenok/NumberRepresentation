#include <iostream>

using namespace std;

template<typename T>
void printByte(T x, int i) {
    unsigned char *ch = (((unsigned char *) &x) + i);
    for (int j = 0; j < 8; j++) {
        cout << bool(*ch & 0x80 >> j);
    }
}

template<typename T>
void print(T val) {
    cout << typeid(val).name() << ":" << endl;
    cout << "Big-Endian: ";
    for (int i = sizeof(val) - 1; i >= 0; i--) {
        printByte(val, i);
    }
    cout << endl;
    cout << "Little-Endian: ";
    for (int i = 0; i < sizeof(val); i++) {
        printByte(val, i);
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Input your number: ";
    cin >> number;
    cout << "\n";
    print(number);
    print((float) number);
    print((double) number);
    return 0;
}