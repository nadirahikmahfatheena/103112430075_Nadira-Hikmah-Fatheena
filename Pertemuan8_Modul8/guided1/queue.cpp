#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(Queue Q) {
    return Q.head == nullptr;
}

bool isFull(Queue) {
    return false;
}

void enQueue(Queue &Q, const string &name) {
    Node* baru = new Node{name, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << name << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->name << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->name << endl;
    }
}

void clearQueue(Queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}