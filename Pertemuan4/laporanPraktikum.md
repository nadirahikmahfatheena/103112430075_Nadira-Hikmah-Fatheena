# <h1 align="center">Laporan Praktikum Modul 4 </h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Struktur data linked list merupakan kumpulan elemen data yang saling terhubung melalui pointer, di mana setiap elemen (node) berisi data dan alamat menuju node berikutnya [1]. Dalam bahasa C++, linked list diimplementasikan menggunakan struct untuk mendefinisikan node dan pointer untuk menghubungkan antar-node, sehingga memungkinkan pengelolaan data secara dinamis tanpa harus menentukan ukuran tetap sejak awal [1].

Linked list memiliki keunggulan dalam efisiensi operasi penambahan dan penghapusan data karena tidak memerlukan pergeseran elemen seperti pada array [2]. Struktur ini sering digunakan dalam sistem yang membutuhkan perubahan data secara dinamis seperti antrian (queue) dan tumpukan (stack), meskipun akses elemennya harus dilakukan secara berurutan (sequential access) [3].

### A. Guided<br/>
...
#### 1. guided 1
#### 2. guided 2

### B. Unguided<br/>
...
#### 1. unguided 1
#### 2. unguided 2 

## Guided 

### 1. guided 1

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL


#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini mengimplementasikan Single Linked List

File list.h berisi deklarasi struktur data dan fungsi-fungsi dasar yang digunakan, seperti createList, alokasi, dealokasi, insertFirst, insertAfter, insertLast, dan printList.

File list.cpp berisi definisi fungsi yang mengatur proses pembuatan list, penambahan node ke awal, tengah, dan akhir list, serta penampilan seluruh isi list.

File main.cpp berfungsi sebagai program utama untuk menguji operasi-operasi pada linked list, yaitu membuat list kosong, menambahkan beberapa node, dan mencetak hasilnya ke layar.

### 2. guided 2

list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL


#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini mengimplementasikan Single Linked List dengan tambahan operasi penghapusan (delete) dan perhitungan jumlah node. Setiap elemen (node) menyimpan data mahasiswa berupa nama, NIM, dan umur.

File list.h berisi deklarasi struktur data dan prototipe fungsi yang digunakan dalam pengelolaan list.

File list.cpp berisi implementasi fungsi-fungsi dasar seperti pembuatan list, penambahan node (insertFirst, insertAfter, insertLast), serta penghapusan node (delFirst, delAfter, delLast). Selain itu, terdapat fungsi nbList untuk menghitung jumlah node dan deleteList untuk menghapus seluruh isi list.

File main.cpp berfungsi untuk menguji seluruh operasi tersebut dengan menambahkan beberapa node, menampilkan isi list, menghapus beberapa node, serta menghitung jumlah node setelah setiap proses.

## Unguided 

### 1. Unguided 1

main.cpp
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(0);
    insertFirst(L, P1);

    P2 = alokasi(12);
    insertFirst(L, P2);

    P4 = alokasi(9);
    insertFirst(L, P4);

    P5 = alokasi(2);
    insertLast(L, P5);

    cout << "Isi List Awal : " << endl;
    printInfo(L);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "Isi List Setelah Insert After : " << endl;
    printInfo(L);

    return 0;
}
```

singlylist.cpp
```C++
#include "singlylist.h"

void createList(linkedList &L) {
    L.first = Nil;
}

address alokasi(int x) {
    address P = new node;
    P->info.num = x;
    P->next = Nil;
    return P;
}

bool isEmpty(linkedList L) {
    return (L.first == Nil);
}

void insertFirst(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info.num << " ";
        P = P->next;
    }
    cout << endl;
}
```

singlylist.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;
typedef struct node *address;

struct node{
    dataAngka info;
    address next;
};
struct linkedList {
    address first;
};
  
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(int x);
void dealokasi(address &node);
void printInfo(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif
```

tempcoderun.cpp
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan4_Modul4/output/tugas1.jpg)

Program ini mengimplementasikan Single Linked List. Setiap elemen (node) menyimpan satu nilai bilangan (num) dan pointer yang menunjuk ke node berikutnya

File singlylist.h berisi deklarasi struktur data (node, linkedList) dan prototipe fungsi seperti createList, alokasi, insertFirst, insertAfter, insertLast, dan printInfo.

File singlylist.cpp berisi definisi fungsi untuk membuat list kosong, menambahkan node di awal, di tengah (setelah node tertentu), maupun di akhir list, serta menampilkan seluruh isi list.

File main.cpp digunakan untuk menguji operasi list, yaitu membuat beberapa node dengan nilai bilangan, menambahkannya ke dalam list menggunakan berbagai metode penyisipan, dan mencetak hasilnya sebelum dan sesudah operasi insertAfter.

### 2. Unguided 2

main.cpp
```C++
#include "singlelist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(0);
    insertFirst(L, P1);

    P2 = alokasi(12);
    insertFirst(L, P2);

    P4 = alokasi(9);
    insertFirst(L, P4);

    P5 = alokasi(2);
    insertLast(L, P5);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "Isi List Awal : " << endl;
    printInfo(L);
    cout << endl;
    
    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, P2, P3);
    cout << "Isi List Setelah Delete First, Delete Last, dan Delete After : " << endl;
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -";
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

singlelist.cpp
```C++
#include "singlelist.h"

void createList(linkedList &L) {
    L.first = Nil;
}

address alokasi(int x) {
    address P = new node;
    P->info.num = x;
    P->next = Nil;
    return P;
}

bool isEmpty(linkedList L) {
    return (L.first == Nil);
}

void insertFirst(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info.num << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void deleteAfter(linkedList &List, address nodePrev, address nodeHapus){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
    P = Nil;
}
```

singlelist.h
```C++
#ifndef SINGLELIST_H
#define SINGLELIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;
typedef struct node *address;

struct node{
    dataAngka info;
    address next;
};
struct linkedList {
    address first;
};
  
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(int x);
void dealokasi(address &node);
void printInfo(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void deleteFirst(linkedList &List);
void deleteLast(linkedList &List);
void deleteAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```

### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan4_Modul4/output/tugas2.jpg)

Program ini merupakan implementasi Single Linked List. Setiap elemen (node) menyimpan satu nilai bilangan dan pointer yang menunjuk ke elemen berikutnya. Program ini mendemonstrasikan operasi dasar seperti penambahan, penghapusan, penelusuran, dan penghitungan jumlah elemen pada list.

File singlelist.h berisi deklarasi struktur data (node, linkedList) dan prototipe fungsi untuk operasi list.

File singlelist.cpp berisi implementasi fungsi, meliputi pembuatan list kosong (createList), penyisipan node di awal, tengah, dan akhir (insertFirst, insertAfter, insertLast), penghapusan node (deleteFirst, deleteAfter, deleteLast), penghitungan jumlah node (nbList), serta penghapusan seluruh elemen (deleteList).

File main.cpp digunakan untuk menguji seluruh operasi, dimulai dengan membuat beberapa node dan menambahkannya ke dalam list, kemudian menghapus beberapa elemen, menampilkan isi list, dan menampilkan jumlah node setelah setiap operasi.

## Kesimpulan

dapat disimpulkan bahwa linked list merupakan struktur data dinamis yang fleksibel dan efisien dalam proses penambahan serta penghapusan elemen. Implementasinya dalam bahasa C++ memanfaatkan konsep pointer untuk menghubungkan antar-node, sehingga memungkinkan pengelolaan data yang lebih optimal dibandingkan struktur data statis seperti array. Dengan sifatnya yang dinamis, linked list sangat berguna dalam berbagai aplikasi yang membutuhkan perubahan ukuran data secara real-time, meskipun akses elemennya dilakukan secara berurutan.

## Referensi

[1] Syafii, M. (2021). Pemrograman Komputer Menggunakan C++. Universitas Andalas. Diakses pada 12 Oktober 2025 melalui http://repo.unand.ac.id/32011/

<br>[2] Wijoyo, A., et al. (2024). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. https://jurnalmahasiswa.com/index.php/jriin/article/view/1060/678


<br>[3] Wijoyo, A., et al. (2024). Perbandingan Struktur Linked List dan Array dalam Manajemen Memori. https://jurnalmahasiswa.com/index.php/jriin/article/view/957/756
