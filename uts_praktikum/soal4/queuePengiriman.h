#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(const QueueEkspedisi &Q);
bool isFull(const QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, const Paket &P);
bool deQueue(QueueEkspedisi &Q, Paket &P);
void viewQueue(const QueueEkspedisi &Q);
long long TotalBiayaPengiriman(const QueueEkspedisi &Q);

#endif
