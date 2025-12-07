#include "MultiLL_Soal2.h"

bool isEmptyParent(listParent LP) { return LP.first == NULL; }
bool isEmptyChild(listChild LC) { return LC.first == NULL; }

void createListParent(listParent &LP) { LP.first = LP.last = NULL; }
void createListChild(listChild &LC) { LC.first = LC.last = NULL; }

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

void insertLastParent(listParent &LP, NodeParent nodeBaru) {
    if (isEmptyParent(LP)) { LP.first = LP.last = nodeBaru; } 
    else { nodeBaru->prev = LP.last; LP.last->next = nodeBaru; LP.last = nodeBaru; }
}

void insertLastChild(listChild &LC, NodeChild nodeBaru) {
    if (isEmptyChild(LC)) { LC.first = LC.last = nodeBaru; } 
    else { nodeBaru->prev = LC.last; LC.last->next = nodeBaru; LC.last = nodeBaru; }
}

void printMLLStructure(listParent LP) {
    NodeParent P = LP.first;
    while(P!=NULL){
        cout << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while(C!=NULL){ cout << " - " << C->isidata.namaHewan << endl; C=C->next;}
        P=P->next;
    }
}

void searchHewanByEkor(listParent LP, bool tail) {
    
    NodeParent P = LP.first;
    int idxParent = 1;
    bool foundAny = false;

    while(P != NULL) {
        NodeChild C = P->L_Child.first;
        int idxChild = 1;
        
        while(C != NULL) {
            if(C->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan 
                     << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl; 
                cout << "Bobot : " << C->isidata.bobot << endl;
                
                cout << "---------------------------" << endl;
                
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                
                cout << "---------------------------" << endl;
                cout << endl; 
                
                foundAny = true;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }

    if(!foundAny) {
        cout << "Data tidak ditemukan." << endl;
    }
}