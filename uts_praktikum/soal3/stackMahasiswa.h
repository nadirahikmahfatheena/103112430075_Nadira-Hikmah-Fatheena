#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    float nilaiTugas;
    float nilaiUTS;
    float nilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

inline float nilaiAkhir(const Mahasiswa &m) {
    return 0.20f * m.nilaiTugas + 0.40f * m.nilaiUTS + 0.40f * m.nilaiUAS;
}

bool isEmpty(const StackMahasiswa &S);
bool isFull(const StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, const Mahasiswa &M);
void Pop(StackMahasiswa &S, Mahasiswa &M);
void Update(StackMahasiswa &S, int posisi, const Mahasiswa &M);
void View(const StackMahasiswa &S);
void SearchNilaiAkhir(const StackMahasiswa &S, float minNilai, float maxNilai);
void MaxNilaiAkhir(const StackMahasiswa &S);

#endif
