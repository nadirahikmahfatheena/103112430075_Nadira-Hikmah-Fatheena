#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke stack!" << endl;
    }
}

void pop(stackTable &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top) {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka baru: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl << endl;
}

void view(stackTable s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = s.top; i >= 0; --i) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

void searchData(stackTable s, int data) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i) {
        if (s.data[i] == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found) {
        cout << "Data " << data << " tidak ditemukan di dalam stack!" << endl << endl;
    }
}

void balikStack(stackTable &S) {
    stackTable temp;
    createStack(temp);

    while (!isEmpty(S)) {
        temp.data[++temp.top] = S.data[S.top--];
    }

    S = temp;
}

void pushAscending(stackTable &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    stackTable temp;
    createStack(temp);

    while (!isEmpty(S) && S.data[S.top] > x) {
        push(temp, S.data[S.top]);
        S.top--;
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, temp.data[temp.top]);
        temp.top--;
    }
}

void getInputStream(stackTable &S) {
    cout << "Masukkan angka (tanpa spasi), akhiri dengan Enter: ";
    string input;
    cin >> input;

    for (char c : input) {
        if (isdigit(c)) {
            int val = c - '0';
            push(S, val);
        }
    }
}
