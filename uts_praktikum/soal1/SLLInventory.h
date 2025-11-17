#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
#include <iostream>

using namespace std;

typedef struct Node* address;

struct Product {
    string nama;
    string sku;
    int jumlah;
    float hargaSatuan;
    float diskonPersen;
};

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

inline float finalPrice(const Product &p) {
    return p.hargaSatuan * (1.0f - p.diskonPersen / 100.0f);
}

bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Product &P);    
void deallocate(address &addr);        
void insertFirst(List &L, const Product &P);
void insertLast(List &L, const Product &P);
void insertAfter(List &L, address Q, const Product &P); 
void deleteFirst(List &L, Product &P);   
void deleteLast(List &L, Product &P);   
void deleteAfter(List &L, address Q, Product &P); 
void updateAtPosition(List &L, int posisi, const Product &P); 
void viewList(const List &L);
void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice);
void maxHargaAkhir(const List &L); 

#endif 