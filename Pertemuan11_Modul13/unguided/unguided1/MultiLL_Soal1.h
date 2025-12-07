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