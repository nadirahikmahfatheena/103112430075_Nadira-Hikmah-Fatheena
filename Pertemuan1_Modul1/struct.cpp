#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

   struct rapot{
    char nama[5]; 
    int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++){
        cout << "Masukkan nama siswa: " ;
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: " ;
        cin >> siswa[i].nilai;
    }

    int i = 0;
    while (i < jumlah){
        cout << "Nama: " << siswa[i].nama << " Nilai: " << siswa[i].nilai << endl;
        i++;
    }
    
    return 0;
}