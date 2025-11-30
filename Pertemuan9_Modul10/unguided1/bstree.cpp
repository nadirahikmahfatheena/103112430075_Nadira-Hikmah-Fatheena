#include "bstree.h"

address alokasi(infotype x) {
    address nodeBaru = new Node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root; 
        }
    }
}

void printInorder(address root) {
    if (root == Nil) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " - "; 
    printInorder(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) {
        return 0; 
    } else {
        int lDepth = hitungKedalaman(root->left);
        int rDepth = hitungKedalaman(root->right);
        
        if (lDepth > rDepth)
            return (lDepth + 1);
        else 
            return (rDepth + 1);
    }
}

void printPreorder(address root) {
    if (root == Nil) {
        return;
    }
    cout << root->info << " - ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(address root) {
    if (root == Nil) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->info << " - ";
}