#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bekasi");

    connectNode(G, "Jakarta", "Bogor", 42);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Tangerang", 24);
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Bekasi", "Tangerang", 45);

    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    printGraph(G);
    cout << endl;

    cout << "MENGHAPUS NODE DEPOK" << endl;
    deleteNode(G, "Depok");

    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    printGraph(G);

    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");
    cout << endl;

    return 0;
}