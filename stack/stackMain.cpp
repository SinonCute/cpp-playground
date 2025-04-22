//
// Created by caoth on 4/21/2025.
//
#include <stack>
#include <iostream>

using namespace std;

void first() {
    stack<int> nums;

    nums.push(10);
    nums.push(20);
    nums.push(30);

    cout << "TOP: " << nums.top() << endl;

    while (!nums.empty()) {
        cout << nums.top() << endl;
        nums.pop();
    }
}

void second() {

}

int main() {
    first();
}