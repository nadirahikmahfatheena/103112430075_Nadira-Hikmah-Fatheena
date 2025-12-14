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