# <h1 align="center">Laporan Praktikum Modul 5</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Struktur data linked list merupakan kumpulan elemen data (node) yang saling terhubung melalui pointer, di mana setiap node berisi data dan alamat menuju node berikutnya [1]. Dalam bahasa C++, linked list diimplementasikan menggunakan struct dan pointer sehingga data dapat dikelola secara dinamis tanpa harus menentukan ukuran tetap seperti pada array. Struktur ini memungkinkan alokasi memori yang lebih fleksibel, menjadikannya cocok untuk aplikasi yang memerlukan perubahan ukuran data selama program berjalan [2].

Linked list memiliki keunggulan dalam efisiensi operasi penambahan dan penghapusan data karena tidak memerlukan pergeseran elemen seperti pada array. Setiap operasi hanya membutuhkan penyesuaian pointer antar-node, membuatnya efektif dalam sistem dinamis seperti antrian (queue) dan tumpukan (stack) [3]. Menurut penelitian Hybrid Array List, konsep linked list juga menjadi dasar pengembangan struktur data hybrid yang menggabungkan kecepatan akses array dengan fleksibilitas linked list dalam pengelolaan memori [1].

Selain itu, linked list mendukung berbagai operasi seperti pembaruan (update), pencarian (search), dan operasi aritmetika sederhana. Operasi update dilakukan untuk mengganti nilai data pada node tertentu, sementara search digunakan untuk menemukan data berdasarkan nilai, alamat, atau rentang tertentu. Adapun operasi aritmetika seperti penjumlahan, pengurangan, dan perkalian dilakukan dengan menelusuri setiap node dalam list. Ketiga jenis operasi tersebut memperlihatkan bagaimana linked list tidak hanya berfungsi sebagai penyimpan data, tetapi juga sebagai struktur yang dapat mendukung berbagai proses komputasi secara efisien [2].

### A. Guided<br/>
...
#### 1. guided 

### B. Unguided<br/>
...
#### 1. unguided 

## Guided 

### 1. guided 

listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
Program ini mengimplementasikan struktur data Singly Linked List untuk mengelola data buah yang terdiri atas nama, jumlah, dan harga. Program dibagi menjadi tiga bagian yaitu listBuah.h berisi deklarasi struktur dan fungsi, listBuah.cpp berisi definisi seluruh prosedur seperti pembuatan list, penambahan (insert), penghapusan (delete), pencarian (searching), serta pembaruan data (update), dan main.cpp digunakan untuk menguji seluruh operasi tersebut. Melalui program ini, list dibuat menggunakan pointer, di mana setiap node terhubung dengan node berikutnya hingga berakhir pada NULL. Program dapat menambahkan node di awal, tengah, dan akhir list, memperbarui serta mencari data berdasarkan nama, alamat, dan range harga, hingga menghapus node maupun seluruh isi list.

## Unguided 

### 1. Unguided 

listAngka.cpp
```C++
#include "listAngka.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(int a) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.a = a;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah angka " << nodePrev->isidata.a << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.a << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//update
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.a;
        cout << endl << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.a;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.a << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.a;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.a == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, int nilaiMin) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float cariAngka = nodeBantu->isidata.a;
            if(cariAngka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->isidata.a << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

int sumList(linkedlist List) {
    int total = 0;
    address p = List.first;
    while (p != Nil) {
        total = total + p->isidata.a;
        p = p->next;
    }
    return total;
}

int subList(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        address p = List.first;
        int total = 0;
        while (p != Nil) {
            total += p->isidata.a;
            p = p->next;
        }
        p = List.first;
        int hasil = p->isidata.a - total;

        return hasil;
    }
}


int multipleList(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        int total = 1;
        address p = List.first;
        while (p != Nil) {
            total = total * p->isidata.a;
            p = p->next;
        }
        return total;
    }
}
```

listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int a;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int a);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, int data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiMin);

int sumList(linkedlist List);
int subList(linkedlist List);
int multipleList(linkedlist List);

#endif
```

main.cpp
```C++
#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(29);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(45);
    nodeF = alokasi(50);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    delAfter(List, nodeB, nodeC);

    cout << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, 20);
    FindNodeByData(List, 55);
    FindNodeByAddress(List, nodeB);
    FindNodeByAddress(List, nodeA);
    FindNodeByRange(List, 40);

    cout << "Total penjumlahan : " << sumList(List) << endl;
    cout << "Total pengurangan : " << subList(List) << endl;
    cout << "Total perkalian   : " << multipleList(List) << endl;

    return 0;
}
```

Program ini dibagi menjadi tiga file utama yaitu listAngka.h, listAngka.cpp, dan main.cpp. File listAngka.h berfungsi sebagai header yang mendefinisikan struktur data dan deklarasi fungsi, seperti angka, node, dan linkedlist. Struktur node terdiri dari satu data bertipe integer dan satu pointer next yang menunjuk ke node berikutnya, sementara linkedlist menyimpan pointer first yang mengarah ke node pertama. File listAngka.cpp berisi implementasi fungsi-fungsi yang digunakan untuk mengelola linked list, termasuk operasi dasar seperti membuat list (createList), memeriksa apakah list kosong (isEmpty), menambahkan node (insertFirst, insertAfter, insertLast), menghapus node (delAfter), serta menampilkan isi list (printList). Selain itu, terdapat pula fungsi tambahan untuk memperbarui data (updateFirst, updateLast, updateAfter), mencari node berdasarkan nilai atau alamat (FindNodeByData, FindNodeByAddress, FindNodeByRange), dan melakukan operasi aritmetika seperti penjumlahan, pengurangan, dan perkalian terhadap semua elemen list (sumList, subList, multipleList). File main.cpp berfungsi untuk menjalankan seluruh fungsi tersebut dengan membuat beberapa node, menambahkannya ke dalam list, memperbarui data, melakukan pencarian, dan menampilkan hasil operasi aritmetika.

### Soal Unguided 1:
Buatlah procedure updateFirst, updateLast, dan updateAfter
Kemudian pada “main.cpp” lakukanlah : 
➢ Update data 40 menjadi 50 
➢ Update data 8 menjadi 29 
➢ Update data 33 menjadi 45 
➢ Update data 18 menjadi 20 
➢ Tampilkan seluruh list setelah diupdate

##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan5_Modul5/output/unguided1.jpg)

Pada soal pertama, diminta untuk membuat tiga prosedur yaitu updateFirst, updateLast, dan updateAfter yang berfungsi untuk memperbarui data pada node tertentu. Prosedur updateFirst digunakan untuk mengganti nilai data pada node pertama di dalam list, updateLast digunakan untuk memperbarui data pada node terakhir, dan updateAfter digunakan untuk mengubah nilai data pada node yang terletak setelah node tertentu yang ditentukan melalui parameter nodePrev. Pada implementasinya, setiap fungsi akan terlebih dahulu memeriksa apakah list kosong menggunakan isEmpty. Jika list tidak kosong, maka program akan meminta input angka baru dari pengguna untuk menggantikan data lama pada posisi yang sesuai. Dalam main.cpp, prosedur-prosedur ini digunakan untuk melakukan beberapa pembaruan data, yaitu mengubah nilai 40 menjadi 50, 8 menjadi 29, 33 menjadi 45, dan 18 menjadi 20. Setelah semua proses update dilakukan, program menampilkan kembali seluruh isi list dengan fungsi printList untuk menunjukkan hasil perubahan data yang telah diperbarui.

### Soal Unguided 2:
Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange
Kemudian pada “main.cpp” lakukanlah : 
➢ Mencari data nilai 20 
➢ Mencari data nilai 55 
➢ Mencari data alamat nodeB 
➢ Mencari data alamat nodeA 
➢ Mencari data dengan nilai minimal 40  

##### Output Unguided 2
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan5_Modul5/output/unguided2.jpg)

Pada soal kedua, dibuat tiga prosedur pencarian data, yaitu FindNodeByData, FindNodeByAddress, dan FindNodeByRange. Prosedur FindNodeByData berfungsi untuk mencari node berdasarkan nilai data integer yang disimpan dalam list. Jika nilai ditemukan, program akan menampilkan posisi node tersebut di dalam list. Prosedur FindNodeByAddress digunakan untuk mencari node berdasarkan alamat memorinya. Prosedur ini bermanfaat untuk memastikan apakah suatu pointer benar-benar menunjuk ke node yang berada di dalam list, serta menampilkan posisi dan alamat node yang sesuai. Sementara itu, FindNodeByRange digunakan untuk menampilkan semua node dengan nilai data yang lebih besar atau sama dengan nilai minimum yang ditentukan (nilaiMin). Dalam main.cpp, ketiga prosedur ini dijalankan untuk mencari data bernilai 20 dan 55, mencari alamat dari nodeB dan nodeA, serta menampilkan seluruh node dengan nilai minimal 40. Setiap prosedur akan menampilkan hasil pencarian berupa posisi node, alamat node, atau pesan bahwa data tidak ditemukan apabila tidak ada nilai yang sesuai.

### Soal Unguided 3:
Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap 
semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, 
untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai 
awal adalah 1. 

##### Output Unguided 3
![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan5_Modul5/output/unguided3.jpg)

Pada soal ketiga, dilakukan operasi aritmetika terhadap seluruh data yang ada dalam list menggunakan tiga fungsi yaitu sumList, subList, dan multipleList. Fungsi sumList menghitung total penjumlahan seluruh data dalam list dengan nilai awal 0, di mana setiap node dijumlahkan satu per satu dari awal hingga akhir. Fungsi subList digunakan untuk melakukan pengurangan dengan nilai awal berupa data dari node pertama, kemudian nilai-nilai node berikutnya dikurangkan secara berurutan. Sementara itu, multipleList digunakan untuk menghitung hasil perkalian semua data dalam list, dimulai dengan nilai awal 1. Ketiga fungsi ini memanfaatkan proses perulangan untuk menelusuri setiap node dan mengakumulasi hasil operasi aritmetika sesuai jenisnya. Dalam main.cpp, setelah proses pembaruan dan pencarian data selesai dilakukan, fungsi-fungsi ini dijalankan dan hasilnya ditampilkan ke layar berupa total penjumlahan, total pengurangan, dan total perkalian.

## Kesimpulan

Dapat disimpulkan bahwa linked list merupakan struktur data dinamis yang efisien untuk pengelolaan data yang sering berubah ukuran. Dengan memanfaatkan konsep node dan pointer, linked list mampu melakukan operasi penambahan, penghapusan, pembaruan, dan pencarian data tanpa perlu mengalokasikan ulang seluruh memori seperti pada array.
Implementasi linked list dalam bahasa C++ memberikan fleksibilitas tinggi dalam pengolahan data, terutama pada aplikasi yang membutuhkan efisiensi memori dan kecepatan manipulasi data. Selain itu, penerapan operasi aritmetika dan fungsi pendukung seperti update dan search menunjukkan bahwa linked list tidak hanya berperan sebagai penyimpan data, tetapi juga sebagai struktur yang mendukung proses komputasi yang kompleks dan dinamis.

## Referensi

[1] S. Sara, A. Rachmadi, & R. I. M. Darmawan. (2020). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesian Journal of Computing (IndoJC), Vol. 5, No. 2, pp. 45–52. Diakses melalui https://socjs.telkomuniversity.ac.id/ojs/index.php/indojc/article/view/527/297

<br>[2] Shofwan Hanief, S.Kom., M.T., & I Wayan Jepriana, S.Kom., M.Cs. (2023). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Deepublish. Diakses melalui https://books.google.co.id/books?id=BRQQEAAAQBAJ


<br>[3] D. Gunawan. (2015). Buku Ajar Bahasa Pemrograman C++. Deepublish. Diakses melalui https://books.google.co.id/books?id=MaNDEQAAQBAJ


