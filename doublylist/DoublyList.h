
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

class DLLNode
{
public:
    DLLNode() : data(0), prev(nullptr), next(nullptr) {}
    DLLNode(int theData, DLLNode* prevLink, DLLNode* nextLink)
            : data(theData), prev(prevLink), next(nextLink) {}
    int getData() const { return data; }
    DLLNode* getPrev() const { return prev; }
    DLLNode* getNext() const { return next; }
    void setData(int theData) { data = theData; }
    void setPrev(DLLNode* prevLink) { prev = prevLink; }
    void setNext(DLLNode* nextLink) { next = nextLink; }
    ~DLLNode(){}
private:
    int data;   // To simplify, we are using only one piece of data.
    DLLNode* prev;
    DLLNode* next;
};

class DoublyList
{
public:
    DoublyList() : first(nullptr), last(nullptr), count(0) {}

    int getCount() const;

    void insertFront(int newData);

    void swapSecondWithLast(DoublyList &otherList);

    void printForward() const;
    void printReverse() const;

    void deleteFirstNode();
    void deleteSecondNode();
    void deleteLastNode();
    void deleteBeforeLastNode();
    void deleteMiddleNode();
    void swapFirstLast();
    void swapFirstSecond();
    void swapFirstBeforeLast();
    void moveFirstBeforeLast();

    void rotateNodes(int k);

    void copyTo(DoublyList& otherList) const;
    void swapWith(DoublyList& otherList);
    bool isEqual(const DoublyList& otherList) const;

    void copyToPosition(DoublyList& otherList, int position) const;


    void clearList();
    ~DoublyList();

    void insertBack(int i);

private:
    // Pointer to the first node in the list.
    DLLNode*first;
    // Pointer to the last node in the list.
    DLLNode*last;
    // Number of nodes in the list.
    int count;
};

#endif