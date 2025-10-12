#include <iostream>
using namespace std;

void tampilArr(int data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarNilai(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrayB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "array A:" << endl;
    tampilArr(arrayA);
    cout << endl << "array B:" << endl;
    tampilArr(arrayB);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp = arrayA[i][j];
            arrayA[i][j] = arrayB[i][j];
            arrayB[i][j] = temp;
        }
    }

    cout << "array A setelah ditukar (manual):" << endl;
    tampilArr(arrayA);
    cout << "array B setelah ditukar (manual):" << endl;
    tampilArr(arrayB);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tukarNilai(&arrayA[i][j], &arrayB[i][j]);
        }
    }

    cout << "array A setelah ditukar (pointer):" << endl;
    tampilArr(arrayA);
    cout << "array B setelah ditukar (pointer):" << endl;
    tampilArr(arrayB);

    return 0;
}
