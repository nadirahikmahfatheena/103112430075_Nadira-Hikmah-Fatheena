#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

typedef string infoGraph; 
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph namaKota;
    int visited;        
    adrEdge firstEdge;  
    adrNode next;       
};

struct ElmEdge {
    adrNode nodeTujuan; 
    int jarak;          
    adrEdge next;       
};

struct Graph {
    adrNode First;
};

void createGraph(Graph &G);
adrNode alokasiNode(infoGraph nama);
adrEdge alokasiEdge(adrNode tujuan, int jarak);
void insertNode(Graph &G, infoGraph nama);
adrNode findNode(Graph G, infoGraph nama);
void connectNode(Graph &G, infoGraph nama1, infoGraph nama2, int jarak);
void disconnectNode(adrNode node1, adrNode node2);
void deleteNode(Graph &G, infoGraph nama);
void printGraph(Graph G);

#endif