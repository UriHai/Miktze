#include <iostream>
#include "Miktze.h"

using std::cout;
using std::endl;

int main() {
    int* x = new int;
    double* y = new double;
    void* z = operator new (1337);
    printAttachments();
    delete(x);
    cout << "Deleted first allocation" << endl;
    printAttachments();
    delete(y);
    delete(z);
    cout << "Deleted all allocations" << endl;
    printAttachments();

    return 0;
}