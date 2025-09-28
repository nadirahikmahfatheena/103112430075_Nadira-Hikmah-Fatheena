# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Bahasa pemrograman merupakan salah satu komponen utama dalam dunia komputasi modern. Melalui bahasa pemrograman, manusia dapat berkomunikasi dengan komputer menggunakan instruksi yang sudah terstandar [1]. Instruksi ini kemudian diterjemahkan oleh komputer menjadi serangkaian proses untuk menyelesaikan suatu perintah. Dalam praktiknya, bahasa pemrograman tidak hanya digunakan di bidang teknologi, tetapi juga banyak dimanfaatkan dalam pendidikan, ekonomi, bisnis, bahkan sosial budaya sebagai sarana membangun sistem aplikasi yang sesuai dengan kebutuhan pengguna [1]. Salah satu bahasa yang banyak digunakan hingga saat ini adalah C++, yaitu bahasa pemrograman yang dikembangkan dari bahasa C dengan konsep hybrid, sehingga lebih fleksibel dalam membangun berbagai jenis aplikasi [1].

Selain pemahaman tentang bahasa, dasar dari pemrograman adalah logika perhitungan. Dalam hal ini, operator aritmatika menjadi salah satu elemen penting karena memungkinkan program melakukan operasi matematis seperti penjumlahan, pengurangan, perkalian, dan pembagian [2]. Operator ini membantu programmer menyusun algoritma yang lebih kompleks, misalnya untuk pengolahan data, pemodelan, maupun perhitungan matematis yang dibutuhkan dalam suatu aplikasi. Untuk mempermudah implementasi, perhitungan biasanya menggunakan tipe data dasar seperti integer (int), sehingga komputer dapat mengolah bilangan bulat dengan lebih cepat dan efisien [2].

Lebih lanjut, konsep rekursi juga menjadi bagian fundamental dalam pemrograman. Rekursi adalah teknik pemanggilan fungsi yang memanggil dirinya sendiri secara berulang [3]. Konsep ini sangat bermanfaat untuk menyelesaikan masalah yang bersifat berulang atau memiliki pola berlapis, misalnya pada perhitungan faktorial, deret Fibonacci, maupun algoritma pencarian dan pengurutan. Dengan rekursi, programmer dapat menuliskan solusi yang lebih ringkas dan elegan, meskipun pada implementasinya tetap perlu diperhatikan aspek efisiensi penggunaan memori.

### A. Guided<br/>

#### 1. Hello World 
#### 2. Input Output
#### 3. Operator Aritmatika
#### 4. For
#### 5. While
#### 6. Percabangan
#### 7. Struct

### B. Unguided<br/>

#### 1. Tugas 1
#### 2. Tugas 2
#### 3. Tugas 3

## Guided 

### 1. Hello World

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```
Program menampilkan output berupa teks "Hello, World!" ke layar.

### 2. Input Output

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "input angka: " ;
    cin >> angka;

    cout << "angka yang diinput " << angka << endl;
    return 0;
}
```
Program berguna untuk menerima masukan dan menampilkan output sesuai dengan inputan. Input pada program berupa angka dan akan ditampilkan kembali ke layar.

### 3. Operator Aritmatika

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;

cout << "Masukkan angka1: ";
cin >> angka1;
cout << "Masukkan angka2: ";
cin >> angka2;

//penjumlahan 
cout << "penjumlahan: " << angka1 + angka2 << endl;
//pengurangan
cout << "pengurangan: " << angka1 - angka2 << endl;
//perkalian 
cout << "perkalian: " << angka1 * angka2 << endl;
//pembagian 
cout << "pembagian: " << angka1 / angka2 << endl;
//modulus
cout << "modulus: " << angka1 % angka2 << endl;
return 0;
}
```
Program menerima input dua angka dan menampilkan hasil dari lima operasi aritmetika dasar yaitu penjumlahan, pengurangan, perkalian, pembagian, dan modulus.

### 4. For

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    for (int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    
    cout << endl;
    
    for (int i = angka1; i >= 0; i--) { //decrement
        cout << i << " - ";
    }
    
    return 0;
}
```
Program menerima input angka, dan akan menampilkan deret angka naik dari 0 hingga sebelum angka tersebut dan deret angka turun dari angka input hingga 0.

### 5. While

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //increment
    int i = 0;
    while (i <= angka1) {
        cout << i << " - ";
        i++;
    }
    
    cout << endl;

    //decrement
    int j = angka2;
    do {
        cout << j << " - ";
        j--;
    } while (j >= 0);
    
    return 0;
}
```
Program menerima dua input angka lalu menampilkan deret angka naik dari 0 hingga angka1 menggunakan while, lalu menampilkan deret angka turun dari angka2 hingga 0 menggunakan do while.

### 6. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;

    cout << "Masukkan angka1: ";
    cin >> angka1;
    cout << "Masukkan angka2: ";
    cin >> angka2;

    if (angka1 > angka2){
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    }else if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    }else if (angka1 < angka2){
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    }
    
    if (angka1 != angka2){
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }
    return 0;
}
```
Program menggunakan struktur percabangan if else untuk membandingkan dua bilangan yang dimasukkan pengguna. Pertama, program mengecek apakah angka1 lebih besar, sama dengan, atau lebih kecil dari angka2, kemudian menampilkan hasil perbandingannya. Selain itu, terdapat percabangan tambahan dengan kondisi if (angka1 != angka2) untuk menampilkan pesan bahwa kedua bilangan tidak sama apabila nilai angka1 dan angka2 berbeda.

### 7. Struct

```C++
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

   struct rapot{
    char nama[5]; 
    int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++){
        cout << "Masukkan nama siswa: " ;
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: " ;
        cin >> siswa[i].nilai;
    }

    int i = 0;
    while (i < jumlah){
        cout << "Nama: " << siswa[i].nama << " Nilai: " << siswa[i].nilai << endl;
        i++;
    }
    
    return 0;
}
```
Program dengan struct rapot yang berisi atribut nama dan nilai, lalu menyimpan data lima siswa dalam array siswa. Menggunakan perulangan for, program meminta input nama dan nilai setiap siswa, kemudian menampilkannya kembali dengan perulangan while. 

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main() {
    float angka1, angka2;

    cout << "masukkan angka 1: ";
    cin >> angka1;

    cout << "masukkan angka 2: ";
    cin >> angka2;

    //penjumlahan
    cout << "penjumlahan: " << angka1 << " + " << angka2 << " = " << angka1 + angka2 << endl;
    //pengurangan
    cout << "pengurangan: " << angka1 << " - " << angka2 << " = " << angka1 - angka2 << endl;
    //perkalian 
    cout << "perkalian: " << angka1 << " * " << angka2 << " = " << angka1 * angka2 << endl;
    //pembagian
    if ( angka2 != 0 ) {
        cout << "pembagian: " << angka1 << " / " << angka2 << " = " << angka1 / angka2 << endl;
    } else {
        cout << "pembagian: undefined karena pembagi 0" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan1_Modul1/output/Output-Unguided1.jpg)

Program ini menerima input dua bilangan bertipe float, kemudian menghitung hasil penjumlahan, pengurangan, perkalian, dan pembagian dari kedua bilangan tersebut. Pada bagian pembagian, program menambahkan pengecekan kondisi agar tidak terjadi pembagian dengan nol, sehingga jika nilai pembagi adalah nol, output akan menampilkan pesan “undefined karena pembagi 0”. 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>
#include <string>

using namespace std;

string ubahAngka(int n) {
    switch (n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        case 10: return "sepuluh";
        case 11: return "sebelas";
        default: return ""; 
    }
}

int main() {
    int a;

    cout << "input angka (dalam rentang 0-100): ";
    cin >> a;

    cout << a << ": ";
    if (a < 0 || a > 100) {
        cout << "angka tidak dalam rentang 0-100" << endl;
    } else {
        string hasil;

        if (a < 12) {
            hasil = ubahAngka(a);
        } else if (a < 20) {
            hasil = ubahAngka(a % 10) + " belas";
        } else if (a < 100) {
            int puluhan = a / 10;
            int sisa = a % 10;
            if (sisa == 0) {
                hasil = ubahAngka(puluhan) + " puluh";
            } else {
                hasil = ubahAngka(puluhan) + " puluh " + ubahAngka(sisa);
            }
        } else {
            hasil = "seratus";
        }
        cout << hasil << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan1_Modul1/output/Output-Unguided2.jpg)

Program ini mengonversi input bilangan bulat positif dari 0 hingga 100 menjadi bentuk tulisan. Konversi angka dalam rentang 0–11 dilakukan melalui fungsi ubahAngka(), sedangkan bilangan 12–19 ditampilkan dalam format “... belas”, bilangan 20–99 dalam format “... puluh ...”, dan angka 100 sebagai “seratus”. Jika input berada di luar rentang 0–100, program akan menampilkan pesan "angka tidak dalam rentang 0-100".

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "input: ";
    cin >> a;
    
    cout << "output: " << endl;

    for (int i = a; i >= 1; i--) {

        for (int j = 1; j <= a - i; j++) {
            cout << "  ";
        }
        
        for (int k = i; k >= 1; k--) {
            cout << k << " ";
        }

        cout << "* ";

        for (int l = 1; l <= i; l++) {
            cout << l << " ";
        }

        cout << endl;
    }

    for (int m = 1; m <= a; m++) {
        cout << "  ";
    }
    
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan1_Modul1/output/Output-Unguided3.jpg)

Program menerima bilangan bulat positif, lalu membentuk pola segitiga simetris dengan angka menurun di sebelah kiri, simbol bintang * di tengah, dan angka menaik di sebelah kanan. Pola dibuat menggunakan perulangan for, pada bagian pertama menampilkan baris angka menurun dan menaik yang dipisahkan oleh bintang, sedangkan bagian kedua menampilkan satu bintang di bagian bawah setelah seluruh pola tercetak.

## Kesimpulan
Dapat disimpulkan bahwa bahasa pemrograman C++ merupakan sarana  yang efektif untuk mengubah logika manusia menjadi instruksi yang dapat dijalankan komputer. Konsep dasar seperti operator aritmatika digunakan dalam perhitungan matematis sederhana untuk memudahkan pemrogram dalam menyusun logika program. Selain itu, penyelesaian masalah berulang dapat dilakukan melalui rekursi maupun perulangan yang berperan penting dalam membangun algoritma yang ringkas dan terstruktur.

## Referensi
[1] Adnyana, I. B. P. A., & Sugihartini, N. (2017). “Media Pembelajaran Bahasa Pemrograman C++”. Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), 14(2), 1–12. Universitas Pendidikan Ganesha. Diakses pada 26 September 2025 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31/25

<br>[2] Lubis, L. A., & Ramadhani, A. A. R. (2019). “Analisis Studi Literatur Penyelesaian Operator Aritmatika Serta Bilangan Bulat Dengan Code Sederhana Pada Bahasa Pemrograman C++”. SABER : Jurnal Teknik Informatika, Sains dan Ilmu Komunikasi, 1(2), 76–83. STIKes Ibnusina Batam. Diakses pada 26 September 2025 melalui https://jurnal.stikes-ibnusina.ac.id/index.php/SABER/article/view/604/577

<br>[3] Choerun A. & Chanief B.S. (2020). “Rekursi dalam Pemrograman”. Jurnal Teknomatika, Universitas Jenderal Achmad Yani Yogyakarta. Diakses pada 26 September 2025 melalui https://ejournal.unjaya.ac.id/index.php/teknomatika/article/view/368/310

