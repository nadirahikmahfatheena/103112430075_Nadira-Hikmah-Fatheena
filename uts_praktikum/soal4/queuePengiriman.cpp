#include "queuePengiriman.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(const QueueEkspedisi &Q) {
    return Q.Head == -1;
}

bool isFull(const QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, const Paket &P) {
    if (isFull(Q)) {
        cout << "queue penuh\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "queue penuh\n";
        return;
    }

    Paket P;
    cout << "masukkan kode resi   : ";
    getline(cin, P.KodeResi);

    cout << "masukkan nama pengirim : ";
    getline(cin, P.NamaPengirim);

    cout << "masukkan Berat Barang (kg): ";
    while (!(cin >> P.BeratBarang)) {
        cout << "input harus angka! masukkan lagi: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');

    cout << "masukkan tujuan: ";
    getline(cin, P.Tujuan);

    enQueue(Q, P);
}

bool deQueue(QueueEkspedisi &Q, Paket &P) {
    if (isEmpty(Q)) {
        cout << "queue kosong\n";
        return false;
    }

    P = Q.dataPaket[Q.Head];

    if (Q.Head == Q.Tail) {
        Q.Head = Q.Tail = -1;
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
    }

    return true;
}

void viewQueue(const QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "queue kosong\n";
        return;
    }

    int pos = 1;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << pos++ << ".\n";
        cout << "  Kode Resi    : " << Q.dataPaket[i].KodeResi << endl;
        cout << "  NamaPengirim : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "  BeratBarang  : " << Q.dataPaket[i].BeratBarang << " kg\n";
        cout << "  Tujuan       : " << Q.dataPaket[i].Tujuan << endl << endl;
    }
}

long long TotalBiayaPengiriman(const QueueEkspedisi &Q) {
    if (isEmpty(Q)) return 0;

    const long long TARIF = 8250;
    long long total = 0;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += (long long)Q.dataPaket[i].BeratBarang * TARIF;
    }

    return total;
}
