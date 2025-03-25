
#include "DoublyList.h"

using namespace std;

void DoublyList::insertFront(int newData)
{
    if (first == nullptr)
    {
        first = new DLLNode(newData, nullptr, nullptr);
        last = first;
        // Common error: Forgetting to reset pointer last.
    }
    else
    {
        first = new DLLNode(newData, nullptr, first);
        first->getNext()->setPrev(first);
        // Common error: Forgetting to connect pointer 
        // prev of what is now the second node to the 
        // new first node.
    }

    ++count;
}

void DoublyList::printForward() const
{
    DLLNode* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
}

void DoublyList::printReverse() const {
    DLLNode* current = last;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
    cout << endl;
}

void DoublyList::clearList()
{
    DLLNode* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;
    // Don't forget to reset pointer last to nullptr.
    count = 0;
}

DoublyList::~DoublyList()
{
    if (first != nullptr)
        clearList();
}

void DoublyList::swapSecondWithLast(DoublyList &otherList) {
    if (count >= 2 && otherList.count >= 2) {
        DLLNode *secondNode = first->getNext();
        DLLNode *otherLastNode = otherList.last;

        otherLastNode->setNext(secondNode->getNext());
        secondNode->getNext()->setPrev(otherLastNode);
        otherLastNode->getPrev()->setNext(secondNode);

        secondNode->setPrev(otherLastNode->getPrev());
        secondNode->setNext(nullptr);
        otherList.last = secondNode;

        otherLastNode->setPrev(first);
        first->setNext(otherLastNode);
    }
}

int DoublyList::getCount() const {
    return count;
}

void DoublyList::deleteFirstNode() {
    if (count > 0) {
        DLLNode* temp = first;

        if (first == last) {
            // Only one node
            first = nullptr;
            last = nullptr;
        } else {
            // More than one node
            first = first->getNext();
            first->setPrev(nullptr);
        }

        delete temp;
        temp = nullptr;
        count--;
    }
}

void DoublyList::deleteSecondNode() {
    if (count >= 2) {
        DLLNode *temp = first->getNext();

        if (count == 2) {
            last = first;
            first->setNext(nullptr);
        } else {
            first->setNext(temp->getNext());
            first->getNext()->setPrev(first);
        }

        delete temp;
        temp = nullptr;
        count--;
    }
}

void DoublyList::deleteLastNode() {
    if (count >= 1) {
       DLLNode *temp = last;

       if (count == 1) {
           first = nullptr;
           last = nullptr;
       } else {
           temp->getPrev()->setNext(nullptr);
           last = temp->getPrev();
       }

       delete temp;
       temp = nullptr;
       count--;
    }
}

void DoublyList::deleteBeforeLastNode() {
    if (count > 2) {
        DLLNode *temp = last->getPrev();

        temp->getPrev()->setNext(last);
        last->setPrev(temp->getPrev());

        delete temp;
        temp = nullptr;
        count--;
    }
}

void DoublyList::deleteMiddleNode() {
    if (count > 2) {
        DLLNode *current = first;
        int middleIndex = count / 2;

        for (int i = 0; i < middleIndex; i++) {
            current = current->getNext();
        }

        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
        delete current;
        current = nullptr;
        count--;
    }
}

void DoublyList::swapFirstLast() {
    if (count > 1) {
        int temp = first->getData();
        first->setData(last->getData());
        last->setData(temp);
    }
}

void DoublyList::swapFirstSecond() {
    if (count > 1) {
        int temp = first->getData();
        first->setData(first->getNext()->getData());
        first->getNext()->setData(temp);
    }
}

void DoublyList::swapFirstBeforeLast() {
    if (count > 2) {
        int temp = first->getData();

        first->setData(last->getPrev()->getData());
        last->getPrev()->setData(temp);
    }
}

void DoublyList::moveFirstBeforeLast() {
    if (count > 2) {
        DLLNode *temp = first;

        first = first->getNext();
        first->setPrev(nullptr);

        last->getPrev()->setNext(temp);
        temp->setPrev(last->getPrev());
        temp->setNext(last);
        last->setPrev(temp);
    }
}

void DoublyList::rotateNodes(int k) {
    if (count > 2 && k <= count) {
        DLLNode *newFirst = first;
        for (int i = 0; i < k; i++) {
            newFirst = newFirst->getNext();
        }

        DLLNode* oldLast = last;
        DLLNode* newLast = newFirst->getPrev();

        newLast->setNext(nullptr);
        newFirst->setPrev(nullptr);

        oldLast->setNext(first);
        first->setPrev(oldLast);

        first = newFirst;
        last = newLast;
    }
}

void DoublyList::insertBack(int i) {
    DLLNode* newNode = new DLLNode(i, nullptr, nullptr);

    if (first == nullptr) {
        first = newNode;
        last = newNode;
    } else {
        newNode->setPrev(last);
        last->setNext(newNode);
        last = newNode;
    }

    count++;
}

void DoublyList::copyTo(DoublyList &otherList) const {
    if (count > 0) {
        DLLNode *temp = first;
        for (int i = 0; i < count; i++) {

            if (otherList.first == nullptr) {
                otherList.first = new DLLNode(temp->getData(), nullptr, nullptr);
                otherList.last = otherList.first;
            } else {
                otherList.first = new DLLNode(temp->getData(), nullptr, otherList.first);
                otherList.first->getNext()->setPrev(otherList.first);
            }

            temp = temp->getNext();
        }
        otherList.count = count;
    }
}

void DoublyList::copyToPosition(DoublyList &otherList, int position) const {
    if (position > 0 && position < otherList.count && count > 0) {
        DLLNode *startPosition = otherList.first;
        for (int i = 1; i < position; i++) {
            startPosition = startPosition->getNext();
        }

        DLLNode *current = first;
        for (int i = 0; i < count; i++) {
            DLLNode *newNode = new DLLNode(current->getData(), startPosition, startPosition->getNext());

            startPosition->getNext()->setPrev(newNode);
            startPosition->setNext(newNode);

            startPosition = startPosition->getNext();
            current = current->getNext();
        }

        otherList.count += count;
    }
}

void DoublyList::swapWith(DoublyList &otherList) {
    if (count > 0 && otherList.count > 0) {
        DLLNode *temp = first;

        first = otherList.first;
        otherList.first = temp;

        temp = last;
        last = otherList.last;
        otherList.last = temp;

        int tempCount = count;
        count = otherList.count;
        otherList.count = tempCount;
    }
}

bool DoublyList::isEqual(const DoublyList &otherList) const {
    if (count != otherList.count) {
        return false;
    }

    DLLNode *current = first;
    DLLNode *otherCurrent = otherList.first;

    for (int i = 0; i < count; i++) {

        if (current->getData() != otherCurrent->getData()) {
            return false;
        }

        current = current->getNext();
        otherCurrent = otherCurrent->getNext();
    }

    return true;
}
