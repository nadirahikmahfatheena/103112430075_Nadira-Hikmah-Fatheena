#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(binTree tree){
    return tree == Nil;
}

void createTree(binTree &tree){
    tree = Nil;
}

node alokasi(int id, string nama, int stok){
    node nodeBaru = new BST;
    nodeBaru->idProduk = id;
    nodeBaru->namaProduk = nama;
    nodeBaru->stok = stok;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(binTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
    } else if(nodeBaru->idProduk < tree->idProduk){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->idProduk > tree->idProduk){
        insertNode(tree->right, nodeBaru);
    } else {
        cout << "ID Produk " << nodeBaru->idProduk << " sudah ada" << endl;
    }
}

void searchById(binTree tree, int idCari){
    if(isEmpty(tree)){
        cout << "Data ID " << idCari << " tidak ditemukan" << endl;
    } else {
        node nodeBantu = tree;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(idCari < nodeBantu->idProduk){
                nodeBantu = nodeBantu->left;
            } else if(idCari > nodeBantu->idProduk){
                nodeBantu = nodeBantu->right;
            } else {
                ketemu = true;
                break;
            }
        }

        if(ketemu){
            cout << "Data Ditemukan: [ID: " << nodeBantu->idProduk 
                 << ", Nama: " << nodeBantu->namaProduk 
                 << ", Stok: " << nodeBantu->stok << "]" << endl;
        } else {
            cout << "data ID " << idCari << " tidak ditemukan" << endl;
        }
    }
}

void searchNameRec(binTree tree, string namaCari, bool &found){
    if(tree != Nil){
        if(tree->namaProduk == namaCari){
            cout << "data ditemukan: [ID: " << tree->idProduk 
                 << ", Nama: " << tree->namaProduk 
                 << ", Stok: " << tree->stok << "]" << endl;
            found = true;
        }
        searchNameRec(tree->left, namaCari, found);
        searchNameRec(tree->right, namaCari, found);
    }
}

void searchByProduct(binTree tree, string namaCari){
    bool found = false;
    searchNameRec(tree, namaCari, found);
    if(!found){
        cout << "produk dengan nama \"" << namaCari << "\" tidak ditemukan" << endl;
    }
}

void preOrder(binTree tree){
    if(tree != Nil){
        cout << tree->idProduk << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(binTree tree){
    if(tree != Nil){
        inOrder(tree->left);
        cout << tree->idProduk << " ";
        inOrder(tree->right);
    }
}

void postOrder(binTree tree){
    if(tree != Nil){
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->idProduk << " ";
    }
}

node mostLeft(binTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

node mostRight(binTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;
}

void findMin(binTree tree){
    if(isEmpty(tree)){
        cout << "Tree kosong." << endl;
    } else {
        node minNode = mostLeft(tree);
        cout << "ID Terkecil: " << minNode->idProduk 
             << " (" << minNode->namaProduk << ")" << endl;
    }
}

void findMax(binTree tree){
    if(isEmpty(tree)){
        cout << "Tree kosong." << endl;
    } else {
        node maxNode = mostRight(tree);
        cout << "ID Terbesar: " << maxNode->idProduk 
             << " (" << maxNode->namaProduk << ")" << endl;
    }
}

bool deleteNode(binTree &tree, int idHapus) {
    if (tree == Nil) {
        return false;
    } else {
        if (idHapus < tree->idProduk) {
            return deleteNode(tree->left, idHapus);
        } else if (idHapus > tree->idProduk) {
            return deleteNode(tree->right, idHapus);
        } else {
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            else {
                node successor = mostLeft(tree->right);
                
                tree->idProduk = successor->idProduk;
                tree->namaProduk = successor->namaProduk;
                tree->stok = successor->stok;
                
                return deleteNode(tree->right, successor->idProduk);
            }
            return true;
        }
    }
}

void deleteTree(binTree &tree){
    if(tree != Nil){
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}