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
