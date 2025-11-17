#include "DLLPlaylist.h"
#include <iomanip>

bool isEmpty(const List &L) {
    return L.head == NULL && L.tail == NULL;
}

void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

address allocate(const Song &S) {
    address newNode = new Node;
    newNode->info = S;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void deallocate(address &addr) {
    delete addr;
    addr = NULL;
}

void insertFirst(List &L, const Song &S) {
    address newNode = allocate(S);
    
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

void insertLast(List &L, const Song &S) {
    address newNode = allocate(S);
    
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void insertAfter(List &L, address Q, const Song &S) {
    if (Q != NULL) {
        address newNode = allocate(S);
        newNode->next = Q->next;
        newNode->prev = Q;
        
        if (Q->next != NULL) {
            Q->next->prev = newNode;
        } else {
            L.tail = newNode;
        }
        Q->next = newNode;
    }
}

void insertBefore(List &L, address Q, const Song &S) {
    if (Q != NULL) {
        address newNode = allocate(S);
        newNode->prev = Q->prev;
        newNode->next = Q;
        
        if (Q->prev != NULL) {
            Q->prev->next = newNode;
        } else {
            L.head = newNode;
        }
        Q->prev = newNode;
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address temp = L.head;
        S = temp->info;
        
        if (L.head == L.tail) {
            L.head = NULL;
            L.tail = NULL;
        } else {
            L.head = temp->next;
            L.head->prev = NULL;
        }
        deallocate(temp);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address temp = L.tail;
        S = temp->info;
        
        if (L.head == L.tail) {
            L.head = NULL;
            L.tail = NULL;
        } else {
            L.tail = temp->prev;
            L.tail->next = NULL;
        }
        deallocate(temp);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        S = temp->info;
        Q->next = temp->next;
        
        if (temp->next != NULL) {
            temp->next->prev = Q;
        } else {
            L.tail = Q;
        }
        deallocate(temp);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != NULL && Q->prev != NULL) {
        address temp = Q->prev;
        S = temp->info;
        Q->prev = temp->prev;
        
        if (temp->prev != NULL) {
            temp->prev->next = Q;
        } else {
            L.head = Q;
        }
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, const Song &S) {
    if (posisi < 1) return;
    
    address current = L.head;
    int count = 1;
    
    while (current != NULL && count < posisi) {
        current = current->next;
        count++;
    }
    
    if (current != NULL) {
        current->info = S;
    }
}

void updateBefore(List &L, int posisi, address Q, const Song &S) {
    if (Q != NULL && Q->prev != NULL) {
        Q->prev->info = S;
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
        float popScore = popularityScore(current->info);
        cout << "No " << no << endl;
        cout << "  Title: " << current->info.title << endl;
        cout << "  Artist: " << current->info.artist << endl;
        cout << "  Duration: " << current->info.durationSec << " detik" << endl;
        cout << "  PlayCount: " << current->info.playCount << endl;
        cout << "  Rating: " << current->info.rating << endl;
        cout << "  Popularity Score: " << popScore << endl;
        cout << endl;
        
        current = current->next;
        no++;
    }
}

void searchByPopularityRange(const List &L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
        return;
    }
    
    cout << "lagu dengan popularity score dalam rentang " << minScore << " - " << maxScore << ":" << endl << endl;
    
    address current = L.head;
    int no = 1;
    int found = 0;
    
    while (current != NULL) {
        float popScore = popularityScore(current->info);
        
        if (popScore >= minScore && popScore <= maxScore) {
            cout << "No " << no << endl;
            cout << "  Title: " << current->info.title << endl;
            cout << "  Artist: " << current->info.artist << endl;
            cout << "  Duration: " << current->info.durationSec << " detik" << endl;
            cout << "  PlayCount: " << current->info.playCount << endl;
            cout << "  Rating: " << current->info.rating << endl;
            cout << "  Popularity Score: " << popScore << endl;
            cout << endl;
            found++;
        }
        
        current = current->next;
        no++;
    }
    
    if (found == 0) {
        cout << "Tidak ada lagu dengan popularity score dalam rentang " << minScore << " - " << maxScore << endl;
    }
    cout << endl;
}