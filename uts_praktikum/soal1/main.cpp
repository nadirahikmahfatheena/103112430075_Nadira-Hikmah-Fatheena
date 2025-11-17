#include <iostream>
#include "SLLInventory.h"

using namespace std;

int main() {
    List L;
    Product P;
    
    createList(L);
    
    P = {"pulpen", "A001", 20, 2500.0f, 0.0f};
    insertLast(L, P);
    
    P = {"buku tulis", "A002", 15, 5000.0f, 10.0f};
    insertLast(L, P);
    
    P = {"penghapus", "A003", 30, 1500.0f, 0.0f};
    insertLast(L, P);
    
    cout << "list" << endl;
    viewList(L);
    
    cout << "setelah delete first" << endl;
    deleteFirst(L, P);
    viewList(L);
    
    cout << "update posisi ke-2" << endl;
    P = {"stabilo", "A010", 40, 9000.0f, 5.0f};
    updateAtPosition(L, 2, P);
    viewList(L);
    
    cout << "search final price (2000 - 7000)" << endl;
    searchByFinalPriceRange(L, 2000.0f, 7000.0f);
    
    cout << "produk harga akhir terbesar" << endl;
    maxHargaAkhir(L);

    return 0;
}

