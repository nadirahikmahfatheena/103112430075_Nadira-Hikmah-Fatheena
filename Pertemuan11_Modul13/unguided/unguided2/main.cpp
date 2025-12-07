#include "MultiLL_Soal2.h"

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent G1 = alokasiNodeParent("G001", "Aves");
    NodeParent G2 = alokasiNodeParent("G002", "Mamalia");
    NodeParent G3 = alokasiNodeParent("G003", "Pisces");
    NodeParent G4 = alokasiNodeParent("G004", "Amfibi");
    NodeParent G5 = alokasiNodeParent("G005", "Reptil");
    
    insertLastParent(LP, G1); insertLastParent(LP, G2); 
    insertLastParent(LP, G3); insertLastParent(LP, G4); insertLastParent(LP, G5);

    insertLastChild(G1->L_Child, alokasiNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, alokasiNodeChild("AV002", "Bebek", "Air", true, 2.0));
    
    insertLastChild(G2->L_Child, alokasiNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, alokasiNodeChild("M003", "Gorila", "Hutan", false, 160)); // <-- Target 1 (Ekor False)
    insertLastChild(G2->L_Child, alokasiNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->L_Child, alokasiNodeChild("AM001", "Kodok", "Sawah", false, 0.2)); // <-- Target 2 (Ekor False)

    searchHewanByEkor(LP, false);

    return 0;
}