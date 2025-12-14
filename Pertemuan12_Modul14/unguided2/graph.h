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