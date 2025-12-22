#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataFilm {
    string IDFilm;
    string judulFilm;
    int durasiFilm;     
    int tahunTayang;    
    float ratingFilm;   
};

struct DataGenre {
    string IDGenre;
    string namaGenre;
};

typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

struct nodeChild {
    DataFilm infoChild;
    adrChild next;
    adrChild prev;
};

struct listChild {
    adrChild first;
    adrChild last;
};

struct nodeParent {
    DataGenre infoParent;
    adrParent next;
    adrParent prev;
    listChild L_Child; 
};

struct listParent {
    adrParent first;
    adrParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent alokasiNodeParent(string IDGenre, string namaGenre);
adrChild alokasiNodeChild(string IDFilm, string judulFilm, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent &P);
void dealokasiNodeChild(adrChild &P);
void insertFirstParent(listParent &L, adrParent P);
void insertLastParent(listParent &L, adrParent P); 
void deleteAfterParent(listParent &L, adrParent prevNode);
void insertLastChild(listChild &L, adrChild P);
void hapusListChild(listChild &L); 
void searchFilmByRatingRange(listParent L, float min, float max);
void printStrukturMLL(listParent L);
adrParent findParentByID(listParent L, string IDGenre);

#endif