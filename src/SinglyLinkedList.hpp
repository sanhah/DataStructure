#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

#include <stdint.h>
#include <iostream>

template <typename T>
struct SingleNode {
    T data;
    SingleNode<T>* next;
};

template <typename T>
class SinglyLinkedList {
    public:
        SinglyLinkedList(T initElement) {
            // init linked list
            head = nullptr;
            tail = nullptr;

            // add init node
            SingleNode<T>* initNode = new SingleNode<T>;
            initNode->data = initElement;
            head = initNode;
            tail = initNode;
        }

        ~SinglyLinkedList(void) {
            head = nullptr;
        }

        bool isEmpty(void) {
            return (head == nullptr);
        }

        void append(T additionElement) {
            // create node
            SingleNode<T>* additionNode = new SingleNode<T>;
            additionNode->data = additionElement;
            additionNode->next = nullptr;

            // add linked list
            tail->next = additionNode;

            // update tail
            tail = additionNode;
        }

        bool insert(T insertionElement, int32_t idx) {
            bool ret = true;
            bool passed = false;

            // invalid index error
            if (ret && (idx < 0)) {
                ret = false;
                std::cout << "Error: Index " << idx << " is out of range" << std::endl;
            }

            // create node
            SingleNode<T>* insertionNode = new SingleNode<T>;
            insertionNode->data = insertionElement;
            insertionNode->next = nullptr;

            // add linked list
            // step 1. empty list, add first node
            if (ret && isEmpty()) {
                std::cout << "list is empty, initialize list with this data" << std::endl; 
                head = insertionNode;
                tail = insertionNode;
                passed = true;
            }

            // step 2. insert data at the front of list
            if (ret && (passed == false) && (idx == 0)) {
                insertionNode->next = head;
                head = insertionNode;
                passed = true;
            }

            // step 2. find space to insert data
            SingleNode<T>* previousNode = nullptr;
            if (ret && (passed == false) && (idx > 0)) {
                previousNode = find(idx - 1);

                // step 2.1 invalid index error
                if (ret && (previousNode == nullptr)) {
                    ret = false;
                    passed == true;
                    std::cout << "Error: Index " << idx << " is out of range, fail to find node" << std::endl;
                }

                // step 2.2 insert data at the middle of list 
                if (ret && (passed == false) && (previousNode != tail)) {
                    insertionNode->next = previousNode->next;
                    previousNode->next = insertionNode;
                    passed = true;
                }

                // step 2.3 insert data at the tail of list 
                if (ret && (passed == false) && (previousNode == tail)) {
                    previousNode->next = insertionNode;
                    tail = insertionNode;
                    passed = true;
                }
            }

            return ret;
        }

        bool remove(int32_t idx) {
            bool ret = true;

            // remove linked list
            SingleNode<T>* previousNode = nullptr;
            SingleNode<T>* tmpRemoveNode = nullptr;

            if (head == nullptr) {
                std::cout << "empty list, need to remove linked list" << std::endl;
                ret = false;
            }

            if (ret && (idx < 0)) {
                ret = false;
                std::cout << "exceed index, out of range" << std::endl;
            }

            if (ret && (idx == 0)) {
                tmpRemoveNode = head;
                head = tmpRemoveNode->next;
                if (head == nullptr) {
                    tail = head;
                }
            }

            if (ret && (idx > 0)) {
                previousNode = find(idx - 1);

                if (ret && (previousNode == nullptr)) {
                    ret = false;
                    std::cout << "fail to find node" << std::endl;
                }
                if (ret && (previousNode == tail)) {
                    ret = false;
                    std::cout << idx << "th node does not exist" << std::endl;
                } else if (ret && (previousNode != tail)) {
                    tmpRemoveNode = previousNode->next;
                    previousNode->next = tmpRemoveNode->next;
                    if (previousNode->next == nullptr) {
                        tail = previousNode;
                    }
                } else {
                    // do nothing
                }
            }

            // free memory
            if (tmpRemoveNode != nullptr ) {
                tmpRemoveNode->data = 0;
                tmpRemoveNode->next = nullptr;
                delete tmpRemoveNode;
            }

            previousNode = nullptr;
            delete previousNode;

            return ret;
        }

        SingleNode<T>* find(int32_t idx) {
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
                std::cout << "exceed index, out of range" << " " << "\n";
                ret = false;
            }

            return findNode;
        }

        void printList(void) {
            SingleNode<T>* tmp = head;
            int32_t count = 0;
            std::cout << "head: " << head << std::endl;
            while (tmp != nullptr) {
                std::cout << "idx: " << count << "  data: " << tmp->data << " address: " << tmp << "\n";
                tmp = tmp->next;
                count++;

                if (count > 20) {
                    break;
                }
            }
            std::cout << "tail: " << tail << std::endl;
            std::cout << "=============================" << std::endl;
        }

    private:
        SingleNode<T>* head;
        SingleNode<T>* tail;
};

#endif // __SINGLY_LINKED_LIST_H__