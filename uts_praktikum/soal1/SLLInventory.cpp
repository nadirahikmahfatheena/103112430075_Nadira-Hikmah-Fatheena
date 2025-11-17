#include "SLLInventory.h"
#include <iomanip>

bool isEmpty(const List &L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(const Product &P) {
    address newNode = new Node;
    newNode->info = P;
    newNode->next = NULL;
    return newNode;
}

void deallocate(address &addr) {
    delete addr;
    addr = NULL;
}

void insertFirst(List &L, const Product &P) {
    address newNode = allocate(P);
    newNode->next = L.head;
    L.head = newNode;
}

void insertLast(List &L, const Product &P) {
    address newNode = allocate(P);
    
    if (isEmpty(L)) {
        L.head = newNode;
    } else {
        address current = L.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAfter(List &L, address Q, const Product &P) {
    if (Q != NULL) {
        address newNode = allocate(P);
        newNode->next = Q->next;
        Q->next = newNode;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = temp->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == NULL) {
            P = L.head->info;
            deallocate(L.head);
            L.head = NULL;
        } else {
            address current = L.head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            P = current->next->info;
            deallocate(current->next);
            current->next = NULL;
        }
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, const Product &P) {
    if (posisi < 1) return;
    
    address current = L.head;
    int count = 1;
    
    while (current != NULL && count < posisi) {
        current = current->next;
        count++;
    }
    
    if (current != NULL) {
        current->info = P;
    }
}

void viewList(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address current = L.head;
    int no = 1;

    while (current != NULL) {
        float finalPriceValue = finalPrice(current->info);
        cout << "Produk " << no << ":" << endl;
        cout << "  Nama         : " << current->info.nama << endl;
        cout << "  SKU          : " << current->info.sku << endl;
        cout << "  Jumlah       : " << current->info.jumlah << endl;
        cout << "  Harga Satuan : " << current->info.hargaSatuan << endl;
        cout << "  Diskon %     : " << current->info.diskonPersen << endl;
        cout << "  Final Price  : " << finalPriceValue << endl;
        cout << endl;

        current = current->next;
        no++;
    }
}

void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    cout << "Menampilkan produk dengan final price dalam rentang " << minPrice << " - " << maxPrice << ":\n\n";

    address current = L.head;
    int found = 0;

    while (current != NULL) {
        float finalPriceValue = finalPrice(current->info);

        if (finalPriceValue >= minPrice && finalPriceValue <= maxPrice) {
            cout << "Produk " << (found + 1) << ":" << endl;
            cout << "  Nama         : " << current->info.nama << endl;
            cout << "  SKU          : " << current->info.sku << endl;
            cout << "  Jumlah       : " << current->info.jumlah << endl;
            cout << "  Harga Satuan : " << current->info.hargaSatuan << endl;
            cout << "  Diskon %     : " << current->info.diskonPersen << endl;
            cout << "  Final Price  : " << finalPriceValue << endl;
            cout << endl;
            found++;
        }

        current = current->next;
    }

    if (found == 0) {
        cout << "Tidak ada produk dengan final price dalam rentang " << minPrice << " - " << maxPrice << endl;
    }
    cout << endl;
}

void maxHargaAkhir(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address current = L.head;
    float maxPrice = finalPrice(current->info);
    int posisi = 1;
    int maxPosisi = 1;

    // Cari harga akhir maksimum
    while (current != NULL) {
        float currentPrice = finalPrice(current->info);
        if (currentPrice > maxPrice) {
            maxPrice = currentPrice;
        }
        current = current->next;
        posisi++;
    }

    cout << "Produk dengan harga akhir terbesar (" << maxPrice << "):" << endl;
    cout << endl;

    current = L.head;
    posisi = 1;
    int found = 0;

    while (current != NULL) {
        float currentPrice = finalPrice(current->info);
        if (currentPrice == maxPrice) {
            cout << "Posisi " << posisi << ":" << endl;
            cout << "  Nama         : " << current->info.nama << endl;
            cout << "  SKU          : " << current->info.sku << endl;
            cout << "  Jumlah       : " << current->info.jumlah << endl;
            cout << "  Harga Satuan : " << current->info.hargaSatuan << endl;
            cout << "  Diskon %     : " << current->info.diskonPersen << endl;
            cout << "  Final Price  : " << currentPrice << endl;
            cout << endl;
            found++;
        }
        current = current->next;
        posisi++;
    }
}
