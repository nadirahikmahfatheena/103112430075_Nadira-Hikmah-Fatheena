#include <iostream>
#include "DLLPlaylist.h"

using namespace std;

int main() {
    List L;
    Song S;
    
    createList(L);
    
    cout << "tambah 3 lagu" << endl;
    S = {"Senja di Kota", "Nona Band", 210, 150, 4.2f};
    insertLast(L, S);
    
    S = {"Langkahmu", "Delta", 185, 320, 4.8f};
    insertLast(L, S);
    
    S = {"Hujan Minggu", "Arka", 240, 90, 3.9f};
    insertLast(L, S);
    
    cout << "list awal" << endl;
    viewList(L);
    
    cout << "setelah delete last 1x" << endl;
    deleteLast(L, S);
    viewList(L);
    
    cout << "update posisi ke-2" << endl;
    S = {"Pelita", "Luna", 200, 260, 4.5f};
    updateAtPosition(L, 2, S);
    viewList(L);
    
    cout << "operasi before" << endl;
    
    address nodePos2 = L.head;
    for (int i = 1; i < 2 && nodePos2 != NULL; i++) {
        nodePos2 = nodePos2->next;
    }
    
    cout << "insert before node posisi 2" << endl;
    S = {"Senandung", "Mira", 175, 120, 4.0f};
    insertBefore(L, nodePos2, S);
    viewList(L);
    
    nodePos2 = L.head;
    for (int i = 1; i < 2 && nodePos2 != NULL; i++) {
        nodePos2 = nodePos2->next;
    }
    
    cout << "update bfore node posisi 2" << endl;
    S = {"Mimpi Indah", "Budi", 195, 200, 4.3f};
    updateBefore(L, 2, nodePos2, S);
    viewList(L);
    
    address nodePos3 = L.head;
    for (int i = 1; i < 3 && nodePos3 != NULL; i++) {
        nodePos3 = nodePos3->next;
    }
    
    cout << "delete before posisi 3" << endl;
    deleteBefore(L, nodePos3, S);
    viewList(L);
    
    cout << "serach popularity score" << endl;
    searchByPopularityRange(L, 150.0f, 300.0f);
    
    return 0;
}