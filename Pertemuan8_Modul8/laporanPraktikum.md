# <h1 align="center">Laporan Praktikum Modul 8</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Struktur data merupakan komponen fundamental dalam pengembangan sistem informasi karena menentukan bagaimana data disimpan, diakses, dan dikelola secara efisien [1]. Dalam konteks sistem antrean, struktur data Queue menjadi salah satu yang paling penting karena bekerja dengan prinsip First In First Out (FIFO), di mana elemen pertama yang masuk akan menjadi elemen pertama yang diproses [1]. Konsep ini umum digunakan pada sistem layanan publik seperti kasir, perbankan, dan pelayanan kesehatan, karena memastikan alur pelayanan yang adil sesuai urutan kedatangan [1].

Selain Queue linear, terdapat pula variasi seperti Circular Queue, yaitu struktur antrean berbentuk melingkar yang memungkinkan elemen baru masuk dengan memanfaatkan kembali ruang kosong akibat elemen yang sudah keluar, tanpa perlu menggeser seluruh data [2]. Circular Queue terbukti lebih efisien dalam penggunaan memori dan pengolahan antrean, karena proses enqueue dan dequeue dapat dilakukan secara berkesinambungan [2]. Penerapan struktur data ini sangat relevan pada sistem antrean berbasis web yang menangani jumlah pengguna besar secara real-time [2].

Dalam situasi tertentu, sistem antrean juga memerlukan mekanisme prioritas, terutama pada layanan kesehatan yang harus menangani pasien berdasarkan tingkat urgensi. Oleh karena itu, beberapa penelitian menggabungkan algoritma FIFO dengan Descending Priority Queue, yaitu struktur antrean yang memproses elemen berdasarkan tingkat prioritas tertinggi terlebih dahulu [3]. Kombinasi kedua pendekatan ini meningkatkan fleksibilitas sistem dalam menghadapi berbagai kondisi layanan, termasuk penanganan pasien yang terlewat saat pemanggilan atau yang membutuhkan atensi khusus [3].

Secara keseluruhan, Queue, Circular Queue, dan Priority Queue merupakan struktur data yang mampu mengoptimalkan pengelolaan antrean dalam berbagai sistem layanan. Ketiganya mendukung efisiensi waktu tunggu, mengurangi kesalahan pencatatan, serta meningkatkan pengalaman pengguna, terutama dalam layanan berbasis web yang membutuhkan pemrosesan cepat, terstruktur, dan dinamis [1][2][3].

### A. Guided<br/>
...
#### 1. guided 1
#### 2. guided 2

### B. Unguided<br/>
...
#### 1. unguided 1
#### 2. unguided 2
#### 3. unguided 3

## Guided 

### 1. guided 1

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

queue.cpp
```C++
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
```

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

void CreateQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, const string &name);
void deQueue(Queue &Q);
void viewQueue(Queue Q);
void clearQueue(Queue &Q);

#endif
```

Program ini terdiri dari tiga file: queue.h, queue.cpp, dan main.cpp. 
Pada file header, didefinisikan struktur Node yang menyimpan data berupa string dan pointer ke node berikutnya, serta struktur Queue yang memiliki pointer head dan tail sebagai penanda elemen depan dan belakang. Fungsi-fungsi utama yang digunakan meliputi CreateQueue untuk inisialisasi queue, isEmpty untuk mengecek kekosongan, enQueue untuk menambahkan data di bagian belakang dengan membuat node baru, deQueue untuk menghapus elemen dari depan queue, viewQueue untuk menampilkan seluruh isi queue dengan melakukan traversal dari head, serta clearQueue untuk menghapus semua node guna mencegah memory leak. Pada main.cpp, program membuat sebuah queue kemudian menambahkan enam nama menggunakan enQueue, menampilkan isi queue, menghapus empat elemen dari depan menggunakan deQueue, dan kembali menampilkan isi queue setelah penghapusan. Terakhir, program memanggil clearQueue untuk membersihkan seluruh data sebelum program selesai.

### 2. guided 2

main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

Program mengimplementasikan struktur data Queue berbasis array statis dengan kapasitas lima elemen menggunakan prinsip FIFO. Struktur queue menyimpan data berupa array nama[] serta indeks head dan tail sebagai penanda elemen depan dan belakang. Fungsi CreateQueue menginisialisasi queue dengan head = -1 dan tail = -1, sementara isEmpty dan isFull digunakan untuk mengecek kondisi antrean. Proses penambahan data melalui enQueue akan menempatkan elemen baru di posisi tail, dan jika queue kosong maka head dan tail di-set ke 0. Proses deQueue menghapus elemen paling depan dan menggeser seluruh elemen ke kiri untuk menjaga posisi head tetap di indeks 0. Fungsi viewQueue menampilkan isi queue dari head hingga tail. Pada main.cpp, program menambahkan beberapa data menggunakan enQueue, menampilkan isi queue, kemudian menghapus empat data menggunakan deQueue, dan kembali menampilkan kondisi queue setelah penghapusan.

## Unguided 

### 1. Unguided 1

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return temp;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 -1 | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan8_Modul8/output/unguided1.jpg)

Program mengimplementasikan struktur data Queue berbasis array menggunakan mekanisme Alternatif 1 (head diam, tail bergerak). Pada queue.h, didefinisikan struktur Queue yang terdiri dari array tetap berukuran 5, serta variabel head dan tail sebagai penanda posisi antrean. File queue.cpp berisi fungsi-fungsi utama seperti createQueue() untuk inisialisasi antrean kosong, enqueue() untuk menambahkan elemen dengan menaikkan tail, serta dequeue() yang menghapus elemen paling depan dan menggeser seluruh elemen ke kiri agar head tetap berada pada posisi awal. Fungsi pemeriksaan seperti isEmptyQueue() dan isFullQueue() memastikan operasi dilakukan sesuai kondisi antrean, sedangkan printInfo() menampilkan isi queue beserta posisi head dan tail. Pada main.cpp, serangkaian operasi enqueue dan dequeue dijalankan untuk menunjukkan bahwa queue bekerja sesuai konsep FIFO (First In First Out), dan bagaimana perubahan isi antrean terjadi setelah setiap operasi.

### 2. Unguided 2 

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = Q.tail = -1;
    }

    return temp;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 -1 | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

##### Output Unguided 2 
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan8_Modul8/output/unguided2.jpg)

Program mengimplementasikan struktur data Queue menggunakan array dengan mekanisme Alternatif 2, yaitu head dan tail sama-sama bergerak tanpa proses penggeseran elemen. Pada file queue.h, didefinisikan struktur Queue yang memiliki array berukuran tetap serta dua indeks, head dan tail, sebagai penanda batas antrean. File queue.cpp memuat fungsi‐fungsi utama, seperti createQueue() untuk inisialisasi antrean kosong, enqueue() untuk menambahkan elemen baru dengan menaikkan nilai tail, serta dequeue() yang menghapus elemen paling depan dengan menaikkan nilai head tanpa menggeser isi array. Ketika head melewati tail, antrean kembali diset menjadi kosong. Fungsi isEmptyQueue() dan isFullQueue() digunakan untuk memeriksa kondisi antrean, sedangkan printInfo() menampilkan isi Queue beserta posisi head dan tail. Dalam main.cpp, program menguji seluruh operasi dengan melakukan beberapa kali enqueue dan dequeue.

### 3. Unguided 3

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```

queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return temp;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 -1 | empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << " | ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

##### Output Unguided 3
![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan8_Modul8/output/unguided3.jpg)

Program mengimplementasikan struktur data Queue berbasis array menggunakan mekanisme Alternatif 3 (circular queue), yaitu head dan tail bergerak secara melingkar di dalam array sehingga ruang penyimpanan dapat digunakan lebih efisien tanpa perlu melakukan pergeseran elemen. Pada queue.h, didefinisikan array berukuran tetap beserta indeks head dan tail sebagai penunjuk posisi data pertama dan terakhir. File queue.cpp mengimplementasikan fungsi-fungsi penting, seperti createQueue() untuk inisialisasi antrean kosong, enqueue() untuk menambahkan elemen baru dengan perhitungan (tail + 1) % MAX sehingga tail dapat kembali ke indeks awal ketika mencapai batas array, dan dequeue() untuk menghapus elemen depan dengan memajukan head secara melingkar menggunakan rumus yang sama. Kondisi penuh dicek dengan membandingkan posisi tail berikutnya dengan head, sedangkan kondisi kosong dicek ketika head bernilai -1. Fungsi printInfo() menampilkan seluruh isi queue dengan cara mengiterasi secara melingkar hingga bertemu kembali dengan posisi tail. Pada main.cpp, operasi enqueue dan dequeue dieksekusi untuk menunjukkan mekanisme FIFO pada circular queue dan bagaimana indeks head maupun tail berpindah dalam struktur melingkar.

## Kesimpulan

Struktur data memegang peranan penting dalam membangun sistem antrean yang efisien dan reliabel. Queue sebagai struktur dasar dengan prinsip FIFO menjadi fondasi utama dalam berbagai layanan karena mampu menjaga urutan pelayanan secara adil. Variasi seperti Circular Queue menawarkan efisiensi lebih tinggi dalam pemanfaatan memori dan kelancaran proses antrean, terutama pada sistem berskala besar dan real-time. Sementara itu, Priority Queue memberikan fleksibilitas tambahan untuk menangani kondisi tertentu yang memerlukan pengolahan berdasarkan tingkat urgensi, seperti pada sistem kesehatan. Dengan penerapan yang tepat, ketiga jenis struktur antrean ini mampu meningkatkan kinerja sistem, mempercepat proses pelayanan, serta mengurangi potensi kesalahan, sehingga menciptakan alur pelayanan yang lebih optimal dan responsif.

## Referensi

[1] Akbar Alif Haikal, dkk. (tanpa tahun). Implementasi Struktur Data Queue dan Stack dalam Sistem Antrian Kasir Cafe Berbasis Web. JUPIKOM: Jurnal Pendidikan dan Informatika. Diakses melalui https://journalcenter.org/index.php/jupikom/article/view/5524/4397

<br>[2] Nur Aini, Kurniawan R. (tanpa tahun). Sistem Antrian Pasien Berbasis Web dengan Algoritma Circular Queue. CESS (Journal of Computer Engineering, System and Science). Diakses melalui https://jurnal.unimed.ac.id/2012/index.php/cess/article/view/67447/27654

<br>[3] Efrans Christian, dkk. (tanpa tahun). Implementasi Algoritma FIFO dan Descending Priority Queue pada Sistem Antrian Pelayanan Kesehatan Puskesmas. JTI: Jurnal Teknik Informatika. Diakses melalui https://e-journal.upr.ac.id/index.php/JTI/article/view/19246/6892