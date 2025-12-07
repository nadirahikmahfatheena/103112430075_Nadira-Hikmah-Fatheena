#include "MultiLL_Soal1.h"

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = ekor;
    C->isidata.bobot = bobot;
    C->next = C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (LP.first == NULL) {
        LP.first = LP.last = nodeBaru;
    } else {
        nodeBaru->prev = LP.last;
        LP.last->next = nodeBaru;
        LP.last = nodeBaru;
    }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (LC.first == NULL) {
        LC.first = LC.last = nodeBaru;
    } else {
        nodeBaru->prev = LC.last;
        LC.last->next = nodeBaru;
        LC.last = nodeBaru;
    }
}

void printMLLStructure(listParent LP) {
    if (LP.first == NULL) { cout << "List Kosong" << endl; return; }
    NodeParent P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << "\nID Golongan: " << P->isidata.idGolongan 
             << "\nNama Golongan: " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        if (C == NULL) cout << "(tidak ada child)" << endl;
        else {
            int j = 1;
            while (C != NULL) {
                cout << " - Child " << j << ":\n   ID Hewan: " << C->isidata.idHewan 
                     << "\n   Nama Hewan: " << C->isidata.namaHewan 
                     << "\n   Habitat: " << C->isidata.habitat 
                     << "\n   Ekor: " << C->isidata.ekor 
                     << "\n   Bobot: " << C->isidata.bobot << endl;
                C = C->next; j++;
            }
        }
        cout << endl;
        P = P->next; i++;
    }
}