#include "MultiLL_Soal3.h"

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }
bool isEmptyParent(listParent LP) { return LP.first == NULL; }
bool isEmptyChild(listChild LC) { return LC.first == NULL; }

NodeParent alokasiNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol; P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL; createListChild(P->L_Child); return P;
}

NodeChild alokasiNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn; C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat; C->isidata.ekor = ekor; C->isidata.bobot = bobot;
    C->next = C->prev = NULL; return C;
}

void dealokasiNodeParent(NodeParent &P) { delete P; P = NULL; }
void dealokasiNodeChild(NodeChild &C) { delete C; C = NULL; }

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (isEmptyParent(LP)) { LP.first = LP.last = nodeBaru; }
    else { nodeBaru->prev = LP.last; LP.last->next = nodeBaru; LP.last = nodeBaru; }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (isEmptyChild(LC)) { LC.first = LC.last = nodeBaru; }
    else { nodeBaru->prev = LC.last; LC.last->next = nodeBaru; LC.last = nodeBaru; }
}

void printMLLStructure(listParent LP) {
    if (isEmptyParent(LP)) {
        cout << "List Kosong." << endl;
        return;
    }
    
    NodeParent P = LP.first;
    int idxParent = 1;
    
    while(P != NULL) {
        cout << "Parent " << idxParent << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
        
        NodeChild C = P->L_Child.first;
        if(C == NULL) {
            cout << "   (tidak ada child)" << endl;
        } else {
            int idxChild = 1;
            while(C != NULL) {
                cout << "   - Child " << idxChild << " :" << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << C->isidata.ekor << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                idxChild++;
            }
        }
        cout << "---------------------------" << endl; 
        P = P->next;
        idxParent++;
    }
}

NodeParent findParentByID(listParent LP, string idGol) {
    NodeParent P = LP.first;
    while(P != NULL) {
        if(P->isidata.idGolongan == idGol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteAfterParent(listParent &LP, NodeParent nodePrev) {
    if (nodePrev != NULL && nodePrev->next != NULL) {
        NodeParent nodeHapus = nodePrev->next;
        
        nodePrev->next = nodeHapus->next;
        
        if (nodeHapus->next != NULL) {
            nodeHapus->next->prev = nodePrev;
        } else {
            LP.last = nodePrev;
        }
        
        NodeChild C = nodeHapus->L_Child.first;
        while(C != NULL) {
            NodeChild hapusC = C;
            C = C->next;
            dealokasiNodeChild(hapusC);
        }
        
        dealokasiNodeParent(nodeHapus);
    }
}