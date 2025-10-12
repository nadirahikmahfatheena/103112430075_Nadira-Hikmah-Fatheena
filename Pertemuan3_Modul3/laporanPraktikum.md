# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Bahasa pemrograman memungkinkan interaksi dengan komputer melalui instruksi logis. Dalam C++, pointer menyimpan alamat memori variabel sehingga data dapat dimodifikasi langsung, sedangkan reference berperan sebagai alias variabel [1]. Struct adalah tipe data bentukan yang mengelompokkan beberapa variabel terkait menjadi satu kesatuan [2].

Parameter fungsi dapat dikirim by value (salinan) atau by reference/pointer (alamat memori) sehingga perubahan memengaruhi data asli [2]. C++ mendukung file terpisah seperti main.cpp, pelajaran.cpp, dan pelajaran.h, di mana file header berisi deklarasi fungsi, variabel global, dan konstanta, sedangkan file implementasi berisi definisi fungsi, sehingga program menjadi modular dan mudah dikembangkan [1].

### A. Guided<br/>
...
#### 1. Struct
#### 2. contoh 1

### B. Unguided<br/>
...
#### 1. Tugas 1
#### 2. Tugas 2 
#### 3. Tugas 3

## Guided 

### 1. Struct

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return float (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan prosedur
    cout << "Rata rata : " << rata2(mhs); //pemanggilan function
    return 0;
}
```
Program struct ini berguna untuk menyimpan dan mengolah data mahasiswa. Program ini menunjukkan penggunaan struct, fungsi, dan parameter referensi untuk memisahkan proses input, perhitungan, serta output secara terstruktur dan efisien.

### 2. Contoh 1

```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel =  create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

//pelajaran.cpp
#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//pelajaran.h
//header guard digunakan untuk mencegah file header yang sama di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```

Program ini dibagi menjadi tiga bagian, yaitu main.cpp, pelajaran.cpp, dan pelajaran.h. 
Pada:

File pelajaran.h, dideklarasikan Abstract Data Type (ADT) bernama pelajaran yang memiliki dua atribut, yaitu namaMapel dan kodeMapel. File ini juga berisi deklarasi fungsi create_pelajaran() untuk membuat data pelajaran baru dan prosedur tampil_pelajaran() untuk menampilkan data tersebut. 

File pelajaran.cpp berisi implementasi dari fungsi dan prosedur tersebut. Fungsi create_pelajaran() menerima dua parameter berupa nama dan kode pelajaran, lalu mengembalikan data bertipe pelajaran. Prosedur tampil_pelajaran() menampilkan isi data pelajaran ke layar. 

File main.cpp, merupakan program utama membuat variabel namapel dan kodepel, lalu memanggil fungsi create_pelajaran() untuk membentuk objek pelajaran, dan menampilkannya menggunakan prosedur tampil_pelajaran().

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3uts+0.4uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct Mhs{
    string nama;
    string nim;
    int uts;
    int uas;
    int tugas;
    float nilaiAkhir;
};

float hitungNilai(Mhs mhs){
    return 0.3 * mhs.uts + 0.4 * mhs.uas + 0.3 * mhs.tugas;
} 

void inputMhs(Mhs &mhs){
    cout << "Nama: ";
    cin >> mhs.nama;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "UTS: ";
    cin >> mhs.uts;
    cout << "UAS: ";
    cin >> mhs.uas;
    cout << "Tugas: ";
    cin >> mhs.tugas;

    mhs.nilaiAkhir = hitungNilai(mhs);
}

void outputMhs(Mhs mhs[], int n){
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "-----------------------------";
    }
    cout << endl;
}

int main(){
    Mhs mhs[10];
    int n;

    cout << "Masukan data mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Melewati batas max! (10)" << endl;
        return 0;
    } else{
        for (int i = 0; i < n; i++) {
            cout << "\nData Mahasiswa ke-" << i + 1 << endl;
            inputMhs(mhs[i]);
        }
    }

    outputMhs(mhs, n);
    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan3_Modul3/output/tugas1.jpg)

Program ini menggunakan struct dan array of struct untuk menyimpan serta menampilkan data nilai beberapa mahasiswa. Struct Mhs berisi atribut nama, nim, uts, uas, tugas, dan nilaiAkhir. Fungsi hitungNilai() menghitung nilai akhir berdasarkan rumus 30% UTS, 40% UAS, dan 30% tugas. Prosedur inputMhs() menerima data mahasiswa sekaligus menghitung nilai akhirnya, sedangkan outputMhs() menampilkan seluruh data yang telah dimasukkan.

### 2. Tugas2

```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel =  create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

//pelajaran.cpp
#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

//pelajaran.h
//header guard digunakan untuk mencegah file header yang sama di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```

### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan3_Modul3/output/tugas2.jpg)

Program ini dibagi menjadi tiga bagian, yaitu main.cpp, pelajaran.cpp, dan pelajaran.h. 
Pada:

File pelajaran.h, dideklarasikan Abstract Data Type (ADT) bernama pelajaran yang memiliki dua atribut, yaitu namaMapel dan kodeMapel. File ini juga berisi deklarasi fungsi create_pelajaran() untuk membuat data pelajaran baru dan prosedur tampil_pelajaran() untuk menampilkan data tersebut. 

File pelajaran.cpp berisi implementasi dari fungsi dan prosedur tersebut. Fungsi create_pelajaran() menerima dua parameter berupa nama dan kode pelajaran, lalu mengembalikan data bertipe pelajaran. Prosedur tampil_pelajaran() menampilkan isi data pelajaran ke layar. 

File main.cpp, merupakan program utama membuat variabel namapel dan kodepel, lalu memanggil fungsi create_pelajaran() untuk membentuk objek pelajaran, dan menampilkannya menggunakan prosedur tampil_pelajaran().

### 3. Buatlah program dengan ketentuan : 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer, fungsi/prosedur yang menampilkan isi sebuah array integer 2D, fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu, fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilArr(int data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarNilai(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrayB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "array A:" << endl;
    tampilArr(arrayA);
    cout << endl << "array B:" << endl;
    tampilArr(arrayB);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp = arrayA[i][j];
            arrayA[i][j] = arrayB[i][j];
            arrayB[i][j] = temp;
        }
    }

    cout << "array A setelah ditukar (manual):" << endl;
    tampilArr(arrayA);
    cout << "array B setelah ditukar (manual):" << endl;
    tampilArr(arrayB);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tukarNilai(&arrayA[i][j], &arrayB[i][j]);
        }
    }

    cout << "array A setelah ditukar (pointer):" << endl;
    tampilArr(arrayA);
    cout << "array B setelah ditukar (pointer):" << endl;
    tampilArr(arrayB);

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan3_Modul3/output/tugas3.jpg)

Program ini berisi dua array 3×3 (arrayA dan arrayB) yang isinya ditukar dengan dua cara, yaitu secara manual menggunakan variabel sementara (temp) dan menggunakan fungsi tukarNilai() yang menggunakan pointer. Fungsi tukarNilai(int *a, int *b) menerima dua parameter berupa alamat memori dari elemen yang akan ditukar. Operator * digunakan untuk mengakses nilai yang tersimpan di alamat tersebut. Di dalam fungsi, nilai dari alamat a disimpan sementara di variabel temp, kemudian nilai di alamat b dipindahkan ke alamat a, dan terakhir nilai temp dikembalikan ke alamat b.

## Kesimpulan
Pointer memungkinkan pengelolaan data secara langsung melalui alamat memori, sedangkan struct mempermudah pengelolaan data yang terkait. Pengiriman parameter fungsi secara by value atau by reference/pointer memengaruhi cara data diproses. Selain itu, penggunaan file terpisah seperti main.cpp, pelajaran.cpp, dan pelajaran.h mendukung modularitas program, memudahkan pengembangan, serta pemeliharaan kode.

## Referensi
[1] Putra, M. T. Dwi, Munawir, & Ana Rahma Yuniarti. (2023). Belajar Pemrograman Lanjut dengan C++. Penerbit Widina Media Utama. Diakses pada 12 Oktober 2025 melalui https://www.scribd.com/document/842224530/564507-belajar-pemrograman-lanjut-dengan-c-f577301

<br>[2] Syafii, M. (2021). Pemrograman Komputer Menggunakan C++. Universitas Andalas. Diakses pada 12 Oktober 2025 melalui http://repo.unand.ac.id/32011/

<br>[3] Moenawar. (2018). Pointer dan Fungsi (SD Lab 5–6). Diakses pada 12 Oktober 2025 melalui http://moenawar.web.id/wp-content/uploads/2018/03/SD-Lab-5-6-pointer-dan-fungsi.pdf


