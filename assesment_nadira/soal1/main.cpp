#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    binTree tree;
    createTree(tree);

    cout << "1. input data" << endl;
    insertNode(tree, alokasi(50, "Monitor LED", 10));
    insertNode(tree, alokasi(30, "Keyboard RGB", 20));
    insertNode(tree, alokasi(70, "Mouse Gaming", 15));
    insertNode(tree, alokasi(20, "Kabel HDMI", 50));
    insertNode(tree, alokasi(40, "Headset 7.1", 12));
    insertNode(tree, alokasi(60, "Webcam HD", 8));
    insertNode(tree, alokasi(80, "Speaker BT", 5));
    cout << "data berhasil diinput" << endl << endl;

    cout << "2. traversal" << endl;
    cout << "InOrder   : "; inOrder(tree); cout << endl;
    cout << "PreOrder  : "; preOrder(tree); cout << endl;
    cout << "PostOrder : "; postOrder(tree); cout << endl << endl;

    cout << "3. searchById (40)" << endl;
    searchById(tree, 40);
    cout << endl;

    cout << "4. searchById (99)" << endl;
    searchById(tree, 99);
    cout << endl;

    cout << "5. searchByProduct (\"Webcam HD\")" << endl;
    searchByProduct(tree, "Webcam HD");
    cout << endl;

    cout << "6. searchByProduct (\"Printer\")" << endl;
    searchByProduct(tree, "Printer");
    cout << endl;

    cout << "7. find Min & Max" << endl;
    findMin(tree);
    findMax(tree);
    cout << endl;

    cout << "8. deleteNode (20)" << endl;
    if(deleteNode(tree, 20)) cout << "node 20 berhasil dihapus" << endl;
    else cout << "gagal hapus" << endl;
    cout << endl;

    cout << "9. inOrder" << endl;
    inOrder(tree); cout << endl << endl;

    cout << "10. deleteNode (30)" << endl;
    if(deleteNode(tree, 30)) cout << "node 30 berhasil dihapus" << endl;
    cout << endl;

    cout << "11. inOrder" << endl;
    inOrder(tree); cout << endl << endl;

    cout << "12. deleteNode (50)" << endl;
    if(deleteNode(tree, 50)) cout << "node 50 berhasil dihapus" << endl;
    cout << endl;

    cout << "13. inOrder" << endl;
    inOrder(tree); cout << endl << endl;

    cout << "14. deleteTree" << endl;
    deleteTree(tree);
    cout << "tree dihapus seluruhnya" << endl << endl;

    cout << "15. inOrder" << endl;
    cout << "Isi Tree: "; 
    inOrder(tree); 
    cout << "(kosong)" << endl;

    return 0;
}