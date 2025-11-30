#include <iostream>

using namespace std;

// Definisi Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    // 1. Membuat Root (Akar)
    Node* root = new Node(10);

    // 2. Menambahkan anak kiri dan kanan
    root->left = new Node(5);
    root->right = new Node(20);

    /*
       Visualisasi Tree yang terbentuk:
            10
           /  \
          5    20
    */

    // Cek hasil (print manual)
    cout << "Root: " << root->data << endl;
    cout << "Anak Kiri: " << root->left->data << endl;
    cout << "Anak Kanan: " << root->right->data << endl;

    return 0;
}