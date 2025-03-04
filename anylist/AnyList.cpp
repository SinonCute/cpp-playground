//
// Created by caoth on 2/28/2025.
//

#include "AnyList.h"
#include "iostream"

using namespace std;

void AnyList::insertFront(int newData) {
    first = new Node(newData, first);
    ++count;
}

void AnyList::print() const {
    if (first == nullptr)
    // Check if the list is empty.
    // You can also use: if (count == 0)
        cerr << "List is empty.";
    // Use cerr, instead of cout. Why?
    else {
        Node *current = first;
        // Create a pointer to traverse the list.
        // This pointer will point to the first node in the list.

        while (current != nullptr)
        // While the current pointer is NOT a nullptr,
        // that is, while the current pointer has not reached
        // the end of the list.
        {
            // Output the data.
            cout << current->getData() << " ";
            // Move the pointer current forward.
            current = current->getNext();
        }
    }
}

// This function does not delete the
// list object; it ONLY deletes the nodes.
void AnyList::clearList() {
    Node *temp = first;
    // Pointer to delete the node, which
    // starts by pointing to the first node.

    while (first != nullptr) {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    // Update the count outside the loop.
    count = 0;
}

AnyList::~AnyList() {
    if (first != nullptr)
        clearList();
}

void AnyList::insertAtBeginning(int newValue) {
    if (first == nullptr) {
        first = new Node(newValue, nullptr);
    } else {
        first = new Node(newValue, first);
    }
    count++;
}

void AnyList::insertAtEnd(int newValue) {
    if (first == nullptr) {
        first = new Node(newValue, nullptr);
    } else {
        Node *current = first;
        for (int i = 0; i < count; i++) {
            if (current->getNext() == nullptr) {
                current->setNext(new Node(newValue, nullptr));
            } else {
                current = current->getNext();
            }
        }
    }
    count++;
}

void AnyList::deleteFirstNode() {
    if (first != nullptr) {
        Node *temp = first;
        first = first->getNext();
        delete temp;
        count--;
    }
}

void AnyList::deleteSecondNode() {
    if (first != nullptr && first->getNext() != nullptr) {
        Node *second = first->getNext();
        first->setNext(second->getNext());
        delete second;
        count--;
    }
}

void AnyList::deleteLastNode() {
    if (first != nullptr) {
        if (first->getNext() == nullptr) {
            delete first;
            first = nullptr;
        } else {
            Node *preLast = first;
            int loopSize = count - 2;

            for (int i = 0; i < loopSize; i++) {
                preLast = preLast->getNext();
            }

            delete preLast->getNext();
            preLast->setNext(nullptr);
        }

        count--;
    }
}

void AnyList::deleteMiddleNode() {
    if (first != nullptr && count >= 3) {
        Node *preMiddle = first;
        Node *middle = first->getNext();
        int middleIndex = (count / 2);
        for (int i = 1; i < middleIndex; i++) {
            preMiddle = middle;
            middle = middle->getNext();
        }
        preMiddle->setNext(middle->getNext());
        delete middle;
        count--;
    }
}

void AnyList::swapFirstLast() {
    if (count >= 2) {
        Node *current = first;
        int lastIndex = count - 1;

        for (int i = 0; i < lastIndex; i++) {
            current = current->getNext();
        }

        int tempValue = current->getData();
        current->setData(first->getData());
        first->setData(tempValue);
    }
}

void AnyList::swapFirstSecond() {
    if (count >= 2) {
        int tempValue = first->getNext()->getData();
        first->getNext()->setData(first->getData());
        first->setData(tempValue);
    }
}

void AnyList::swapFirstBeforeLast() {
    if (count >= 3) {
        Node *current = first;
        int preLastIndex = count - 2;

        for (int i = 0; i < preLastIndex; i++) {
            current = current->getNext();
        }

        int tempValue = current->getData();
        current->setData(first->getData());
        first->setData(tempValue);
    }
}

bool AnyList::search(int value) const {
    Node *current = first;

    while (current != nullptr) {
        if (current->getData() == value) {
            return true;
        } else {
            current = current->getNext();
        }
    }

    return false;
}

void AnyList::moveFirstToLast() {
    if (count >= 2) {
        Node *current = first;
        int lastIndex = count - 1;

        for (int i = 0; i < lastIndex; i++) {
            current = current->getNext();
        }

        Node *temp = first;
        first = first->getNext();
        temp->setNext(nullptr);
        current->setNext(temp);
    }
}

void AnyList::insertBefore(int value1, int value2) {
    Node *current = first;
    bool found = false;

    if (first->getData() == value2) {
        first = new Node(value1, first);
        count++;
    } else {
        while (!found && current->getNext() != nullptr) {
            if (current->getNext()->getData() == value2) {
                current->setNext(new Node(value1, current->getNext()));
                found = true;
                count++;
            } else {
                current = current->getNext();
            }
        }
    }
}

// void AnyList::swapFirstNode(AnyList &otherList) {
//     if (count != 0 && otherList.count != 0) {
//         Node *temp = first->getNext();
//
//         // Exchange next pointer
//         first->setNext(otherList.first->getNext());
//         otherList.first->setNext(temp);
//
//         // Exchange first pointer
//         temp = first;
//         first = otherList.first;
//         otherList.first = temp;
//     }
// }

void AnyList::swapFirstNode(AnyList &otherList) {
    if (count != 0 && otherList.count != 0) {
        Node *temp = otherList.first;

        otherList.first = first;
        first = temp;
    }
}

bool AnyList::isEqual(const AnyList &otherList) const {
    if (count != otherList.count) {
        return false;
    }

    Node *current = first;
    Node *currentOther = otherList.first;

    while (current != nullptr && currentOther != nullptr) {
        if (current->getData() != currentOther->getData()) {
            return false;
        }

        current = current->getNext();
        currentOther = currentOther->getNext();
    }

    return true;
}

void AnyList::rotateNodes() {
    Node *current = first;
    int lastIndex = count - 1;
    for (int i = 0; i < lastIndex; i++) {
        current = current->getNext();
    }

    Node *temp = first;
    first = first->getNext();
    temp->setNext(nullptr);
    current->setNext(temp);
}