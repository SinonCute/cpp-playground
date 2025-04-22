//
// Created by caoth on 4/21/2025.
//

#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

void first() {
    multiset<int> myMultiset = {5, 3, 5, 7 , 3, 3};

    for (int value : myMultiset) {
        cout << value << endl;
    }

    cout << "Count 3: " << myMultiset.count(3) << endl;

    auto myPair = myMultiset.equal_range(5);

    for_each(myPair.first, myPair.second, [](int a){
        cout << a << endl;
    });
}

int main() {
    first();
}