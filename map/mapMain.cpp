//
// Created by caoth on 4/21/2025.
//

#include <string>
#include <map>
#include <iostream>

using namespace std;

void first() {
    map<string, int> ages;

    ages["Alice"] = 21;
    ages["Bob"] = 25;
    ages["Charlie"] = 19;

    for (pair<string, int> value : ages) {
        cout << "Name: " << value.first << " is " << value.second << endl;
    }

    cout << "Bob: " << ages.count("Bob") << endl;
    cout << "David: " << ages.count("David") << endl;

    cout << ages.at("Da") << endl;
    cout << ages.at("Charlie") << endl;
}

void challenge() {
    // Part 1: map
    map<string, int> bestGrade;
    bestGrade["Alice"] = 85;
    bestGrade["Bob"] = 92;
    bestGrade["Charlie"] = 78;

    bestGrade["Bob"] = 95; // update grade

    cout << "Best Grades:\n";
    for (auto& entry : bestGrade) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Part 2: multimap
    multimap<string, int> allGrades;

    allGrades.insert({ "Alice", 80 });
    allGrades.insert({ "Alice", 85 });
    allGrades.insert({ "Alice", 90 });
    allGrades.insert({ "Bob", 88 });
    allGrades.insert({ "Bob", 92 });
    allGrades.insert({ "Bob", 95 });

    cout << "\nAll grades for Alice:\n";
    auto range = allGrades.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;

    cout << "\nAll student grades:\n";
    for (auto& entry : allGrades) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main() {
    challenge();
}