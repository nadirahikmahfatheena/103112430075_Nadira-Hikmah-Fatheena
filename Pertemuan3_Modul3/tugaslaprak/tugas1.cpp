#include <iostream>
using namespace std;

struct Mhs{
    string nama;
    string nim;
    int uts;
    int uas;
    int tugas;
    float nilaiAkhir;
};

float hitungNilai(Mhs mhs){
    return 0.3 * mhs.uts + 0.4 * mhs.uas + 0.3 * mhs.tugas;
} 

void inputMhs(Mhs &mhs){
    cout << "Nama: ";
    cin >> mhs.nama;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "UTS: ";
    cin >> mhs.uts;
    cout << "UAS: ";
    cin >> mhs.uas;
    cout << "Tugas: ";
    cin >> mhs.tugas;

    mhs.nilaiAkhir = hitungNilai(mhs);
}

void outputMhs(Mhs mhs[], int n){
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "-----------------------------";
    }
    cout << endl;
}

int main(){
    Mhs mhs[10];
    int n;

    cout << "Masukan data mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Melewati batas max! (10)" << endl;
        return 0;
    } else{
        for (int i = 0; i < n; i++) {
            cout << "\nData Mahasiswa ke-" << i + 1 << endl;
            inputMhs(mhs[i]);
        }
    }

    outputMhs(mhs, n);
    return 0;
}