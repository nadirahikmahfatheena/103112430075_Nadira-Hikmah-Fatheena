#include <iostream>
#include "stackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    Mahasiswa M;

    createStack(S);

    M = {"Venti", "11111", 75.7f, 82.1f, 65.5f}; Push(S, M);
    M = {"Xiao", "22222", 87.4f, 88.9f, 81.9f}; Push(S, M);
    M = {"Kazuha", "33333", 92.3f, 88.8f, 82.4f}; Push(S, M);
    M = {"Wanderer", "44444", 95.5f, 85.5f, 90.5f}; Push(S, M);
    M = {"Lynette", "55555", 77.7f, 65.4f, 79.9f}; Push(S, M);
    M = {"Chasca", "66666", 99.9f, 93.6f, 87.3f}; Push(S, M);

    cout << "stack setelah input 6 mahasiswa:\n";
    View(S);

    Pop(S, M);
    cout << "data yang dipop: " << M.nama << " (" << M.NIM << ")\n\n";

    cout << "sttack setelah 1x Pop:\n";
    View(S);

    M = {"Heizou", "77777", 99.9f, 88.8f, 77.7f};
    Update(S, 3, M);

    cout << "stack setelah update posisi ke-3:\n";
    View(S);

    cout << "searching Nilai Akhir 85.5 - 95.5\n";
    SearchNilaiAkhir(S, 85.5f, 95.5f);

    cout << "nahasiswa dengan Nilai Akhir terbesar:\n";
    MaxNilaiAkhir(S);

    return 0;
}
