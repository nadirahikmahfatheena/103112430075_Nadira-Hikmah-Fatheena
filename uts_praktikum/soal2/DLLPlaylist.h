#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>
#include <iostream>

using namespace std;

typedef struct Node* address;

struct Song {
    string title;
    string artist;
    int durationSec;
    int playCount;
    float rating; // 0.0 - 5.0
};

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

inline float popularityScore(const Song &s) {
    return 0.8f * s.playCount + 20.0f * s.rating;
}

bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Song &S);
void deallocate(address &addr);
void insertFirst(List &L, const Song &S);
void insertLast(List &L, const Song &S);
void insertAfter(List &L, address Q, const Song &S);
void insertBefore(List &L, address Q, const Song &S);
void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);
void updateAtPosition(List &L, int posisi, const Song &S);
void updateBefore(List &L, int posisi, address Q, const Song &S);
void viewList(const List &L);
void searchByPopularityRange(const List &L, float minScore, float maxScore);

#endif 