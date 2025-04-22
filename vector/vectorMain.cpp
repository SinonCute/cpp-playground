//
// Created by caoth on 4/20/2025.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void one() {
    vector<int> vec{10, 20, 30, 40, 50};

//    vec[0] = 10;
//    vec[1] = 20;
//    vec[2] = 30;
//    vec[3] = 40;
//    vec[4] = 50;

    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl;

    vec.erase(vec.cbegin() + 1);

    for (int i : vec){
        cout << i << endl;
    }
}

void two() {
    vector<int> vec{100, 200, 300};

    // Insert 150 at position 1
    vec.insert(vec.begin() + 1, 150);
    cout << "After insert: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    // Change the value at index 2 to 350 using .at()
    vec.at(2) = 350;
    cout << "After at(): ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    // Resize vector to 5 elements (new ones = 0)
    vec.resize(5, 0);
    cout << "After resize: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    // Erase the first element
    vec.erase(vec.begin());
    cout << "After erase: ";
    for (int val : vec) cout << val << " ";
    cout << endl;
}

void three() {
    vector<int> nums = {5, 12, 8, 7, 20, 3, 15};

    int count = count_if(nums.cbegin(), nums.cend(), [](int value){
        return value == 7;
    });

    cout << "There are " << count << " of number 7" << endl;

    auto newEnd = remove_if(nums.begin(), nums.end(), [](int value){
        return value < 10;
    });

    nums.erase(newEnd, nums.end());

    std::sort(nums.begin(), nums.end(), [](int first, int second){
        return second < first;
    });

    for (int i : nums){
        cout << i << endl;
    }
}

void four() {
    vector<int> nums = {3, 6, 9, 12, 15, 18, 21};

    auto newEnd = remove_if(nums.begin(), nums.end(), [](int value){
       return value % 2 != 0;
    });
    nums.erase(newEnd, nums.end());

    transform(nums.begin(), nums.end(), nums.begin(), [](int value){
        return value * 2;
    });

    for (int i : nums) {
        cout << i << endl;
    }
}

void five() {
    vector<int> nums = {2, 5, 8, 11, 14};

    int vectorSize = nums.size();
    for (int i = 0; i < vectorSize; i++) {
        if (nums[i] % 2 == 0) {
            nums[i] = -1;
        }
    }

    for (int i : nums) {
        cout << i << endl;
    }
}

int main() {
    five();
}
