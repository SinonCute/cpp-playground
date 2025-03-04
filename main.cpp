#include "AnyList.h"
#include "iostream"
using namespace std;

int main() {
    AnyList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.print();

    cout << endl;
    cout << "---------" << endl;

    list.insertBefore(25, 20);
    list.print();
}
