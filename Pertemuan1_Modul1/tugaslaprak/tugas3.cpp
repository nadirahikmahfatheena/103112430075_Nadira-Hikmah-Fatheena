#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "input: ";
    cin >> a;
    
    cout << "output: " << endl;

    for (int i = a; i >= 1; i--) {

        for (int j = 1; j <= a - i; j++) {
            cout << "  ";
        }
        
        for (int k = i; k >= 1; k--) {
            cout << k << " ";
        }

        cout << "* ";

        for (int l = 1; l <= i; l++) {
            cout << l << " ";
        }

        cout << endl;
    }

    for (int m = 1; m <= a; m++) {
        cout << "  ";
    }
    
    cout << "*" << endl;

    return 0;
}