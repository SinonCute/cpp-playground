//
// Created by caoth on 4/21/2025.
//
#include <queue>
#include <iostream>

using namespace std;

void first() {
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << "Front value: " << myQueue.front() << endl;
    cout << "Back value: " << myQueue.back() << endl;

    while (!myQueue.empty()) {
        cout << "Before pop: " << myQueue.front() << endl;
        myQueue.pop();
    }
}

int main() {
    first();
}