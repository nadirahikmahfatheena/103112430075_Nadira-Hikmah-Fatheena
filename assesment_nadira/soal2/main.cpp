#include <iostream>
#include "mll.h"

using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    adrParent P1 = alokasiNodeParent("G001", "Action");
    adrParent P2 = alokasiNodeParent("G002", "Comedy");
    adrParent P3 = alokasiNodeParent("G003", "Horror");
    adrParent P4 = alokasiNodeParent("G004", "Romance");

    insertFirstParent(LP, P1); 
    insertLastParent(LP, P2);  
    insertLastParent(LP, P3);  
    insertLastParent(LP, P4);  

    adrChild C1_1 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(P1->L_Child, C1_1);
    adrChild C2_1 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(P2->L_Child, C2_1);
    adrChild C2_2 = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(P2->L_Child, C2_2);

    adrChild C3_1 = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(P3->L_Child, C3_1);

    adrChild C4_1 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(P4->L_Child, C4_1);

    adrChild C4_2 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(P4->L_Child, C4_2);

    cout << "OUTPUT 1: printStrukturMLL() AWAL" << endl;
    printStrukturMLL(LP);
    cout << endl;

    cout << "OUTPUT 2: searchFilmByRatingRange() Rating 8.0-8.5" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);
    cout << endl;

    cout << "OUTPUT 3: Menghapus Node G002 (Comedy) dan anaknya" << endl;
    deleteAfterParent(LP, P1); 
    
    cout << endl;

    cout << "OUTPUT 4: printStrkturMLL() SETELAH PENGHAPUSAN" << endl;
    printStrukturMLL(LP);

    return 0;
}