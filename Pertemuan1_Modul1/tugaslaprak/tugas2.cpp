#include <iostream>
#include <string>

using namespace std;

string ubahAngka(int n) {
    switch (n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        case 10: return "sepuluh";
        case 11: return "sebelas";
        default: return ""; 
    }
}

int main() {
    int a;

    cout << "input angka (dalam rentang 0-100): ";
    cin >> a;

    cout << a << ": ";
    if (a < 0 || a > 100) {
        cout << "angka tidak dalam rentang 0-100" << endl;
    } else {
        string hasil;

        if (a < 12) {
            hasil = ubahAngka(a);
        } else if (a < 20) {
            hasil = ubahAngka(a % 10) + " belas";
        } else if (a < 100) {
            int puluhan = a / 10;
            int sisa = a % 10;
            if (sisa == 0) {
                hasil = ubahAngka(puluhan) + " puluh";
            } else {
                hasil = ubahAngka(puluhan) + " puluh " + ubahAngka(sisa);
            }
        } else {
            hasil = "seratus";
        }
        cout << hasil << endl;
    }

    return 0;
}