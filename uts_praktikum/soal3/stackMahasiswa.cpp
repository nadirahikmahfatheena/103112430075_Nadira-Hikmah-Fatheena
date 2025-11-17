#include "stackMahasiswa.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isEmpty(const StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(const StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, const Mahasiswa &M) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push\n";
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = M;
}

void Pop(StackMahasiswa &S, Mahasiswa &M) {
    if (isEmpty(S)) {
        cout << "stack kosong, tidak ada yang dipop\n";
        return;
    }
    M = S.dataMahasiswa[S.Top];
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi, const Mahasiswa &M) {
    if (isEmpty(S)) {
        cout << "stack kosong\n";
        return;
    }

    int index = S.Top - (posisi - 1);

    if (index < 0 || index > S.Top) {
        cout << "posisi tidak valid\n";
        return;
    }

    S.dataMahasiswa[index] = M;
}

void View(const StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "stack kosong\n";
        return;
    }

    for (int i = S.Top; i >= 0; i--) {
        cout << "index " << i << ":\n";
        cout << "  nama       : " << S.dataMahasiswa[i].nama << endl;
        cout << "  NIM        : " << S.dataMahasiswa[i].NIM << endl;
        cout << "  NilaiAkhir : " << nilaiAkhir(S.dataMahasiswa[i]) << endl;
        cout << endl;
    }
}

void SearchNilaiAkhir(const StackMahasiswa &S, float minNilai, float maxNilai) {
    if (isEmpty(S)) {
        cout << "stack kosong\n";
        return;
    }

    cout << fixed << setprecision(2);
    bool found = false;

    for (int i = S.Top, pos = 1; i >= 0; i--, pos++) {
        float na = nilaiAkhir(S.dataMahasiswa[i]);

        if (na >= minNilai && na <= maxNilai) {
            cout << "ditemukan pada posisi " << pos << " (index " << i << "):\n";
            cout << "  nama : " << S.dataMahasiswa[i].nama << endl;
            cout << "  NIM  : " << S.dataMahasiswa[i].NIM << endl;
            cout << "  NilaiAkhir: " << na << endl << endl;
            found = true;
        }
    }

    if (!found)
        cout << "tidak ada mahasiswa dalam rentang nilai tersebut\n";
}

void MaxNilaiAkhir(const StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "satack kosong\n";
        return;
    }

    float maxNA = nilaiAkhir(S.dataMahasiswa[0]);

    for (int i = 1; i <= S.Top; i++) {
        float na = nilaiAkhir(S.dataMahasiswa[i]);
        if (na > maxNA) maxNA = na;
    }

    cout << "Nilai Akhir Tertinggi: " << maxNA << endl << endl;

    for (int i = S.Top; i >= 0; i--) {
        float na = nilaiAkhir(S.dataMahasiswa[i]);
        if (fabs(na - maxNA) < 1e-4f) {
            cout << "  nama : " << S.dataMahasiswa[i].nama << endl;
            cout << "  NIM  : " << S.dataMahasiswa[i].NIM << endl;
            cout << "  NilaiAkhir: " << na << endl << endl;
        }
    }
}
