//
// Created by caoth on 4/21/2025.
//
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <queue>

using namespace std;

void processData(const vector<int>& dataVec, list<int>& resultList) {
    auto iterVec = find_if(dataVec.begin(), dataVec.end(), [](int value){
        return value % 4 == 0;
    });

    if (iterVec != dataVec.end()) {
        for (auto it = iterVec; it != dataVec.end(); it++) {
            resultList.push_back(*it);
        }
        //Alt
        //copy(iterVec, dataVec.end(), back_inserter(resultList));

        //sort
        resultList.sort();

        //Remove larger than 50
        auto newEnd = remove_if(resultList.begin(), resultList.end(), [](int value){
            return value > 50;
        });
        resultList.erase(newEnd, resultList.end());

        //Alt
        //nums.remove_if([](int val) {
        //    return val >= 50;
        //});
    }
}

void first() {
    vector<int> data = {11, 15, 18, 24, 70, 12, 45};
    list<int> result;
    processData(data, result);

    for (int value : result) {
        cout << value << endl;
    }
}

void flipAndStore(const map<int, int>& aMap, list<int>& aList) {
    auto keyExist = std::find_if(aMap.begin(), aMap.end(), [](pair<int, int> value) {
        return value.first == value.second;
    });

    if (keyExist != aMap.end()) {
        for (auto it : aMap) {
            aList.push_front(it.first);
            aList.push_back(it.second);
        }
    } else {
        for (auto it = aMap.begin(); it != aMap.end(); ++it) {
            aList.push_front(it->second);
            aList.push_back(it->first);
        }
    }
}

void second() {
    map<int, int> testMap = {
            {1, 5}, {2, 2}, {3, 7}
    };
    list<int> result;
    flipAndStore(testMap, result);

    for (int value : result) {
        cout << value << endl;
    }
}

int filterAndLoad(const vector<int>& nums, stack<int>& st, queue<int>& qu) {
    auto divisibleThree = any_of(nums.begin(), nums.end(), [](int value){
        return value % 3 == 0;
    });

    if (divisibleThree) {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 1) {
                st.push(nums[i]);
            }
        }
        return st.top();
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                qu.push(nums[i]);
            }
        }
        return qu.back();
    }
}

void three() {
    vector<int> nums1 = {10, 15, 22, 30, 11};
    vector<int> nums2 = {4, 10, 8, 14};

    stack<int> st;
    queue<int> qu;

    int result1 = filterAndLoad(nums1, st, qu);
    cout << "Result from stack: " << result1 << endl;

    // Reset for second test
    while (!st.empty()) st.pop();
    while (!qu.empty()) qu.pop();

    int result2 = filterAndLoad(nums2, st, qu);
    cout << "Result from queue: " << result2 << endl;
}

int main() {
    three();
}