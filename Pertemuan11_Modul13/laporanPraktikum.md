# <h1 align="center">Laporan Praktikum Modul 13</h1>

<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori

Linked List merupakan struktur data linier yang terdiri dari kumpulan elemen atau simpul (node), di mana setiap simpul menyimpan nilai data sekaligus penunjuk (pointer) yang mengarah ke simpul berikutnya [1]. Berbeda dengan struktur data statis seperti Array yang menyimpan elemen dalam satu blok memori dengan ukuran tetap, Linked List menawarkan fleksibilitas yang lebih tinggi karena ukurannya bersifat dinamis dan tidak memerlukan pengalokasian ulang memori saat terjadi penambahan data [3]. Keunggulan utama dari struktur ini adalah efisiensi dalam operasi penyisipan dan penghapusan data tanpa perlu menggeser elemen lain, menjadikannya fondasi yang kuat untuk pengelolaan data yang sering mengalami perubahan [3].

Pengembangan konsep Linked List melalui pemanfaatan pointer memungkinkan terbentuknya struktur yang lebih kompleks untuk mengatasi keterbatasan memori dan representasi data yang rumit, yang dikenal sebagai Multi List atau Multi Linked List [2]. Dalam struktur Multi List, sebuah simpul tidak hanya memiliki satu pointer yang menunjuk ke data berikutnya secara linear, tetapi dapat memiliki beberapa pointer yang menghubungkan berbagai objek dengan relasi yang berbeda [2]. Penggunaan struktur data pointer ini sangat krusial untuk aplikasi yang membutuhkan sumber daya memori yang besar namun terbatas, karena memori dapat dipakai dan dilepas (deallocation) secara dinamis sesuai kebutuhan aplikasi saat berjalan (runtime) [2].

Multi Linked List secara spesifik dirancang untuk merepresentasikan hubungan antar objek yang kompleks, seperti relasi "satu ke banyak" (one-to-many) ataupun "banyak ke banyak" (many-to-many) yang sering ditemukan dalam sistem basis data [2]. Sebagai contoh dalam relasi satu ke banyak, Multi List dapat menghubungkan satu objek dosen dengan banyak objek mahasiswa bimbingannya melalui pointer yang saling berkait, di mana struktur datanya didefinisikan dengan record yang memiliki field pointer ke objek lain yang berbeda tipe [2]. Hal ini memungkinkan sistem untuk membaca informasi secara terstruktur dari satu simpul induk ke berbagai simpul anak yang terkait [2].

Lebih jauh lagi, penerapan Multi List sangat efektif untuk menangani kondisi basis data yang tidak normal atau denormalisasi, di mana penggunaan tabel konvensional sering kali menghasilkan banyak kolom kosong yang memboroskan ruang penyimpanan [2]. Dengan menggunakan Multi List untuk relasi "banyak ke banyak", seperti hubungan antara banyak mahasiswa dengan banyak mata kuliah, sistem dapat meminimalkan redundansi tabel dan mengoptimalkan efisiensi ruang [2]. Selain itu, konsep ini juga relevan dengan pengembangan struktur data prioritas, di mana elemen-elemen dapat dikelompokkan dan diakses berdasarkan tingkat kepentingannya, mirip dengan mekanisme Priority Queue yang memproses elemen prioritas tinggi terlebih dahulu [1].

### A. Guided<br/>

...

#### 1. guided 1

### B. Unguided<br/>

...

#### 1. unguided 1

#### 2. unguided 2

#### 3. unguided 3

## Guided

### 1. guided 1

main.cpp

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);

    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu

    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);

    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;

    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;

    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;

    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak);

    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L);

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

mll.h

```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

mll.cpp

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

Program ini mengimplementasikan struktur data Multi-Linked List (MLL) dengan relasi 1-ke-N, di mana baik list induk (Parent/Kategori) maupun list anak (Child/Menu Makanan) dikonstruksi sebagai Double Linked List. Header file mll.h mendefinisikan Abstract Data Type (ADT) yang mengintegrasikan struct listAnak di dalam nodeParent, menciptakan hierarki data bersarang yang memungkinkan setiap kategori memiliki linked list independennya sendiri. Implementasi logika pada mll.cpp mencakup operasi CRUD (Create, Read, Update, Delete) yang kompleks, termasuk mekanisme traversal ganda (nested loop) untuk pencarian data Child di seluruh Parent serta prosedur penghapusan (deleteParent) yang secara otomatis menangani dealokasi memori seluruh list anak terkait untuk mencegah memory leak. Keseluruhan logika ini divalidasi melalui main.cpp yang mensimulasikan manajemen menu restoran, mendemonstrasikan bagaimana manipulasi node dilakukan secara dinamis mulai dari insersi, pembaruan data, hingga penghapusan struktur data yang saling terhubung tersebut.

## Unguided

### 1. Unguided 1

main.cpp

```C++
#include "MultiLL_Soal1.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = alokasiNodeParent("G001", "Aves");
    NodeParent G2 = alokasiNodeParent("G002", "Mamalia");
    NodeParent G3 = alokasiNodeParent("G003", "Pisces");
    NodeParent G4 = alokasiNodeParent("G004", "Amfibi");
    NodeParent G5 = alokasiNodeParent("G005", "Reptil");
    insertLastParent(LP, G1); insertLastParent(LP, G2);
    insertLastParent(LP, G3); insertLastParent(LP, G4); insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, alokasiNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, alokasiNodeChild("AV002", "Bebek", "Air", true, 2.0));
    insertLastChild(G2->L_Child, alokasiNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, alokasiNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, alokasiNodeChild("M002", "Kucing", "Darat", true, 4));
    insertLastChild(G4->L_Child, alokasiNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);
    return 0;
}
```

MultiLL_Soal1.cpp

```C++
#include "MultiLL_Soal1.h"

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = ekor;
    C->isidata.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (LP.first == NULL) {
        LP.first = LP.last = nodeBaru;
    } else {
        nodeBaru->prev = LP.last;
        LP.last->next = nodeBaru;
        LP.last = nodeBaru;
    }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (LC.first == NULL) {
        LC.first = LC.last = nodeBaru;
    } else {
        nodeBaru->prev = LC.last;
        LC.last->next = nodeBaru;
        LC.last = nodeBaru;
    }
}

void printMLLStructure(listParent LP) {
    if (LP.first == NULL) { cout << "List Kosong" << endl; return; }
    NodeParent P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << "\nID Golongan: " << P->isidata.idGolongan
             << "\nNama Golongan: " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        if (C == NULL) cout << "(tidak ada child)" << endl;
        else {
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":\n   ID Hewan: " << C->isidata.idHewan
                     << "\n   Nama Hewan: " << C->isidata.namaHewan
                     << "\n   Habitat: " << C->isidata.habitat
                     << "\n   Ekor: " << C->isidata.ekor
                     << "\n   Bobot: " << C->isidata.bobot << endl;
                C = C->next; j++;
            }
        }
        cout << endl;
        P = P->next; i++;
    }
}
```

MultiLL_Soal1.h

```C++
#ifndef MULTILL_SOAL1_H
#define MULTILL_SOAL1_H

#include <iostream>
#include <string>

using namespace std;

struct DataHewan {
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

struct GolonganHewan {
    string idGolongan, namaGolongan;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataHewan isidata;
    NodeChild next, prev;
};

struct listChild {
    NodeChild first, last;
};

struct nodeParent {
    GolonganHewan isidata;
    NodeParent next, prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first, last;
};

void createListParent(listParent &LP);
void createListChild(listChild &LC);
NodeParent alokasiNodeParent(string idGol, string namaGol);
NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);
void insertLastParent(listParent &LP, NodeParent nodeBaru);
void insertLastChild(listChild &LC, NodeChild nodeBaru);
void printMLLStructure(listParent LP);

#endif
```

Program ini memodelkan relasi hierarkis one-to-many antara Golongan Hewan sebagai Parent dan data hewan spesifik sebagai Child. Baik list Parent maupun Child dikonstruksi menggunakan Double Linked List, yang memungkinkan penelusuran elemen dua arah melalui pointer next dan prev. Arsitektur utama kode ini terletak pada struct nodeParent yang membungkus tipe data listChild, sehingga setiap node Parent yang dialokasikan memiliki sub-list independen untuk menampung anak-anaknya. Alur manipulasi data dilakukan melalui prosedur alokasi memori dan penyisipan elemen di akhir list (insert last), sedangkan validasi struktur dilakukan melalui fungsi cetak yang menggunakan algoritma traversal bersarang (nested loop); algoritma ini menelusuri setiap node Parent dan mengakses pointer head dari listChild yang dimilikinya untuk menampilkan seluruh data hewan terkait sebelum berpindah ke golongan berikutnya.

##### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan11_Modul13/output/unguided1.jpg)

### 2. Unguided 2

main.cpp

```C++
#include "MultiLL_Soal2.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = alokasiNodeParent("G001", "Aves");
    NodeParent G2 = alokasiNodeParent("G002", "Mamalia");
    NodeParent G3 = alokasiNodeParent("G003", "Pisces");
    NodeParent G4 = alokasiNodeParent("G004", "Amfibi");
    NodeParent G5 = alokasiNodeParent("G005", "Reptil");

    insertLastParent(LP, G1); insertLastParent(LP, G2);
    insertLastParent(LP, G3); insertLastParent(LP, G4); insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, alokasiNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, alokasiNodeChild("AV002", "Bebek", "Air", true, 2.0));

    insertLastChild(G2->L_Child, alokasiNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, alokasiNodeChild("M003", "Gorila", "Hutan", false, 160)); // <-- Target 1 (Ekor False)
    insertLastChild(G2->L_Child, alokasiNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->L_Child, alokasiNodeChild("AM001", "Kodok", "Sawah", false, 0.2)); // <-- Target 2 (Ekor False)

    searchHewanByEkor(LP, false);

    return 0;
}
```

MultiLL_Soal2.cpp

```C++
#include "MultiLL_Soal2.h"

bool isEmptyParent(listParent LP) { return LP.first == NULL; }
bool isEmptyChild(listChild LC) { return LC.first == NULL; }

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol; P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL; createListChild(P->L_Child); return P;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn; C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat; C->isidata.ekor = ekor; C->isidata.bobot = bobot;
    C->next = C->prev = NULL; return C;
}

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (isEmptyParent(LP)) { LP.first = LP.last = nodeBaru; }
    else { nodeBaru->prev = LP.last; LP.last->next = nodeBaru; LP.last = nodeBaru; }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (isEmptyChild(LC)) { LC.first = LC.last = nodeBaru; }
    else { nodeBaru->prev = LC.last; LC.last->next = nodeBaru; LC.last = nodeBaru; }
}

void printMLLStructure(listParent LP) {
    NodeParent P = LP.first;
    while(P!=NULL){
        cout << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while(C!=NULL){ cout << " - " << C->isidata.namaHewan << endl; C=C->next;}
        P=P->next;
    }
}

void searchHewanByEkor(listParent LP, bool tail) {

    NodeParent P = LP.first;
    int idxParent = 1;
    bool foundAny = false;

    while(P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1;

        while(C != NULL) {
            if(C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan
                     << " pada posisi ke-" << idxChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "---------------------------" << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;

                cout << "---------------------------" << endl;
                cout << endl;

                foundAny = true;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }

    if(!foundAny) {
        cout << "Data tidak ditemukan." << endl;
    }
}
```

MultiLL_Soal2.h

```C++
#ifndef MULTILL_SOAL2_H
#define MULTILL_SOAL2_H

#include <iostream>
#include <string>

using namespace std;

struct DataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct GolonganHewan {
    string idGolongan;
    string namaGolongan;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    GolonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LP);
bool isEmptyChild(listChild LC);
void createListParent(listParent &LP);
void createListChild(listChild &LC);

NodeParent alokasiNodeParent(string idGol, string namaGol);
NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &LP, NodeParent nodeBaru);
void insertLastChild(listChild &LC, NodeChild nodeBaru);

void printMLLStructure(listParent LP);

void searchHewanByEkor(listParent LP, bool tail);

#endif
```

Pada program ini dikembangkan sebuah algoritma pencarian (searching) pada struktur data Multi-Linked List untuk menelusuri data hewan berdasarkan atribut spesifiknya, yaitu keberadaan ekor (tipe boolean). Prosedur searchHewanByEkor mengimplementasikan teknik nested traversal (penelusuran bersarang), di mana outer loop bertugas menavigasi node Parent (Golongan Hewan) dan inner loop menelusuri setiap node Child (Data Hewan) yang terhubung pada Parent tersebut. Dalam setiap iterasi inner loop, dilakukan komparasi antara atribut ekor pada node Child dengan parameter pencarian. Jika kondisi matching terpenuhi, program tidak hanya menampilkan data hewan, tetapi juga melacak dan menampilkan indeks posisi Parent maupun Child terkait, sehingga memberikan informasi lokasi data yang presisi dalam struktur hierarki tersebut.

##### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan11_Modul13/output/unguided2.jpg)

### 3. Unguided 3

main.cpp

```C++
#include "MultiLL_Soal3.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = alokasiNodeParent("G001", "Aves");
    NodeParent G2 = alokasiNodeParent("G002", "Mamalia");
    NodeParent G3 = alokasiNodeParent("G003", "Pisces");
    NodeParent G4 = alokasiNodeParent("G004", "Amfibi");
    NodeParent G5 = alokasiNodeParent("G005", "Reptil");

    insertLastParent(LP, G1);
    insertLastParent(LP, G2);
    insertLastParent(LP, G3);
    insertLastParent(LP, G4);
    insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, alokasiNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, alokasiNodeChild("AV002", "Bebek", "Air", true, 2.0));

    insertLastChild(G2->L_Child, alokasiNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, alokasiNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, alokasiNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->L_Child, alokasiNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    NodeParent Predecessor = findParentByID(LP, "G003");

    if (Predecessor != NULL) {
        deleteAfterParent(LP, Predecessor);
    }

    printMLLStructure(LP);

    return 0;
}
```

MultiLL_Soal3.cpp

```C++
#include "MultiLL_Soal3.h"

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }
bool isEmptyParent(listParent LP) { return LP.first == NULL; }
bool isEmptyChild(listChild LC) { return LC.first == NULL; }

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol; P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL; createListChild(P->L_Child); return P;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn; C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat; C->isidata.ekor = ekor; C->isidata.bobot = bobot;
    C->next = C->prev = NULL; return C;
}

void dealokasiNodeParent(NodeParent &P) { delete P; P = NULL; }
void dealokasiNodeChild(NodeChild &C) { delete C; C = NULL; }

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (isEmptyParent(LP)) { LP.first = LP.last = nodeBaru; }
    else { nodeBaru->prev = LP.last; LP.last->next = nodeBaru; LP.last = nodeBaru; }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (isEmptyChild(LC)) { LC.first = LC.last = nodeBaru; }
    else { nodeBaru->prev = LC.last; LC.last->next = nodeBaru; LC.last = nodeBaru; }
}

void printMLLStructure(listParent LP) {
    if (isEmptyParent(LP)) {
        cout << "List Kosong." << endl;
        return;
    }

    NodeParent P = LP.first;
    int idxParent = 1;

    while(P != NULL) {
        cout << "Parent " << idxParent << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if(C == NULL) {
            cout << "   (tidak ada child)" << endl;
        } else {
            int idxChild = 1;
            while(C != NULL) {
                cout << "   - Child " << idxChild << " :" << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << C->isidata.ekor << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                idxChild++;
            }
        }
        cout << "---------------------------" << endl;
        P = P->next;
        idxParent++;
    }
}

NodeParent findParentByID(listParent LP, string idGol) {
    NodeParent P = LP.first;
    while(P != NULL) {
        if(P->isidata.idGolongan == idGol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteAfterParent(listParent &LP, NodeParent nodePrev) {
    if (nodePrev != NULL && nodePrev->next != NULL) {
        NodeParent nodeHapus = nodePrev->next;

        nodePrev->next = nodeHapus->next;

        if (nodeHapus->next != NULL) {
            nodeHapus->next->prev = nodePrev;
        } else {
            LP.last = nodePrev;
        }

        NodeChild C = nodeHapus->L_Child.first;
        while(C != NULL) {
            NodeChild hapusC = C;
            C = C->next;
            dealokasiNodeChild(hapusC);
        }

        dealokasiNodeParent(nodeHapus);
    }
}
```

MultiLL_Soal3.h

```C++
#ifndef MULTILL_SOAL3_H
#define MULTILL_SOAL3_H

#include <iostream>
#include <string>

using namespace std;

struct DataHewan {
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

struct GolonganHewan {
    string idGolongan, namaGolongan;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataHewan isidata;
    NodeChild next, prev;
};

struct listChild {
    NodeChild first, last;
};

struct nodeParent {
    GolonganHewan isidata;
    NodeParent next, prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first, last;
};

void createListParent(listParent &LP);
void createListChild(listChild &LC);
bool isEmptyParent(listParent LP);
bool isEmptyChild(listChild LC);

NodeParent alokasiNodeParent(string idGol, string namaGol);
NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &LP, NodeParent nodeBaru);
void insertLastChild(listChild &LC, NodeChild nodeBaru);

void deleteAfterParent(listParent &LP, NodeParent nodePrev);
NodeParent findParentByID(listParent LP, string idGol);

void printMLLStructure(listParent LP);

void dealokasiNodeParent(NodeParent &P);
void dealokasiNodeChild(NodeChild &C);

#endif
```

Program ini mengimplementasikan struktur data Multi-Linked List dengan variasi list of lists menggunakan Double Linked List pada baik node Parent (merepresentasikan Golongan Hewan) maupun node Child (merepresentasikan Data Hewan) untuk memungkinkan traversal dua arah. Fokus utama alur program terletak pada mekanisme manajemen memori dan manipulasi pointer melalui fungsi deleteAfterParent, di mana penghapusan node Parent dilakukan pada elemen yang terletak tepat setelah node predecessor tertentu. Secara teknis, sebelum node Parent dihapus, algoritma melakukan iterasi untuk mendealokasi seluruh node Child yang terhubung dengannya terlebih dahulu guna mencegah memory leak, sebagaimana disimulasikan dalam fungsi main di mana golongan "Amfibi" (G004) dihapus karena berada tepat setelah "Pisces" (G003), menghasilkan struktur data akhir yang tetap terhubung secara utuh tanpa node tersebut.

##### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan11_Modul13/output/unguided3.jpg)

## Kesimpulan

Penerapan Multi Linked List memungkinkan optimalisasi penggunaan sumber daya memori melalui mekanisme alokasi dan dealokasi dinamis saat program berjalan (runtime), sehingga mampu meminimalkan pemborosan ruang penyimpanan akibat kolom kosong pada basis data yang tidak normal. Selain itu, fleksibilitas struktur ini mendukung implementasi fitur-fitur lanjutan seperti pengurutan berdasarkan prioritas (Priority Queue), yang memastikan data diproses secara sistematis sesuai tingkat kepentingannya. Dengan demikian, Multi Linked List merupakan metode penyimpanan yang efisien dan adaptif untuk mengatasi kebutuhan komputasi yang melibatkan manipulasi data kompleks dan bervolume besar.

## Referensi

[1] Juliana Gloria Sipayung, dkk. (2025). Pengembangan Aplikasi Belanja Pintar Berbasis Linked List dengan Fitur Checklist dan Prioritas. Jurnal Ilmu Komputer Dan Informatika. Diakses melalui https://jurnal.globalscients.com/index.php/jiki/article/view/708

[2] Jaidup Banjarnahor. (2022). Pemanfaatan Link List Untuk Mengatasi database Tidak Normal. LOFIAN: Jurnal Teknologi Informasi dan Komunikasi. Diakses melalui https://ejournal.umbp.ac.id/index.php/lofian/article/view/183

[3] Septian Dwi Purwanto, dkk. (2024). Implementasi Array dalam Pengolahan Data Nilai Mahasiswa di Perguruan Tinggi. ResearchGate. Diakses melalui https://www.researchgate.net/publication/387553025_Implementasi_Array_dalam_Pengolahan_Data_Nilai_Mahasiswa_di_Perguruan_Tinggi
