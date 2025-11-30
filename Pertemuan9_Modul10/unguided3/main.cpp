#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    
    address root = Nil;
    
    insertNode(root, 6); 
    insertNode(root, 4); 
    insertNode(root, 7); 
    insertNode(root, 2); 
    insertNode(root, 5); 
    insertNode(root, 1); 
    insertNode(root, 3); 
    
    
    cout << "Pre-Order  : ";
    printPreorder(root);
    cout << endl;
    
    cout << "In-Order   : "; 
    printInorder(root);
    cout << endl;
    
    cout << "Post-Order : ";
    printPostorder(root);
    cout << endl;
    
    return 0;
}