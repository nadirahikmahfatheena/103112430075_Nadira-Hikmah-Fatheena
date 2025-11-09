# <h1 align="center">Laporan Praktikum Modul 7</h1>
<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori
Struktur data memainkan peran krusial dalam pengembangan perangkat lunak modern [1]. Salah satu struktur data yang penting adalah Stack, atau tumpukan, yang merupakan struktur data linier dengan prinsip Last In First Out (LIFO) [1]. Artinya, elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan [1]. Konsep ini sering dianalogikan seperti tumpukan baju di lemari atau tumpukan nampan di kafetaria [1]. Stack banyak digunakan dalam berbagai aplikasi pemrograman seperti evaluasi ekspresi matematika, manajemen memori, dan implementasi fitur undo/redo [1].

Struktur data Stack dapat diimplementasikan menggunakan dua pendekatan utama, yaitu Array dan Linked List [1]. Array merupakan tipe data terstruktur yang menyimpan sekumpulan data dengan tipe yang sama dalam lokasi memori yang berurutan, memungkinkan akses langsung ke elemen melalui indeks [1][2].

Meskipun konsep struktur data seperti Stack dan Queue bersifat fundamental, keduanya sering kali sulit dipahami oleh mahasiswa [3]. Oleh karena itu, penggunaan media pembelajaran berbasis komputer seperti visualisasi interaktif dapat membantu mempercepat pemahaman terhadap konsep tersebut [3]. Selain itu, struktur data seperti Stack dan Array juga menjadi dasar bagi penerapan algoritma praktis, misalnya dalam pengurutan data menggunakan Selection Sort untuk mengelola dan menampilkan data secara terurut [2].

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
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

Program merupakan implementasi struktur data Stack menggunakan Linked List yang bersifat dinamis dengan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dihapus. Struktur data node digunakan untuk menyimpan data integer (dataAngka) dan pointer ke elemen berikutnya (next), sedangkan struktur stack menyimpan pointer top sebagai penunjuk elemen teratas. Program diawali dengan inisialisasi stack kosong menggunakan createStack(), kemudian beberapa elemen dialokasikan dengan alokasi() dan dimasukkan ke stack menggunakan push(). Operasi pop() digunakan untuk menghapus elemen teratas stack, update() berfungsi mengubah nilai data pada posisi tertentu, sedangkan view() menampilkan seluruh isi stack dari atas ke bawah, dan searchData() mencari data tertentu di dalam stack beserta posisinya. Selama eksekusi, program menampilkan proses penambahan, penghapusan, pembaruan, serta pencarian elemen.

### 2. guided 2

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
 stackTable s;
 createStack(s);

 push(s, 1);
 push(s, 2);
 push(s, 3);
 push(s, 4);
 push(s, 5);
 cout << endl;

 cout << "--- Stack setelah push ---" << endl;
 view(s);
 cout << endl;

 pop(s);
 pop(s);
 cout << endl;

 cout << "--- Stack setelah pop 2 kali ---" << endl;
 view(s);
 cout << endl;

 // Posisi dihitung dari TOP (1-based)
 update(s, 2);
 update(s, 1);
 update(s, 4);
 cout << endl;

 cout << "--- Stack setelah update ---" << endl;
 view(s);
 cout << endl;

 searchData(s, 4);
 searchData(s, 9);

 return 0;
}
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
    cout << "Stack penuh!" << endl;
    }
    else {
    s.top++;
    s.data[s.top] = angka;
    cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
    cout << "Stack kosong!" << endl;
    }
    else {
    int val = s.data[s.top];
    s.top--;
    cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
    cout << "Stack kosong!" << endl;
    return;
    }

    if(posisi <= 0){
    cout << "Posisi tidak valid!" << endl;
    return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
    cout << "Posisi " << posisi << " tidak valid!" << endl;
    return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
    cout << "Stack kosong!" << endl;
    }
    else {
    for(int i = s.top; i >= 0; --i){
    cout << s.data[i] << " ";
    }
    }

    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
    cout << "Stack kosong!" << endl;
    return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
    if(s.data[i] == data){
    cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
    cout << endl;
    found = true;
    break;
    }
    posisi++;
    }

    if(!found){
    cout << "Data " << data << " " << "tidak ditemukan didalam stack!" << endl;
    cout << endl;
    }
}
```

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
 int data[MAX];
 int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif	
```

Program di atas merupakan implementasi struktur data Stack menggunakan array, dengan prinsip kerja LIFO (Last In First Out) di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Struktur stackTable terdiri dari array data[MAX] sebagai wadah elemen dan variabel top untuk menunjukkan posisi elemen teratas, dengan nilai awal -1 yang menandakan stack masih kosong. Fungsi createStack() digunakan untuk menginisialisasi stack, isEmpty() memeriksa apakah stack kosong, dan isFull() memeriksa apakah stack telah penuh. Operasi push() menambahkan data ke bagian atas stack jika belum penuh, sedangkan pop() menghapus elemen teratas jika stack tidak kosong. Fungsi update() memungkinkan pengguna mengubah nilai data pada posisi tertentu yang dihitung dari posisi TOP (1-based indexing), sementara view() menampilkan seluruh isi stack dari elemen teratas hingga terbawah. Terakhir, searchData() digunakan untuk mencari nilai tertentu di dalam stack dan menampilkan posisinya jika ditemukan. Selama proses eksekusi, program menampilkan setiap langkah operasi seperti penambahan, penghapusan, pembaruan, dan pencarian data.

## Unguided 

### 1. Unguided 1

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    stackTable S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    view(S);
    cout << "balik stack" << endl;
    balikStack(S);
    view(S);
    cout << endl;

    return 0;
}

```

stack.cpp
```C++
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

```

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

struct stackTable {
    int data[MAX];
    int top; 
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

void balikStack(stackTable &s);
void pushAscending(stackTable &s, int x);
void getInputStream(stackTable &s);

#endif

```

##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan7_Modul7/output/unguided1.jpg)

Program merupakan implementasi Abstract Data Type (ADT) Stack menggunakan array statis yang menerapkan prinsip LIFO (Last In First Out), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Struktur Stack terdiri dari array info[20] yang digunakan untuk menyimpan data bertipe integer dan variabel top yang berfungsi menunjukkan posisi elemen teratas pada stack. Fungsi createStack() digunakan untuk menginisialisasi stack agar berada dalam kondisi kosong dengan nilai top = -1. Proses penambahan data dilakukan melalui fungsi push(), sedangkan penghapusan elemen teratas dilakukan menggunakan fungsi pop(). Fungsi printInfo() berfungsi menampilkan isi stack dari elemen teratas hingga terbawah. Selain itu, terdapat fungsi balikStack() yang berperan untuk membalik urutan elemen dalam stack dengan bantuan stack sementara, sehingga urutan elemen menjadi terbalik dari kondisi awal. Pada program main, dilakukan serangkaian operasi seperti menambahkan data ke dalam stack dengan push(), menghapus beberapa data menggunakan pop(), menampilkan isi stack dengan printInfo(), kemudian membalik urutan data dengan balikStack(). Hasil eksekusi menunjukkan bahwa sebelum dibalik, isi stack adalah [TOP] 9 2 4 3, dan setelah dibalik menjadi [TOP] 3 4 2 9.

### 2. Unguided 2 

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    stackTable S;
    createStack(S);

    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    view(S);            
    cout << "balik stack" << endl;
    balikStack(S);
    view(S);            
    cout << endl;

    return 0;
}

```

stack.cpp
```C++
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

```

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

struct stackTable {
    int data[MAX];
    int top; 
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

void balikStack(stackTable &s);
void pushAscending(stackTable &s, int x);
void getInputStream(stackTable &s);

#endif

```

##### Output Unguided 2 
![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan7_Modul7/output/unguided2.jpg)

Program merupakan pengembangan dari implementasi ADT Stack menggunakan array dengan penambahan prosedur pushAscending() yang berfungsi untuk menyisipkan elemen ke dalam stack secara berurutan naik (ascending order). Struktur data stackTable masih menggunakan array data[MAX] untuk menyimpan elemen bertipe integer dan variabel top untuk menunjukkan posisi elemen teratas. Fungsi dasar seperti createStack() digunakan untuk inisialisasi stack agar kosong, push() untuk menambahkan data, pop() untuk menghapus data teratas, dan view() untuk menampilkan isi stack dari atas ke bawah.

Prosedur pushAscending() bekerja dengan membuat stack sementara, lalu memindahkan elemen dari stack utama ke stack sementara selama elemen teratas lebih besar dari nilai yang akan dimasukkan (x). Setelah itu, nilai x dimasukkan ke stack utama, kemudian seluruh elemen dari stack sementara dikembalikan ke stack utama agar urutannya tetap terjaga dalam bentuk ascending dari bawah ke atas. Pada program main, serangkaian operasi pushAscending() dilakukan untuk menambahkan elemen 3, 4, 8, 2, 3, dan 9. Setelah semua data dimasukkan, fungsi view() menampilkan hasil [TOP] 9 8 4 3 3 2, lalu fungsi balikStack() digunakan untuk membalik urutan elemen sehingga menjadi [TOP] 2 3 3 4 8 9.

### 3. Unguided 3

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    stackTable S;
    createStack(S);

    createStack(S);
    getInputStream(S);
    view(S);
    cout << "balik stack" << endl;
    balikStack(S);
    view(S);
    cout << endl;

    return 0;
}
```

stack.cpp
```C++
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

```

stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

struct stackTable {
    int data[MAX];
    int top; 
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

void balikStack(stackTable &s);
void pushAscending(stackTable &s, int x);
void getInputStream(stackTable &s);

#endif
```

##### Output Unguided 3
![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan7_Modul7/output/unguided3.jpg)

Program merupakan implementasi ADT Stack menggunakan array dengan penambahan prosedur getInputStream(), yang berfungsi untuk membaca input dari pengguna dan memasukkannya ke dalam stack secara otomatis. Struktur data stackTable terdiri dari array data[MAX] untuk menyimpan elemen bertipe integer dan variabel top sebagai penunjuk elemen teratas. Fungsi dasar seperti createStack() digunakan untuk menginisialisasi stack agar kosong, push() untuk menambahkan elemen ke dalam stack, serta view() untuk menampilkan isi stack dari atas ke bawah.

Prosedur getInputStream() meminta pengguna untuk memasukkan sejumlah angka tanpa spasi dan menekan tombol Enter setelah selesai. Setiap karakter yang dimasukkan akan diperiksa menggunakan fungsi isdigit(), kemudian dikonversi menjadi integer dan dimasukkan ke dalam stack dengan memanggil fungsi push(). Setelah input selesai dimasukkan, program menampilkan isi stack melalui fungsi view(). Kemudian, fungsi balikStack() digunakan untuk membalik urutan elemen dalam stack menggunakan stack sementara, sehingga elemen teratas menjadi terbawah dan sebaliknya. Pada saat program dijalankan, jika pengguna memasukkan angka “4729601”, maka output awal yang ditampilkan adalah [TOP] 1 0 6 9 2 7 4, dan setelah dibalik menjadi [TOP] 4 7 2 9 6 0 1.

## Kesimpulan
Struktur data Stack merupakan salah satu komponen dasar yang penting dalam pemrograman karena menerapkan prinsip Last In First Out (LIFO) yang memungkinkan pengelolaan data secara teratur dan efisien. Implementasi Stack dapat dilakukan menggunakan Array atau Linked List, masing-masing memiliki keunggulan dan keterbatasan. Array unggul dalam kecepatan akses, sedangkan Linked List lebih fleksibel karena mendukung alokasi memori dinamis.

## Referensi

[1] Risky Dwi Setiyawan, dkk. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH Journal Education and Technology, Vol. 5, No. 2, Desember 2024. Diakses melalui https://www.researchgate.net/publication/387858466_PENGGUNAAN_STRUKTUR_DATA_STACK_DALAM_PEMROGRAMAN_C_DENGAN_PENDEKATAN_ARRAY_DAN_LINKED_LIST

<br>[2] G. M. Putri. (2024). Implementasi Stack dan Array pada Pengurutan Lagu. JTEKSIS: Jurnal Teknologi dan Sistem Informasi, 2024. Diakses melalui https://www.mendeley.com/catalogue/11df8583-e195-39a3-9344-66d13631ab4a/

<br>[3] A. Aliyanto. (tanpa tahun). Sistem Pembelajaran Algoritma Stack dan Queue dengan Pendekatan Problem-Based Learning. Neliti. Diakses melalui https://www.neliti.com/publications/126175/sistem-pembelajaran-algoritma-stack-dan-queue-dengan-pendekatan-problem-based-le