#include "mll.h"

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent alokasiNodeParent(string IDGenre, string namaGenre) {
    adrParent P = new nodeParent;
    P->infoParent.IDGenre = IDGenre;
    P->infoParent.namaGenre = namaGenre;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child); 
    return P;
}

adrChild alokasiNodeChild(string IDFilm, string judulFilm, int durasi, int tahun, float rating) {
    adrChild P = new nodeChild;
    P->infoChild.IDFilm = IDFilm;
    P->infoChild.judulFilm = judulFilm;
    P->infoChild.durasiFilm = durasi;
    P->infoChild.tahunTayang = tahun;
    P->infoChild.ratingFilm = rating;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiNodeParent(adrParent &P) {
    delete P;
    P = NULL;
}

void dealokasiNodeChild(adrChild &P) {
    delete P;
    P = NULL;
}

void insertFirstParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteAfterParent(listParent &L, adrParent prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        adrParent delNode = prevNode->next;
        
        prevNode->next = delNode->next;
        if (delNode->next != NULL) {
            delNode->next->prev = prevNode;
        } else {
            L.last = prevNode; 
        }
        
        delNode->next = NULL;
        delNode->prev = NULL;

        hapusListChild(delNode->L_Child);
        
        dealokasiNodeParent(delNode);
    } else {
        cout << "gagal delete after parent: node prev tidak valid atau tidak ada node setelahnya" << endl;
    }
}

void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void hapusListChild(listChild &L) {
    adrChild P = L.first;
    while (P != NULL) {
        adrChild hapus = P;
        P = P->next;
        dealokasiNodeChild(hapus);
    }
    L.first = NULL;
    L.last = NULL;
}

void searchFilmByRatingRange(listParent L, float min, float max) {
    adrParent P = L.first;
    int idxParent = 1;
    bool found = false;

    while (P != NULL) {
        adrChild C = P->L_Child.first;
        int idxChild = 1;
        
        while (C != NULL) {
            if (C->infoChild.ratingFilm >= min && C->infoChild.ratingFilm <= max) {
                found = true;
                cout << "Data Film ditemukan pada list child dari node parent " << P->infoParent.namaGenre 
                     << " pada posisi ke-" << idxChild << "!" << endl;
                
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->infoChild.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << idxChild << endl;
                cout << "ID Film : " << C->infoChild.IDFilm << endl;
                cout << "Durasi Film : " << C->infoChild.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->infoChild.tahunTayang << endl;
                cout << "Rating Film : " << C->infoChild.ratingFilm << endl;
                
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->infoParent.IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << idxParent << endl;
                cout << "Nama Genre : " << P->infoParent.namaGenre << endl;
                cout << "============================================" << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }

    if (!found) {
        cout << "tidak ada film dengan rating antara " << min << " - " << max << endl;
    }
}

void printStrukturMLL(listParent L) {
    if (L.first == NULL) {
        cout << "list parent kosong" << endl;
        return;
    }

    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->infoParent.IDGenre << endl;
        cout << "Nama Genre : " << P->infoParent.namaGenre << endl;
        
        adrChild C = P->L_Child.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :" << endl;
            cout << "      ID Film : " << C->infoChild.IDFilm << endl;
            cout << "      Judul Film : " << C->infoChild.judulFilm << endl;
            cout << "      Durasi Film : " << C->infoChild.durasiFilm << " menit" << endl;
            cout << "      Tahun Tayang : " << C->infoChild.tahunTayang << endl;
            cout << "      Rating Film : " << C->infoChild.ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "-------------------------" << endl;
        P = P->next;
        i++;
    }
}

adrParent findParentByID(listParent L, string IDGenre) {
    adrParent P = L.first;
    while(P != NULL) {
        if(P->infoParent.IDGenre == IDGenre) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}