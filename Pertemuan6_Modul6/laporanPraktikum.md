# <h1 align="center">Laporan Praktikum Modul 6</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Struktur data doubly linked list merupakan salah satu jenis linked list yang memiliki dua pointer pada setiap node, yaitu pointer next yang menunjuk ke node berikutnya dan pointer prev yang menunjuk ke node sebelumnya. Struktur ini memungkinkan proses penelusuran data dilakukan dalam dua arah, baik dari awal ke akhir maupun sebaliknya. Dengan karakteristik tersebut, doubly linked list memberikan fleksibilitas yang lebih tinggi dibandingkan singly linked list karena mendukung proses manipulasi data secara efisien tanpa harus menelusuri list dari awal [1].

Setiap node pada doubly linked list terdiri atas tiga komponen utama, yaitu bagian data, pointer ke node berikutnya, dan pointer ke node sebelumnya. Struktur ini sangat berguna dalam aplikasi yang memerlukan proses penambahan dan penghapusan data di posisi mana pun secara cepat, karena setiap operasi hanya melibatkan perubahan pada pointer antar node. Hal ini membuat doubly linked list lebih efisien dibandingkan struktur data seperti array yang memerlukan pergeseran elemen setiap kali dilakukan operasi penyisipan atau penghapusan [1][2].

Doubly linked list juga sering digunakan pada sistem yang membutuhkan pengelolaan data dinamis, seperti sistem antrian, navigasi data dua arah, serta pengolahan data mahasiswa. Dalam implementasinya menggunakan bahasa C++, struktur ini dibangun dengan memanfaatkan konsep struct dan pointer agar dapat mengatur alokasi memori secara dinamis [2]. Setiap node dapat ditambahkan atau dihapus tanpa mengganggu struktur keseluruhan, karena hubungan antar node dijaga melalui dua arah pointer yang saling terhubung.

Penelitian lain menunjukkan bahwa doubly linked list memberikan efisiensi tinggi dalam operasi insertion dan deletion dibandingkan array. Namun demikian, doubly linked list memerlukan penggunaan memori yang lebih besar karena setiap node menyimpan dua pointer sekaligus. Oleh sebab itu, penggunaannya lebih sesuai untuk sistem yang membutuhkan fleksibilitas manipulasi data daripada efisiensi ruang penyimpanan [3]. Dengan keunggulan tersebut, doubly linked list menjadi salah satu struktur data yang penting dalam pengembangan algoritma dan sistem informasi yang membutuhkan pengelolaan data secara dinamis dan terstruktur.

### A. Guided<br/>
...
#### 1. guided 1
#### 2. guided 2

### B. Unguided<br/>
...
#### 1. unguided 

## Guided 

### 1. guided 1

listMakanan.cpp
```C++
#include "listMakanan.h"
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
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Setiap node dalam list berisi informasi berupa nama makanan, jenis, harga, dan rating, serta dua pointer yaitu next untuk menunjuk ke node berikutnya dan prev untuk menunjuk ke node sebelumnya. Pada awal program, list diinisialisasi sebagai list kosong menggunakan fungsi createList, kemudian dilakukan proses alokasi memori untuk membuat node baru melalui fungsi alokasi. Node-node tersebut dimasukkan ke dalam list menggunakan berbagai fungsi penyisipan seperti insertFirst, insertLast, insertAfter, dan insertBefore, yang memungkinkan penambahan node di awal, akhir, atau di antara dua node tertentu. Program juga menyediakan fungsi printList untuk menampilkan seluruh isi list, serta fungsi updateFirst, updateLast, updateAfter, dan updateBefore untuk memperbarui data pada posisi tertentu dalam list. Sehingga, pengguna dapat menambah, melihat, dan mengubah data makanan.

### 2. guided 2

listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
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
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program ini digunakan untuk menyimpan, menampilkan, memperbarui, mencari, dan menghapus data makanan yang terdiri atas atribut nama, jenis, harga, dan rating. Struktur data yang digunakan adalah linked list ganda, di mana setiap node memiliki dua pointer yaitu next untuk menunjuk ke node berikutnya dan prev untuk menunjuk ke node sebelumnya, sehingga data dapat diakses dari dua arah. Pada tahap awal, list diinisialisasi kosong menggunakan fungsi createList, kemudian node baru dibuat melalui alokasi dan dimasukkan ke list menggunakan berbagai metode seperti insertFirst, insertLast, insertAfter, dan insertBefore. Setelah data tersimpan, fungsi updateFirst, updateLast, updateBefore, dan updateAfter digunakan untuk memperbarui isi node tertentu.

Program ini juga dilengkapi fitur pencarian dengan tiga fungsi utama yaitu findByName untuk mencari makanan berdasarkan nama, findByJenis untuk mencari berdasarkan jenis makanan, serta findByMinRating untuk menampilkan makanan dengan rating minimal tertentu. Selain itu, terdapat beberapa fungsi penghapusan seperti deleteFirst, deleteLast, deleteAfter, dan deleteBefore yang digunakan untuk menghapus node di posisi tertentu, serta deleteByName dan deleteNode untuk menghapus data berdasarkan nama atau alamat node secara langsung. Proses dealokasi dilakukan setelah penghapusan agar memori yang digunakan node tersebut dikembalikan ke sistem.

## Unguided 

### 1. Unguided 

doublylist.cpp
```C++
#include "doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) { 
    address nodeBaru = new ElmList;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna; 
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

bool isNopolExist(List L, string nopol) {
    address p = L.first;
    while(p != Nil) {
        if(p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void insertLast(List &L, address nodeBaru){
    if(isEmpty(L) == true){
        L.first = L.last = nodeBaru;
    } else {
        nodeBaru->prev = L.last;
        L.last->next = nodeBaru;
        L.last = nodeBaru;
    }
    cout << "Kendaraan berhasil ditambahkan" << endl;
}

void printList(List L) {
    if (isEmpty(L) == true) {
        cout << "L kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << "Nomor Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna        : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun        : " << nodeBantu->isidata.thnBuat<< endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// SEARCHING
void findElm(List L, string nopol){
    if(isEmpty(L)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.first;
    while(p != Nil){
        if(p->isidata.nopol == nopol){
            cout << "Nomor Polisi : " << p->isidata.nopol << endl;
            cout << "Warna        : " << p->isidata.warna << endl;
            cout << "Tahun        : " << p->isidata.thnBuat<< endl;
            return;
        }
        p = p->next;
    }
    cout << "Kendaraan tidak ditemukan." << endl;
}

// DELETE
void deleteFirst(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.first;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.first = pDel->next;
        L.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(List &L){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.last;
    if(L.first == L.last){
        L.first = L.last = Nil;
    } else {
        L.last = pDel->prev;
        L.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(List &L, address Prev){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada kendaraan yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Kendaraan sebelumnya (Prev) tidak valid atau tidak ada kendaraan setelahnya!" << endl;
        return;
    }
    if(Prev->next == L.last){
        deleteLast(L);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Kendaraan dengan nomor polisi " << pDel->isidata.nopol << " berhasil dihapus setelah kendaraan bernomor polisi " << Prev->isidata.nopol << "." << endl;
    dealokasi(pDel);
}
```

doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat;
};

typedef kendaraan infoType;

typedef struct ElmList *address;

struct ElmList{
    infoType isidata;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &ElmList);

bool isNopolExist(List L, string nopol);
void insertLast(List &L, address ElmListBaru);

void printList(List L);

// Searching
void findElm(List L, string nopol);

// Delete
void deleteFirst(List &List);
void deleteLast(List &List);
void deleteAfter(List &List, address Prev);

#endif
```

main.cpp
```C++
#include "doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    List L;
    createList(L);

    infoType dataKendaraan;
    string nopol, warna, cariNopol, hapusNopol;
    int thnBuat;
    int count = 0;
    
    while(count < 3) {
        cout << "Masukkan nomor polisi: ";
        getline(cin, nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;
        cin.ignore();
        
        if(!isNopolExist(L, nopol)) {
            address nodeBaru = alokasi(nopol, warna, thnBuat);
            insertLast(L, nodeBaru);
            count++;
        } else {
            cout << "Nomor polisi " << nopol << " sudah terdaftar" << endl;
        }
    }
    
    cout << "\nDATA LIST 1" << endl;
    printList(L);

    cout << "\nMasukkan nomor polisi yang dicari: ";
    getline(cin, cariNopol);
    findElm(L, cariNopol);

    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    
    if(!isEmpty(L)) {
        address p = L.first;
        
        if(p->isidata.nopol == hapusNopol) {
            deleteFirst(L);
        } else if(L.last->isidata.nopol == hapusNopol) {
            deleteLast(L);
        } else {
            while(p != Nil && p->next != Nil) {
                if(p->next->isidata.nopol == hapusNopol) {
                    deleteAfter(L, p);
                    break;
                }
                p = p->next;
            }
        }
    }
    
    cout << "\nDATA LIST 1" << endl;
    printList(L);

    return 0;
}
```

Program ini berfungsi untuk mengelola data kendaraan. Setiap node dalam list menyimpan informasi kendaraan berupa nomor polisi, warna, dan tahun pembuatan, serta memiliki dua pointer yaitu next dan prev yang memungkinkan pergerakan data secara maju maupun mundur. Melalui program ini, pengguna dapat menambahkan data kendaraan baru, menampilkan seluruh data kendaraan yang tersimpan, mencari data kendaraan berdasarkan nomor polisi, dan menghapus data kendaraan tertentu baik di awal, di akhir, maupun di tengah list. Program juga dilengkapi dengan pengecekan menggunakan fungsi isNopolExist untuk memastikan tidak ada duplikasi nomor polisi sebelum data dimasukkan ke dalam list. Selain itu, fungsi deleteFirst, deleteLast, dan deleteAfter digunakan untuk menghapus data sesuai posisi yang ditentukan, sedangkan fungsi findElm digunakan untuk menampilkan detail kendaraan yang dicari.

### Output Unguided :

##### Output 
![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan6_Modul6/output/unguided1.jpg)

Pengguna diminta untuk memasukkan data kendaraan sebanyak tiga kali.
Program akan memeriksa terlebih dahulu apakah nomor polisi sudah ada dengan isNopolExist().
Jika belum ada, data akan dialokasikan dan dimasukkan ke bagian akhir list dengan insertLast().
Setelah input selesai, semua data kendaraan akan ditampilkan melalui printList().

##### Output 
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan6_Modul6/output/unguided2.jpg)

Setelah semua data dimasukkan, program meminta pengguna memasukkan nomor polisi yang ingin dicari, misalnya D001.
Fungsi findElm(L, "D001") akan menelusuri node dari L.first hingga L.last.
Jika ditemukan, program menampilkan seluruh informasi kendaraan tersebut.

##### Output 
![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan6_Modul6/output/unguided3.jpg)

program melakukan proses penghapusan data kendaraan berdasarkan nomor polisi yang dimasukkan pengguna. Misalnya, ketika pengguna memasukkan nomor polisi D003, program akan mencari posisi data tersebut di dalam list. Jika data ditemukan, maka kendaraan dengan nomor polisi tersebut akan dihapus menggunakan prosedur penghapusan yang sesuai dengan posisinya, apakah berada di awal, di tengah, atau di akhir list. Setelah data berhasil dihapus, program menampilkan pesan konfirmasi bahwa kendaraan dengan nomor polisi D003 telah dihapus setelah kendaraan bernomor polisi D001, kemudian menampilkan kembali daftar kendaraan yang tersisa.

## Kesimpulan

Dapat disimpulkan bahwa doubly linked list merupakan struktur data yang efisien dan fleksibel dalam pengelolaan data dinamis. Setiap node yang memiliki dua pointer memungkinkan proses penambahan, penghapusan, dan penelusuran data dilakukan dengan lebih mudah tanpa perlu memindahkan elemen lain seperti pada array. Meskipun membutuhkan memori yang lebih besar, doubly linked list tetap menjadi pilihan yang tepat untuk sistem yang memerlukan manipulasi data secara terus-menerus dan dua arah, seperti sistem antrian, pengolahan data akademik, serta aplikasi dengan kebutuhan navigasi data yang kompleks.

## Referensi

[1] Agung Wijoyo, dkk. (2024). Penggunaan Algoritma Doubly Linked List untuk Insertion dan Deletion. Jurnal Riset Informatika dan Inovasi (JRIIN), Vol. 1, No. 12, pp. 45–52. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1282/762

<br>[2] Maria Triani Mbejo, dkk. (2025). Analisis Struktur Data Linked List dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan (JSIT), Vol. 4, No. 2, pp. 120–130. Diakses melalui https://rcf-indonesia.org/home/index.php/jsit/article/view/591/418

<br>[3] R. D. Putra, A. S. Rahman, & Y. F. Hidayat. (2023). Implementasi Struktur Data Array dan Linked List dalam Pengelolaan Data Mahasiswa. Jurnal Menulis dan Riset Informatika (JMRI), Vol. 3, No. 1, pp. 33–41. Diakses melalui https://padangjurnal.web.id/index.php/menulis/article/view/417/433