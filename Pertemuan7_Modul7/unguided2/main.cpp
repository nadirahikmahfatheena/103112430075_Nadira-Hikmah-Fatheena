#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    stackTable S;
    createStack(S);

    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    view(S);            
    cout << "balik stack" << endl;
    balikStack(S);
    view(S);            
    cout << endl;

    return 0;
}
