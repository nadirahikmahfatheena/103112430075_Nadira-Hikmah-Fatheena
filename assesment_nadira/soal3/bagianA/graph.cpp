#include "graph.h"

void createGraph(Graph &G) {
    G.First = NULL;
}

adrNode alokasiNode(infoGraph nama) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->namaKota = nama;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->next = NULL;
    return nodeBaru;
}

adrEdge alokasiEdge(adrNode tujuan, int jarak) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->nodeTujuan = tujuan;
    edgeBaru->jarak = jarak;
    edgeBaru->next = NULL;
    return edgeBaru;
}

void insertNode(Graph &G, infoGraph nama) {
    if (findNode(G, nama) != NULL) return; 

    adrNode nodeBaru = alokasiNode(nama);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        adrNode last = G.First;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = nodeBaru;
    }
}

adrNode findNode(Graph G, infoGraph nama) {
    adrNode curr = G.First;
    while (curr != NULL) {
        if (curr->namaKota == nama) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph nama1, infoGraph nama2, int jarak) {
    adrNode node1 = findNode(G, nama1);
    adrNode node2 = findNode(G, nama2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = alokasiEdge(node2, jarak);
        edge1->next = node1->firstEdge; 
        node1->firstEdge = edge1;

        adrEdge edge2 = alokasiEdge(node1, jarak);
        edge2->next = node2->firstEdge;
        node2->firstEdge = edge2;
    }
}

void disconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edge = node1->firstEdge;
        adrEdge prev = NULL;

        while (edge != NULL && edge->nodeTujuan != node2) {
            prev = edge;
            edge = edge->next;
        }

        if (edge != NULL) { 
            if (prev == NULL) {
                node1->firstEdge = edge->next;
            } else {
                prev->next = edge->next;
            }
            delete edge;
        }
    }
}

void deleteNode(Graph &G, infoGraph nama) {
    adrNode nodeHapus = findNode(G, nama);
    if (nodeHapus == NULL) {
        cout << "node tidak ditemukan" << endl;
        return;
    }

    adrNode curr = G.First;
    while (curr != NULL) {
        if (curr != nodeHapus) {
            disconnectNode(curr, nodeHapus);
        }
        curr = curr->next;
    }

    adrEdge edge = nodeHapus->firstEdge;
    while (edge != NULL) {
        adrEdge temp = edge;
        edge = edge->next;
        delete temp;
    }
    nodeHapus->firstEdge = NULL;

    if (G.First == nodeHapus) {
        G.First = nodeHapus->next;
    } else {
        adrNode prev = G.First;
        while (prev->next != nodeHapus) {
            prev = prev->next;
        }
        prev->next = nodeHapus->next;
    }
    delete nodeHapus;
}

void printGraph(Graph G) {
    adrNode curr = G.First;
    while (curr != NULL) {
        cout << "node " << curr->namaKota << " terhubung ke: ";
        adrEdge edge = curr->firstEdge;
        while (edge != NULL) {
            cout << edge->nodeTujuan->namaKota << "(" << edge->jarak << " KM), ";
            edge = edge->next;
        }
        cout << endl;
        curr = curr->next;
    }
}