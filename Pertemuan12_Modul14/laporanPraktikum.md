# <h1 align="center">Laporan Praktikum Modul 14</h1>

<p align="center">Nadira Hikmah Fatheena - 103112430075</p>

## Dasar Teori

Teori graf merupakan representasi matematis yang memodelkan jaringan di mana setiap lokasi atau entitas dipandang sebagai simpul (node), sementara jalur penghubung antar entitas tersebut direpresentasikan sebagai sisi (edge) yang dapat memiliki bobot tertentu, seperti jarak atau waktu tempuh [1]. Dalam konteks pencarian jalur optimal pada sebuah graf berbobot, Algoritma Dijkstra bekerja menggunakan prinsip greedy untuk menemukan lintasan dengan akumulasi bobot terkecil dari titik awal ke tujuan, sehingga menjamin optimalitas jarak [1]. Berbeda dengan Dijkstra, metode pencarian buta (uninformed search) seperti Breadth-First Search (BFS) melakukan eksplorasi secara melebar (level-by-level) yang efektif untuk menemukan jalur dengan jumlah simpul minimum, sedangkan Depth-First Search (DFS) menelusuri jalur secara mendalam (depth-wise) yang lebih cocok untuk eksplorasi struktur graf atau pengecekan konektivitas [1].

Selain untuk pencarian jalur, struktur graf juga diterapkan secara luas dalam penyelesaian masalah penjadwalan melalui konsep pewarnaan graf (graph coloring), di mana tujuannya adalah memberikan warna pada titik-titik sedemikian rupa sehingga tidak ada dua titik yang bertetangga memiliki warna yang sama [2]. Metode yang sering digunakan adalah Algoritma Welsh-Powell, yang bekerja dengan cara mengurutkan titik berdasarkan derajat tertingginya (jumlah koneksi terbanyak) sebelum melakukan pewarnaan, sehingga dapat meminimalkan jumlah "warna" atau slot waktu yang dibutuhkan [2]. Untuk memproses data ini secara komputasi, hubungan antar titik, seperti mata kuliah yang memiliki potensi bentrok, dikonstruksi ke dalam bentuk matriks ketetanggaan (adjacency matrix) yang berisi nilai biner 0 atau 1 untuk menunjukkan adanya relasi antar elemen [2].

Dalam permasalahan yang berfokus pada efisiensi sumber daya dan pembangunan infrastruktur jaringan, digunakan konsep Pohon Merentang Minimum (Minimum Spanning Tree atau MST) untuk menghubungkan semua titik dengan total bobot seminimal mungkin tanpa membentuk sirkuit [3]. Terdapat tiga algoritma utama dalam penyelesaian MST: Algoritma Prim yang bersifat sederhana dengan memulai dari satu titik root dan memilih sisi terdekat; Algoritma Kruskal yang mengurutkan seluruh sisi dari bobot terkecil ke terbesar sebelum menghubungkannya; serta Algoritma Sollin yang memilih sisi terpendek dari setiap titik secara bersamaan dan menggabungkan pohon-pohon yang terbentuk [3]. Meskipun memiliki pendekatan langkah yang berbeda dalam pemilihan sisi, penelitian menunjukkan bahwa ketiga algoritma tersebut memiliki tingkat efisiensi yang seimbang dengan kompleksitas waktu yang sama, yaitu O(n^2) [3].

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

graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List)
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL) return;

    queue<adrNode> Qyu;

    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL) return;

    stack<adrNode> Stak;

    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus." << endl;
    } else {
        cout << "Node E gagal dihapus." << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;
}
```

Pada graph.h didefinisikan struktur dasar graph yang meliputi ElmNode sebagai simpul (node) yang menyimpan informasi bertipe char, penanda kunjungan (visited), pointer ke edge pertama, serta pointer ke node berikutnya, dan ElmEdge sebagai sisi (edge) yang menunjuk ke node tujuan, sedangkan struktur Graph menyimpan pointer ke node pertama.

File graph.cpp berisi implementasi berbagai operasi graph, mulai dari inisialisasi graph, alokasi node dan edge, penambahan node, pencarian node, penghubungan dan pemutusan node, penghapusan node beserta seluruh edge terkait, hingga penampilan graph dalam bentuk adjacency list. Selain itu, program juga mengimplementasikan traversal Breadth First Search (BFS) menggunakan struktur data queue dan Depth First Search (DFS) menggunakan stack, dengan memanfaatkan atribut visited untuk mencegah kunjungan ulang ke node yang sama.

Pada main.cpp, graph dibangun dengan menambahkan beberapa node dan menghubungkannya sesuai skenario, kemudian ditampilkan representasi adjacency list, hasil traversal BFS dan DFS dari node awal tertentu, serta dilakukan pengujian penghapusan node untuk memastikan seluruh relasi edge terkait terhapus dengan benar.

## Unguided

### 1. Unguided 1

main.cpp

```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');

    PrintInfoGraph(G);
    return 0;
}

```

graph.cpp

```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AlokasiNode(X);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrNode Q = G.First;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X, infoGraph Y) {
    adrNode N1 = FindNode(G, X);
    adrNode N2 = FindNode(G, Y);

    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}
```

graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X, infoGraph Y);
void PrintInfoGraph(Graph G);

#endif
```

File graph.h berisi pendefinisian tipe data dan struktur graph, meliputi ElmNode sebagai node yang menyimpan informasi bertipe char, penanda kunjungan (visited), pointer ke edge pertama, serta pointer ke node berikutnya, dan ElmEdge sebagai representasi edge yang menunjuk ke node tujuan, sedangkan struktur Graph menyimpan pointer ke node pertama sebagai awal graph.

Pada graph.cpp diimplementasikan berbagai operasi dasar graph, seperti inisialisasi graph melalui prosedur CreateGraph, alokasi node dan edge menggunakan AlokasiNode dan AlokasiEdge, penambahan node ke dalam graph dengan metode insert last, pencarian node berdasarkan informasi tertentu, serta penghubungan dua node secara dua arah melalui prosedur ConnectNode sehingga membentuk graph tidak berarah. Selain itu, disediakan prosedur PrintInfoGraph untuk menampilkan isi graph dalam bentuk adjacency list, yang menunjukkan setiap node beserta node-node tetangganya.

Pada main.cpp, graph dibuat dan diinisialisasi, kemudian beberapa node dimasukkan dan dihubungkan sesuai skenario yang diberikan, dan hasil akhir struktur graph ditampilkan ke layar.

##### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan12_Modul14/output/unguided1.jpg)

### 2. Unguided 2

main.cpp

```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== REPRESENTASI GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode start = FindNode(G, 'A');
    if (start != NULL) {
        cout << "=== HASIL DFS ===" << endl;
        PrintDFS(G, start);
    }

    return 0;
}
```

graph.cpp

```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode NewNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->Next = NULL;
    P->firstEdge = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = NewNode(X);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrNode Q = G.First;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X, infoGraph Y) {
    adrNode P = FindNode(G, X);
    adrNode Q = FindNode(G, Y);

    if (P != NULL && Q != NULL) {
        adrEdge E = new ElmEdge;
        E->Node = Q;
        E->Next = NULL;

        if (P->firstEdge == NULL) {
            P->firstEdge = E;
        } else {
            E->Next = P->firstEdge;
            P->firstEdge = E;
        }
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    ResetVisited(G);
    stack<adrNode> S;

    S.push(N);

    while (!S.empty()) {
        adrNode P = S.top();
        S.pop();

        if (P->visited == 0) {
            P->visited = 1;
            cout << P->info << " ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    S.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}
```

graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stack>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode NewNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X, infoGraph Y);
void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);

#endif
```

Pada file graph.h didefinisikan struktur dasar graph yang terdiri dari ElmNode sebagai node yang menyimpan data bertipe char, penanda kunjungan (visited), pointer ke edge pertama, serta pointer ke node berikutnya, dan ElmEdge sebagai edge yang menunjuk ke node tujuan, sedangkan struktur Graph menyimpan pointer ke node pertama.

File graph.cpp berisi implementasi fungsi-fungsi utama graph, mulai dari inisialisasi graph, pembuatan node baru, penambahan node ke graph, pencarian node berdasarkan informasi tertentu, serta penghubungan node secara satu arah melalui prosedur ConnectNode, sehingga hubungan yang terbentuk bersifat berarah. Selain itu, program ini juga mengimplementasikan traversal Depth First Search (DFS) menggunakan struktur data stack, di mana proses penelusuran dimulai dari node awal tertentu dan memanfaatkan atribut visited untuk memastikan setiap node hanya dikunjungi satu kali.

Pada main.cpp, graph dibangun dengan menambahkan beberapa node dan membentuk hubungan sesuai skenario, kemudian ditampilkan representasi graph dalam bentuk adjacency list dan hasil traversal DFS dari node awal yang ditentukan.

##### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan12_Modul14/output/unguided2.jpg)

### 3. Unguided 3

main.cpp

```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== REPRESENTASI GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode start = FindNode(G, 'A');
    if (start != NULL) {
        cout << "=== HASIL BFS ===" << endl;
        PrintBFS(G, start);
    } else {
        cout << "Node Awal tidak ditemukan!" << endl;
    }

    return 0;
}
```

graph.cpp

```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AlokasiNode(X);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrNode Q = G.First;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X, infoGraph Y) {
    adrNode N1 = FindNode(G, X);
    adrNode N2 = FindNode(G, Y);

    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    queue<adrNode> Q;

    Q.push(N);
    N->visited = 1;

    cout << "BFS: ";
    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}
```

graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X, infoGraph Y);
void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintBFS(Graph G, adrNode N);
void PrintDFS(Graph G, adrNode N);

#endif
```

Pada file graph.h didefinisikan struktur dasar graph yang meliputi ElmNode sebagai node yang menyimpan data bertipe char, penanda kunjungan (visited), pointer ke edge pertama, serta pointer ke node berikutnya, dan ElmEdge sebagai edge yang menunjuk ke node tujuan, sedangkan struktur Graph menyimpan pointer ke node pertama sebagai awal graph.

File graph.cpp berisi implementasi fungsi-fungsi utama graph, seperti inisialisasi graph, alokasi node dan edge, penambahan node ke dalam graph, pencarian node berdasarkan informasi tertentu, serta penghubungan dua node secara dua arah melalui prosedur ConnectNode sehingga membentuk graph tidak berarah. Selain itu, program ini juga mengimplementasikan traversal Breadth First Search (BFS) menggunakan struktur data queue, di mana penelusuran dimulai dari node awal tertentu dan dilakukan secara melebar ke seluruh node tetangga terdekat terlebih dahulu, dengan memanfaatkan atribut visited untuk memastikan setiap node hanya dikunjungi satu kali.

Pada main.cpp, graph dibangun dengan menambahkan beberapa node dan membentuk hubungan antar node sesuai skenario yang diberikan, kemudian ditampilkan representasi graph dalam bentuk adjacency list dan hasil traversal BFS dari node awal yang ditentukan.

##### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/nadirahikmahfatheena/103112430075_Nadira-Hikmah-Fatheena/blob/main/Pertemuan12_Modul14/output/unguided3.jpg)

## Kesimpulan

Dapat disimpulkan bahwa graf merupakan struktur data dan model matematis yang sangat fleksibel serta efektif dalam merepresentasikan berbagai permasalahan jaringan dan hubungan antar entitas. Beragam algoritma graf, seperti Dijkstra, BFS, dan DFS, memiliki karakteristik dan tujuan yang berbeda sehingga pemilihannya harus disesuaikan dengan kebutuhan permasalahan, baik untuk mencari jalur terpendek, jumlah simpul minimum, maupun eksplorasi struktur graf. Selain itu, penerapan graf dalam penjadwalan melalui pewarnaan graf dengan Algoritma Welsh-Powell menunjukkan bagaimana graf dapat dimanfaatkan untuk mengoptimalkan penggunaan sumber daya dan menghindari konflik. Konsep Minimum Spanning Tree (MST) juga menegaskan peran graf dalam efisiensi pembangunan jaringan dengan meminimalkan total bobot koneksi, di mana algoritma Prim, Kruskal, dan Sollin menawarkan pendekatan yang berbeda namun memiliki tingkat efisiensi yang sebanding. Dengan demikian, pemahaman teori graf dan algoritma-algoritma pendukungnya menjadi landasan penting dalam penyelesaian berbagai permasalahan komputasi dan dunia nyata secara optimal dan sistematis.

## Referensi

[1] Siti Nurul Qomariah, dkk. (2023). Implementasi Teori Graf dan Optimisasi Alogaritma Dijkstra, BFS dan DFS Dalam Menentukan Jalur Terpendek Jaringan Toko Mixue Di Jabodetabek Berbasis Google Maps. Jurnal Transformasi dan Integrasi Lima. Diakses melalui https://journal.cattleyadf.org/index.php/jatilima/article/view/1649

<br>[2] Hesti Kurniawati. (2023). PEMROGRAMAN PEWARNAAN GRAF PADA PENJADWALAN MATA KULIAH JURUSAN MATEMATIKA. ResearchGate. Diakses melalui https://www.researchgate.net/publication/374037153_PEMROGRAMAN_PEWARNAAN_GRAF_PADA_PENJADWALAN_MATA_KULIAH_JURUSAN_MATEMATIKA

<br>[3] Nisa Nur'azizah, dkk. (2018). perbandingan kompleksitas algoritma prim, algoritma kruskal, dan algoritma sollin untuk menyelesaikan masalah minimum spanning tree. Jurnal Komputasi. Diakses melalui https://komputasi.fmipa.unila.ac.id/index.php/komputasi/article/view/27
