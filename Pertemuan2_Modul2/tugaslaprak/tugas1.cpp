#include <iostream>
using namespace std;

void tampilkanHasil(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << "\t"; 
        }
        cout << endl;
    }
}

int main() {
    int matriksA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriksB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};  

    //penjumlahan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    cout << "Hasil Penjumlahan: " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    //pengurangan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrD[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    cout << "Hasil Pengurangan: " << endl;
    tampilkanHasil(arrD);
    cout << endl;

    //perkalian matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrE[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 3; i++) {      
        for (int j = 0; j < 3; j++) {   
            for (int k = 0; k < 3; k++) { 
                arrE[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian: " << endl;
    tampilkanHasil(arrE);

    return 0;
}