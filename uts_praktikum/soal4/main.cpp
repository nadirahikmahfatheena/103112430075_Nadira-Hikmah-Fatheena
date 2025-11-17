#include <iostream>
#include "queuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    enQueue(Q, {"123456", "Hutao", 14, "Sumeru"});
    enQueue(Q, {"234567", "Ayaka", 10, "Fontaine"});
    enQueue(Q, {"345678", "Bennet", 7, "Natlan"});
    enQueue(Q, {"456789", "Furina", 16, "Liyue"});
    enQueue(Q, {"567890", "Nefer", 6, "Inazuma"});

    cout << "queue setelah input 5 paket\n";
    viewQueue(Q);

    Paket removed;
    cout << "deQueue 1x\n";
    deQueue(Q, removed);

    cout << "\nqueue setelah 1x deQueue\n";
    viewQueue(Q);

    cout << "total biaya pengiriman: Rp " 
         << TotalBiayaPengiriman(Q) << endl << endl;

    while (true) {
        cout << "--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda : ";

        int pilih;
        cin >> pilih;
        cin.ignore(1000, '\n');
        cout << endl;

        if (pilih == 0) break;

        switch (pilih) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                if (deQueue(Q, removed)) {
                    cout << "paket dihapus: " << removed.KodeResi 
                         << " - " << removed.NamaPengirim << endl;
                }
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                cout << "total biaya pengiriman: Rp "
                     << TotalBiayaPengiriman(Q) << endl;
                break;
            default:
                cout << "pilihan tidak valid\n";
        }

        cout << endl;
    }

    return 0;
}
