#include "AnyList.h"
#include "iostream"
using namespace std;

int main() {
    AnyList list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);
    list.insertFront(50);

    list.print();
    cout << endl;
    list.rotateNodes();
    list.print();
}