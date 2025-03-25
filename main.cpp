#include "doublylist/DoublyList.h"
#include "iostream"
#include "darray/DArray.h"

using namespace std;

int main() {
    DArray source;
    source.addElement(10);
    source.addElement(15);
    source.addElement(22);
    source.addElement(33);
    source.addElement(40);
    source.addElement(99);

    cout << "\nSource array:\n";
    source.printArray();
    cout << "Count: " << source.getNumOfElements() << endl;

    DArray oddOnly;
    oddOnly.copyOddsFrom(source);

    cout << "\nCalling object after copying odds:\n";
    oddOnly.printArray();
    cout << "Count: " << oddOnly.getNumOfElements() << endl;

}