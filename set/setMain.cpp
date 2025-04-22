//
// Created by caoth on 4/21/2025.
//

#include <set>
#include <iostream>

using namespace std;

void first() {
    set<int> mySet;

    mySet.insert(5);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(2);
    mySet.insert(5);
    mySet.insert(3);

    cout << "Set: ";
    for (int value : mySet) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Count for 2: " << mySet.count(2) << endl;
    cout << "Count for 2: " << mySet.count(10) << endl;

    mySet.erase(4);

    cout << "After erase: ";
    for (int value : mySet) {
        cout << value << " ";
    }
}

void second() {
    set<int> s = {1, 3, 5, 7, 9};

    auto it1 = s.lower_bound(4); // first ≥ 4 → points to 5
    auto it2 = s.upper_bound(5); // first > 5  → points to 7

    if (it1 != s.end()) cout << "lower_bound(4): " << *it1 << endl;
    if (it2 != s.end()) cout << "upper_bound(5): " << *it2 << endl;
}

void third() {
    set<int> s = {2, 4, 6, 8, 10};

    auto lb = s.lower_bound(5);  // Should point to 6
    auto ub = s.upper_bound(6);  // Should point to 8

    if (lb != s.end()) cout << "lower_bound(5): " << *lb << endl;
    else cout << "lower_bound(5): not found" << endl;

    if (ub != s.end()) cout << "upper_bound(6): " << *ub << endl;
    else cout << "upper_bound(6): not found" << endl;

    auto outOfRange = s.lower_bound(11);  // Should be s.end()

    if (outOfRange == s.end()) {
        cout << "lower_bound(11): not found" << endl;
    }
}

int main() {
    third();
}