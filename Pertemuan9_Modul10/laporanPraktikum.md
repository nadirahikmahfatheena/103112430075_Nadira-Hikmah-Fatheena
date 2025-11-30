# <h1 align="center">Laporan Praktikum Modul 10</h1>

<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori

Pohon (Tree) merupakan struktur data hierarkis yang terdiri dari simpul (node) dan cabang, yang memegang peranan vital dalam ilmu komputer karena kemampuannya dalam mengelola data secara efisien [3]. Salah satu bentuk implementasi yang paling umum adalah Binary Search Tree (BST), yaitu pohon biner yang memiliki aturan keterurutan di mana setiap simpul anak kiri memiliki nilai lebih kecil dari induknya, sedangkan simpul anak kanan memiliki nilai lebih besar [1]. Struktur ini memungkinkan operasi dasar seperti pencarian, penyisipan, dan penghapusan data dilakukan dengan kompleksitas waktu yang lebih rendah dibandingkan struktur data linear seperti array maupun linked list, sehingga sangat efektif untuk menangani volume data yang besar [3].

Efisiensi Binary Search Tree sangat bergantung pada keseimbangan pohon tersebut. Dalam kondisi optimal, kompleksitas waktu pencarian dapat mencapai O log n, namun untuk menjaga kinerja tetap stabil dalam kasus terburuk, dikembangkan varian pohon biner penyeimbang otomatis seperti AVL Tree dan Red-Black Tree [3]. Varian-varian ini memastikan bahwa selisih tinggi antara sub-pohon kiri dan kanan tetap terkendali, sehingga operasi komputasi dalam basis data, jaringan komputer, maupun algoritma pencarian tetap berjalan dengan kecepatan optimal baik dari segi waktu maupun ruang [3].

Selain digunakan untuk penyimpanan dan pencarian data, konsep pohon biner juga menjadi landasan dalam pembentukan struktur data Priority Queue atau antrean berprioritas [1]. Berbeda dengan antrean konvensional yang menggunakan prinsip First In First Out (FIFO), Priority Queue memproses elemen berdasarkan tingkat prioritasnya, di mana elemen dengan nilai atau prioritas lebih tinggi akan dilayani terlebih dahulu [1]. Implementasi Priority Queue dengan memanfaatkan Binary Search Tree dianggap solusi yang tepat karena sifat keterurutan pada BST memudahkan penyisipan elemen sesuai prioritas dan pengambilan elemen tertinggi secara efisien [1].

Penerapan metode pohon biner juga meluas ke bidang penerjemahan sinyal, seperti pada dekripsi sandi Morse melalui metode Pohon Morse (Morse Tree) [2]. Dalam sistem ini, struktur Binary Search Tree digunakan untuk memetakan kombinasi titik (dot) dan garis (dash), di mana penelusuran ke cabang kiri merepresentasikan titik dan cabang kanan merepresentasikan garis [2]. Metode ini memungkinkan perangkat lunak, seperti aplikasi berbasis Android, untuk mendeskripsikan pesan sandi Morse menjadi teks atau sebaliknya dengan menelusuri simpul-simpul pohon secara akurat dan responsif [2].

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

bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```

bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ // nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

main.h

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Program ini mengimplementasikan struktur data Binary Search Tree (BST), di mana definisi struktur node yang memuat data integer serta pointer left dan right dipisahkan dalam file header (bst.h) sementara logika operasinya dimuat dalam file implementasi (bst.cpp). Algoritma inti program meliputi penyisipan data (insertNode) yang bekerja secara rekursif menempatkan nilai lebih kecil di subtree kiri dan nilai lebih besar di kanan, serta operasi pencarian (searchByData) yang tidak hanya memvalidasi keberadaan data tetapi juga melacak relasi node tersebut dengan parent, sibling, dan children-nya. Fitur manajemen tree mencakup tiga jenis traversal (PreOrder, InOrder, PostOrder), perhitungan properti tree (seperti size dan height), serta mekanisme penghapusan node (deleteNode) yang kompleks karena menangani tiga skenario berbeda (penghapusan leaf, node dengan satu anak, dan node dengan dua anak menggunakan teknik penggantian successor), diakses melalui menu interaktif pada program utama.

## Unguided

### 1. Unguided 1

main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "Tampilan InOrder: ";
    printInorder(root);
    cout << endl;

    return 0;
}
```

bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x) {
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root;
        }
    }
}

void printInorder(address root) {
    if (root == Nil) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) {
        return 0;
    } else {
        int lDepth = hitungKedalaman(root->left);
        int rDepth = hitungKedalaman(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printPreorder(address root) {
    if (root == Nil) {
        return;
    }
    cout << root->info << " - ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " - ";
}
```

bstree.h

```C++
#include "bstree.h"

address alokasi(infotype x) {
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root;
        }
    }
}

void printInorder(address root) {
    if (root == Nil) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) {
        return 0;
    } else {
        int lDepth = hitungKedalaman(root->left);
        int rDepth = hitungKedalaman(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printPreorder(address root) {
    if (root == Nil) {
        return;
    }
    cout << root->info << " - ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " - ";
}
```

Program ini dibagi menjadi tiga file utama untuk memisahkan deklarasi tipe data abstrak (ADT) dari implementasinya. File header bstree.h mendefinisikan struct Node yang menampung infotype bertipe integer dan pointer alamat memori. File bstree.cpp berisi logika fungsi, dimulai dari alokasi memori dan insertNode. Fungsi penyisipan (insertNode) bekerja secara rekursif dengan prinsip dasar BST: jika nilai baru lebih kecil dari node saat ini, ia akan menelusuri ke kiri, dan jika lebih besar akan ke kanan. Program juga dilengkapi dengan fitur manipulasi dan analisis pohon, mencakup fungsi findNode untuk pencarian, fungsi statistik rekursif (hitungJumlahNode, hitungTotalInfo, hitungKedalaman), serta prosedur traversal standar (Preorder, Inorder, dan Postorder) untuk menelusuri seluruh elemen pohon.

Pada file main.cpp, program menginisialisasi pointer root dengan nilai Nil (NULL) dan melakukan serangkaian operasi penyisipan data. Data yang dimasukkan berturut-turut adalah 1, 2, 6, 4, 5, 3, 6, dan 7. Berdasarkan logika pada fungsi insertNode, input angka 6 yang kedua tidak akan ditambahkan ke dalam struktur pohon karena kondisi percabangan hanya menangani nilai yang lebih kecil (<) atau lebih besar (>), sehingga nilai duplikat diabaikan. Setelah seluruh node terbentuk, program memanggil fungsi printInorder. Pemanggilan ini akan mencetak seluruh nilai di dalam pohon yang dikunjungi mulai dari sub-pohon kiri, akar, lalu sub-pohon kanan, sehingga menghasilkan keluaran angka yang terurut dari kecil ke besar (sorted).

##### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan9_Modul10/output/unguided1.jpg)

### 2. Unguided 2

main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {

    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman    : " << hitungKedalaman(root) << endl;
    cout << "jumlah Node  : " << hitungJumlahNode(root) << endl;
    cout << "total        : " << hitungTotalInfo(root) << endl;

    return 0;
}
```

bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x) {
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root;
        }
    }
}

void printInorder(address root) {
    if (root == Nil) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) {
        return 0;
    } else {
        int lDepth = hitungKedalaman(root->left);
        int rDepth = hitungKedalaman(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printPreorder(address root) {
    if (root == Nil) {
        return;
    }
    cout << root->info << " - ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " - ";
}
```

bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

void printPreorder(address root);
void printPostorder(address root);

#endif
```

Program ini terbagi menjadi file header (bstree.h), file implementasi (bstree.cpp), dan file eksekusi (main.cpp). Struktur pohon dibentuk menggunakan struct Node dinamis yang memiliki pointer ke anak kiri dan kanan. Fungsi inti insertNode bekerja secara rekursif untuk menempatkan data baru: nilai yang lebih kecil dari root akan menelusuri sub-pohon kiri, sedangkan nilai yang lebih besar menelusuri sub-pohon kanan. Selain fungsi dasar penyisipan dan pencarian, modul ini menyediakan fungsi analitik rekursif yang krusial untuk mengevaluasi properti pohon, yaitu hitungKedalaman untuk mencari level maksimum pohon, hitungJumlahNode untuk menghitung banyaknya elemen yang tersimpan, dan hitungTotalInfo untuk mengakumulasi penjumlahan seluruh nilai data dalam pohon.

Pada fungsi utama (main), pohon diinisialisasi dan diisi dengan urutan data 1, 2, 6, 4, 5, 3, 6, dan 7. Mekanisme validasi pada insertNode menyebabkan angka 6 yang dimasukkan kedua kali diabaikan (tidak terjadi duplikasi data). Setelah data tersimpan, prosedur printInorder dipanggil untuk mencetak elemen secara terurut (ascending). Program kemudian menampilkan hasil perhitungan statistik pohon tersebut: hitungKedalaman menghasilkan nilai 5, yang merepresentasikan jalur terpanjang dari akar hingga daun, yaitu lintasan yang melalui urutan node 1, 2, 6, dan 4, lalu berakhir pada node 3 atau node 5. hitungJumlahNode menghasilkan nilai 7 yang merupakan total elemen unik dalam pohon; dan hitungTotalInfo menghasilkan nilai 28, didapatkan dari penjumlahan seluruh elemen (1+2+6+4+5+3+7).

##### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan9_Modul10/output/unguided2.jpg)

### 3. Unguided 3

main.cpp

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {

    address root = Nil;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);


    cout << "Pre-Order  : ";
    printPreorder(root);
    cout << endl;

    cout << "In-Order   : ";
    printInorder(root);
    cout << endl;

    cout << "Post-Order : ";
    printPostorder(root);
    cout << endl;

    return 0;
}
```

bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x) {
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root;
        }
    }
}

void printInorder(address root) {
    if (root == Nil) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) {
        return 0;
    } else {
        int lDepth = hitungKedalaman(root->left);
        int rDepth = hitungKedalaman(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printPreorder(address root) {
    if (root == Nil) {
        return;
    }
    cout << root->info << " - ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " - ";
}
```

bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

void printPreorder(address root);
void printPostorder(address root);

#endif
```

Program ini terdiri dari file header bstree.h sebagai antarmuka ADT dan file bstree.cpp sebagai implementasi fungsi. Struktur pohon dibangun menggunakan pointer, di mana fungsi insertNode menempatkan data baru secara rekursif: nilai yang lebih kecil dari node pembanding akan ditempatkan di sub-pohon kiri, sedangkan nilai yang lebih besar di sub-pohon kanan. Fokus utama program ini adalah mendemonstrasikan tiga algoritma penelusuran pohon (tree traversal) standar. Fungsi printPreorder melakukan penelusuran dengan urutan Cetak-Kiri-Kanan (Root-Left-Right), printInorder dengan urutan Kiri-Cetak-Kanan (Left-Root-Right) yang menghasilkan data terurut, dan printPostorder dengan urutan Kiri-Kanan-Cetak (Left-Right-Root).

Pada fungsi utama (main), pohon dibentuk melalui penyisipan data dengan urutan spesifik: 6, 4, 7, 2, 5, 1, dan 3. Urutan input ini membentuk pohon di mana angka 6 menjadi akar utama (root), angka 4 dan 7 menjadi anak level pertama, dan seterusnya hingga angka 1 dan 3 berada di level terdalam (daun). Program kemudian mengeksekusi ketiga fungsi traversal untuk menampilkan struktur data tersebut. Hasil Pre-order menampilkan urutan 6 - 4 - 2 - 1 - 3 - 5 - 7, yang menggambarkan alur kunjungan dari akar ke bawah. Hasil In-order menampilkan urutan 1 - 2 - 3 - 4 - 5 - 6 - 7, membuktikan sifat BST yang terurut secara ascending. Terakhir, hasil Post-order menampilkan urutan 1 - 3 - 2 - 5 - 4 - 7 - 6, yang merepresentasikan penelusuran dari daun terbawah hingga kembali ke akar utama.

##### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan9_Modul10/output/unguided3.jpg)

## Kesimpulan
Dapat disimpulkan bahwa Binary Search Tree (BST) merupakan struktur data hierarkis yang memegang peranan vital dalam ilmu komputer karena menawarkan efisiensi operasi data (pencarian, penyisipan, penghapusan) yang lebih baik dibandingkan struktur linear seperti array. Kinerja optimal BST sangat bergantung pada keseimbangan strukturnya. Oleh karena itu, varian seperti AVL Tree dan Red-Black Tree dikembangkan untuk menjamin stabilitas kompleksitas waktu tetap logaritmik (O(log n)). Fleksibilitas konsep BST juga terbukti melalui penerapannya yang luas, tidak hanya sebagai penyimpanan data, tetapi juga sebagai fondasi algoritma kompleks seperti Priority Queue untuk manajemen prioritas proses, serta implementasi Pohon Morse untuk kebutuhan penerjemahan sinyal digital.

## Referensi

[1] Muhammad Hanif Adzkiya. (2018). Implementasi Binary Search Tree pada Struktur Data Priority Queue dalam Bahasa C. Makalah IF2120 Matematika Diskrit, Program Studi Teknik Informatika, Institut Teknologi Bandung. Diakses melalui https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2018-2019/Makalah/Makalah-Matdis-2018-087.pdf

<br>[2] Nurul Chafid, Apriyanto Saputra. (2024). Penerapan Metode Binary Search Tree Untuk Deskripsi Sandi Morse Berbasis Android. JISNI: Jurnal Ilmiah Universitas Satya Negara Indonesia. Diakses melaluihttps://jurnal.unimed.ac.id/2012/index.php/cess/article/view/67447/27654

<br>[3] Agung Wijoyo, dkk. (2024). Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien. JRIIN: Jurnal Riset Informatika dan Inovasi. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1264



