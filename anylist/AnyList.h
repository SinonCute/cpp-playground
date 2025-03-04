//
// Created by caoth on 2/28/2025.
//

#ifndef UNTITLED_ANYLIST_H
#define UNTITLED_ANYLIST_H


class Node
{
public:
    Node() : data(0), next(nullptr) {}
    Node(int theData, Node *newNext)
            : data(theData), next(newNext){}
    Node* getNext() const { return next; }
    int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setNext(Node *newNext) { next = newNext; }
    ~Node(){}
private:
    int data;
    Node *next; // Pointer that points to next node.
};


class AnyList
{
public:
    AnyList() : first(nullptr), count(0) {}

    void insertFront(int);
    void insertAtBeginning(int);
    void insertAtEnd(int);

    //start exercise
    /**
     * 1.Delete the first node of the calling object.
     */
    void deleteFirstNode();

    /**
     * 2.Delete the second node of the calling object.
     */
    void deleteSecondNode();

    /**
     * 3.Delete the last node of the calling object.
     */
    void deleteLastNode();

    /**
     * 4.Delete the middle node (assume the list has an odd number of nodes).
     */
    void deleteMiddleNode();

    /**
     * 6.Swap the Value of the First Node with the Value of the Last Node
     */
    void swapFirstLast();

    /**
     * 7. Swap the Value of the First Node with the Value of the Second Node
     */
    void swapFirstSecond();

    /**
     * 8. Swap the Value of the First Node with the Value of the Node Before Last
     */
    void swapFirstBeforeLast();

    /**
     * 32. Search for a Value in the List
     */
    bool search(int value) const;

    /**
     * 19. Move the First Node to Last Position
     */
    void moveFirstToLast();

    /**
     * 45. Given Two int Parameters, value1 and value2, Insert a New Node Storing value1 Before the Node That Stores value2
     */
    void insertBefore(int value1, int value2);

    /**
     * 57. Swap the First Node of the Calling Object with the First Node of the Parameter Object
     */
    void swapFirstNode(AnyList& otherList);

    /**
     * 63. Compare the Elements of the Calling Object and the Parameter Object and Return true if They Are the Same
     */
    bool isEqual(const AnyList &otherList) const;

    /**
     * 21. Rotate Nodes (Repositioning Pointers, Not Swapping Values)
     */
    void rotateNodes();

    void print() const;

    void clearList();
    ~AnyList();

private:
    Node *first;
    // Pointer to point to the first node in the list.
    int count;
    // Variable to keep track of number of nodes in the list.
};



#endif //UNTITLED_ANYLIST_H
