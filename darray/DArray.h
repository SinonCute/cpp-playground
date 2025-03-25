//
// Created by caoth on 3/24/2025.
//

#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>

const int CAP = 50;
// We declare the capacity as a global constant so
// that we can easily change the value if needed.

class DArray
{
public:
    DArray();
    // Default constructor
    // Initializes the array to the capacity
    // set by the global constant.

    DArray(int newCapacity);
    // Overloaded constructor
    // Initializes the array to a given capacity.

    void addElement(int newElement);
    // Function adds a given element to the array.

    int getNumOfElements() const;
    //Functions returns the number of elements in the array.

    void replaceElementAt(int newElement, int idx);
    // Function replaces an element stored at a given index with
    // a new element passed as a parameter. It assumes there is
    // enough space to insert the new element.

    bool compareArrays(const DArray& otherArray) const;
    // Function returns true if the calling object stores the
    // same values stored in the parameter object, all in the
    // same order.

    void printArray() const;
    // Function prints all elements in the array.
    // If the array is empty, it outputs an error message.

    void deleteLastElement();
    void swapFirstLast();
    void zeroFirstHalf();
    void replaceLastElement(int newValue);
    void copyOddsFrom(const DArray& source);


    ~DArray( );
    //Destructor

private:
    int *a;            //will point to an array of integers
    int capacity;      //capacity of the array
    int numOfElements; //total number of elements in the array
};

#endif