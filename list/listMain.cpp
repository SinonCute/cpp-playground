//
// Created by caoth on 4/21/2025.
//
#include <list>
#include <iostream>

using namespace std;

void first() {
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6};

    a.splice(a.begin(), b);

    cout << "List A: " << endl;
    for (int value : a) {
        cout << value << endl;
    }

    cout << "List B: " << endl;
    for (int value : b) {
        cout << value << endl;
    }
}

void second() {
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6};

    auto pos = ++a.begin();
    auto target = ++b.begin();

    a.splice(pos, b, target);

    cout << "List A: " << endl;
    for (int value : a) {
        cout << value << endl;
    }

    cout << "List B: " << endl;
    for (int value : b) {
        cout << value << endl;
    }
}

void three() {
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6, 7};

    auto rangeBegin = ++b.begin();
    auto rangeEnd = next(b.begin(), 3);

    auto targetPos = next(a.begin(), 2);

    a.splice(targetPos, b, rangeBegin, rangeEnd);

    cout << "List A: " << endl;
    for (int value : a) {
        cout << value << endl;
    }

    cout << "List B: " << endl;
    for (int value : b) {
        cout << value << endl;
    }
}

void four() {
    list<int> a = {10, 20, 30, 40};
    list<int> b = {1, 2, 3, 4, 5, 6, 7};

    auto lastOdd1 = b.end();
    auto lastOdd2 = b.end();

    for (auto it = b.begin(); it != b.end(); it++) {
        if (*it % 2 != 0) {
            lastOdd1 = lastOdd2;
            lastOdd2 = it;
        }
    }

    if (lastOdd1 != b.end()) {
        a.splice(a.end(), b, lastOdd1);
    }

    if (lastOdd2 != b.end()) {
        a.splice(a.end(), b, lastOdd2);
    }

    cout << "List A: " << endl;
    for (int value : a) {
        cout << value << endl;
    }

    cout << "List B: " << endl;
    for (int value : b) {
        cout << value << endl;
    }
}

void five() {
    list<int> nums = {1, 8, 3, 4, 9, 2, 5, 7, 6};

    nums.remove_if([](int a){
        return a % 2 != 0;
    });

    for (int value : nums) {
        cout << value << endl;
    }
}

int main() {
    five();
}