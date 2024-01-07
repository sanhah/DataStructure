#include <src/SinglyLinkedList.h>
#include <iostream>

using namespace std;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T initData) {
    // init linked list
    head = nullptr;
    tail = nullptr;

    // add init node
    SingleNode<T>* initNode = new SingleNode<T>;
    initNode->data = initData;
    head = initNode;
    tail = initNode;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList(void) {
    head = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::append(T additionElement) {
    // create node
    SingleNode<T>* additionNode = new SingleNode<T>;
    additionNode->data = additionElement;
    additionNode->next = nullptr;

    // add linked list
    tail->next = additionNode;

    // update tail
    tail = additionNode;
}

template <typename T>
bool SinglyLinkedList<T>::insert(T insertionElement, int32_t idx) {
    bool ret = true;

    // create node
    SingleNode<T>* insertionNode = new SingleNode<T>;
    insertionNode->data = insertionElement;
    insertionNode->next = nullptr;

    // add linked list
    SingleNode<T>* previousNode = nullptr;
    SingleNode<T>* tmpNextNode = nullptr;
    if (idx == 0) {
        tmpNextNode = head->next;
        insertionNode->next = tmpNextNode;
        head = insertionNode;
    } else if (find(previousNode, idx - 1) == false) {
        ret = false;
    } else if (previousNode == tail) {
        previousNode->next = insertionNode;
        tail = insertionNode;
    } else if (previousNode != tail) {
        tmpNextNode = previousNode->next;
        previousNode->next = insertionNode;
        insertionNode->next = tmpNextNode;
    } else {
        // nothing
    }

    return ret;
}

template <typename T>
bool SinglyLinkedList<T>::remove(int32_t idx) {
    bool ret = true;

    // remove linked list
    SingleNode<T>* previousNode = nullptr;
    SingleNode<T>* tmpRemoveNode = nullptr;
    if (idx == 0) {
        tmpRemoveNode = head;
        head = tmpRemoveNode->next;
        ret = true;
    } else if (find(previousNode, idx - 1) == false) {
        ret = false;
    } else if (tmpRemoveNode == tail) {
        tmpRemoveNode = previousNode->next;
        previousNode->next = nullptr;
        tail = previousNode;
    } else if (tmpRemoveNode != tail) {
        tmpRemoveNode = previousNode->next;
        previousNode->next = tmpRemoveNode->next;
    }

    // free memory
    if (tmpRemoveNode != nullptr ) {
        tmpRemoveNode->data = 0;
        tmpRemoveNode->next = nullptr;
        delete tmpRemoveNode;
    }

    previousNode = nullptr;

    return ret;
}

template <typename T>
bool SinglyLinkedList<T>::find(SingleNode<T>* item, int32_t idx) {
    bool ret = true;
    int32_t count = -1;
    SingleNode<T>* findNode = head;

    while (findNode != nullptr) {
        count++;
        if (count == idx) {
            break;
        }

        SingleNode<T>* tmp = findNode->next;
        findNode = tmp;
    }

    if (count < idx) {
        cout << "exceed index, out of range" << "\n";
        ret = false;
    }

    item = findNode;

    return ret;
}

template <typename T>
 void SinglyLinkedList<T>::printList(void) {
    SinglyLinkedList<T>* tmp = head;
    int32_t count = 0;
    while (tmp != nullptr) {
        cout << "idx: " << count << "  data: " << tmp->data << " address: " << tmp << "\n";
        tmp = tmp->next;
        count++;
    }
 }