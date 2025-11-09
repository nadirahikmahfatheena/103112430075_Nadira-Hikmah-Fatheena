#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    stackTable S;
    createStack(S);

    createStack(S);
    getInputStream(S);
    view(S);
    cout << "balik stack" << endl;
    balikStack(S);
    view(S);
    cout << endl;

    return 0;
}
