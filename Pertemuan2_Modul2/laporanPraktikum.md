# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Bahasa pemrograman merupakan sarana utama untuk berinteraksi dengan komputer melalui instruksi logis yang terstruktur [1].
Konsep penting dalam C++ adalah pointer, yaitu variabel yang menyimpan alamat memori suatu variabel, bukan nilainya [1]. 
Pointer memungkinkan manipulasi data secara langsung dan efisien. Selain itu, reference berfungsi sebagai alias dari variabel lain, sehingga perubahan pada reference juga memengaruhi variabel aslinya [1].

Dalam fungsi, parameter dapat dikirim by value atau by reference. Pada by value, nilai disalin tanpa memengaruhi data asli, sedangkan pada by reference, alamat memori variabel dikirim sehingga perubahan di fungsi berdampak langsung pada data asli [2]. Pointer juga dapat digunakan sebagai parameter fungsi untuk memodifikasi data secara langsung melalui alamat memori [3].

### A. Guided<br/>
...
#### 1. Array 1 Dimensi 
#### 2. Array 2 Dimensi 
#### 3. Function & Procedure
#### 4. Pointer
#### 5. Reference

### B. Unguided<br/>
...
#### 1. Tugas 1
#### 2. Tugas 2 Pointer
#### 3. Tugas 2 Reference
#### 3. Tugas 3

## Guided 

### 1. Array 1 Dimensi 

```C++
#include<iostream>
using namespace std;

int main (){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5){
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program menggunakan array satu dimensi. Pengguna diminta memasukkan nilai untuk setiap indeks array melalui perulangan for, lalu semua nilai dimasukkan, program menampilkan kembali isi array menggunakan perulangan while. 

### 2. Array 2 Dimensi 

```C++
#include<iostream>
using namespace std;


void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil (arrC);
    
    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program menggunakan array dua dimensi (matriks) berukuran 2x2 untuk melakukan operasi penjumlahan dan perkalian matriks. Terdapat dua matriks awal, yaitu arrA dan arrB. Matriks arrC digunakan untuk menyimpan hasil penjumlahan, sedangkan arrD menyimpan hasil perkalian. Perhitungan menggunakan nested loop (perulangan bersarang), lalu hasilnya ditampilkan melalui fungsi tampilkanHasil().

### 3. Function & Procedure

```C++
#include <iostream>

using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan: " << totalJumlah << endl;
    
    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian: " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program menggunakan function dan procedure. Function cariMAX() digunakan untuk mencari nilai terbesar dari elemen array dengan cara membandingkan setiap elemen menggunakan perulangan.Procedure operasiAritmatika() digunakan untuk menghitung total penjumlahan dan total perkalian dari seluruh elemen array, kemudian menampilkannya ke layar.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    tukar(&a, &b);
    cout << "after swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Program menggunakan pointer untuk menukar nilai dua variabel melalui fungsi swap yang menerapkan metode pass-by-reference. Variabel ptr menyimpan alamat memori dari variabel a, sehingga nilai a dapat diakses melalui *ptr. Fungsi tukar() menerima dua parameter pointer (int *x dan int *y) untuk menukar nilai dari variabel yang ditunjuk menggunakan variabel sementara temp.

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar (int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
} 

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;
    
    ref = 50;
    cout << "\nSetelah ref = 50" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Program menggunakan reference untuk menukar nilai dua variabel melalui fungsi tukar() yang menerapkan metode pass-by-reference. Variabel ref merupakan referensi (alias) dari variabel a, sehingga perubahan pada ref secara langsung mengubah nilai a. Fungsi tukar() menerima dua parameter reference (int &x dan int &y) untuk menukar nilai variabel tanpa perlu mengakses alamat memori seperti pada pointer, melainkan dengan mengacu langsung pada variabel aslinya.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << "\t"; 
        }
        cout << endl;
    }
}

int main() {
    int matriksA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriksB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};  

    //penjumlahan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
    cout << "Hasil Penjumlahan: " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    //pengurangan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrD[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
    cout << "Hasil Pengurangan: " << endl;
    tampilkanHasil(arrD);
    cout << endl;

    //perkalian matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrE[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 3; i++) {      
        for (int j = 0; j < 3; j++) {   
            for (int k = 0; k < 3; k++) { 
                arrE[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian: " << endl;
    tampilkanHasil(arrE);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan2_Modul2/output/Output-Modul2-Unguided1.jpg)

Program melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3. Hasil penjumlahan disimpan di arrC, pengurangan di arrD, dan perkalian di arrE. Penjumlahan dan pengurangan dilakukan dengan mengoperasikan elemen-elemen yang seposisi, sedangkan perkalian menggunakan metode perkalian (baris x kolom) dengan nested loop.

### 2. Berdasarkan guided pointer, buatlah dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukar (int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
} 

int main() {
    int a = 20, b = 30, c=40;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    tukar(&a, &b, &c);
    cout << "after swapping, value of a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan2_Modul2/output/Output-Modul2-Unguided2ptr.jpg)

Program menukar nilai dari tiga variabel (a, b, dan c) menggunakan pointer. Fungsi tukar() menerima alamat dari ketiga variabel tersebut dan melakukan pertukaran nilai, nilai a ditukar ke c, b ke a, dan c ke b dengan variabel sementara. 

### 3. Berdasarkan guided reference, buatlah dapat menukar nilai dari 3 variabel
```C++
#include <iostream>
using namespace std;

void tukar (int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;

} 

int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;
    
    ref = 50;
    cout << "\nSetelah ref = 50" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "After swapping, value of a = " << a << " b = " << b << " c =" << c << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan2_Modul2/output/Output-Modul2-Unguided2ref.jpg)

Program menukar nilai dari tiga variabel (a, b, dan c) menggunakan reference. Fungsi tukar() menerima referensi ke ketiga variabel tersebut dan melakukan pertukaran nilai, nilai a ditukar ke c, b ke a, dan c ke b dengan variabel sementara.

### 4. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} . Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata!

```C++
#include <iostream>
using namespace std;

const int N = 10;
int arrA[N] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void hitungRataRata(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rata = total / n;
    cout << "nilai rata-rata = " << rata << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Program Array\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < N; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, N) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, N) << endl;
                break;
            case 4:
                hitungRataRata(arrA, N);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 4 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan2_Modul2/output/Output-Modul2-Unguided3.jpg)

Program berfungsi untuk menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung nilai rata-rata. Data array disimpan dalam variabel arrA dengan nilai awal yang telah ditentukan. Fungsi cariMinimum() digunakan untuk menemukan nilai terkecil, sedangkan cariMaksimum() digunakan untuk mencari nilai terbesar. Fungsi hitungRataRata() menjumlahkan seluruh elemen array dan membaginya dengan jumlah elemen untuk memperoleh nilai rata-rata. Program menggunakan perulangan do-while dan switch-case untuk menampilkan menu.

## Kesimpulan
Pointer dan reference merupakan konsep penting dalam pemrograman C++ yang berfungsi untuk mengelola data melalui alamat memori. Keduanya memungkinkan efisiensi dalam pemrosesan data dan komunikasi antar fungsi. Melalui penerapan konsep-konsep tersebut, efisiensi memori, kecepatan eksekusi, dan fleksibilitas dalam pengembangan aplikasi dapat ditingkatkan.

## Referensi
[1] Putra, M. T. Dwi, Munawir, & Ana Rahma Yuniarti. (2023). Belajar Pemrograman Lanjut dengan C++. Penerbit Widina Media Utama. Diakses pada 4 Oktober 2025 melalui https://www.scribd.com/document/842224530/564507-belajar-pemrograman-lanjut-dengan-c-f577301

<br>[2] Syafii, M. (2021). Pemrograman Komputer Menggunakan C++. Universitas Andalas. Diakses pada 4 Oktober 2025 melalui http://repo.unand.ac.id/32011/

<br>[3] Moenawar. (2018). Pointer dan Fungsi (SD Lab 5–6). Diakses pada 4 Oktober 2025 melalui http://moenawar.web.id/wp-content/uploads/2018/03/SD-Lab-5-6-pointer-dan-fungsi.pdf


