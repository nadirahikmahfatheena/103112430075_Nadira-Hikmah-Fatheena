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