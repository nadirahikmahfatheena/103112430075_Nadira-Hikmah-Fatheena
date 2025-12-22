#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef struct BST *node; 

struct BST {
    int idProduk;      
    string namaProduk;
    int stok;
    node left;
    node right;
};

typedef node binTree; 
bool isEmpty(binTree tree);
void createTree(binTree &tree);
node alokasi(int id, string nama, int stok);
void dealokasi(node nodeHapus);
void insertNode(binTree &tree, node nodeBaru);
void searchById(binTree tree, int idCari);
void searchByProduct(binTree tree, string namaCari); 
bool deleteNode(binTree &tree, int idHapus);
void deleteTree(binTree &tree);
void inOrder(binTree tree);
void preOrder(binTree tree);
void postOrder(binTree tree);
void findMin(binTree tree);
void findMax(binTree tree);
node mostLeft(binTree tree);
void searchNameRec(binTree tree, string namaCari, bool &found); 

#endif