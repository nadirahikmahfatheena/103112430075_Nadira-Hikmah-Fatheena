#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    for (int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    
    cout << endl;
    
    for (int i = angka1; i >= 0; i--) { //decrement
        cout << i << " - ";
    }
    
    return 0;
}