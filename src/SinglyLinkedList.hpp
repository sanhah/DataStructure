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

            // create node
            SingleNode<T>* insertionNode = new SingleNode<T>;
            insertionNode->data = insertionElement;
            insertionNode->next = nullptr;

            // add linked list
            SingleNode<T>* previousNode = nullptr;
            if (ret && (idx < 0)) {
                ret = false;
                std::cout << "exceed index, out of range" << std::endl;
            }

            if (ret && (idx == 0)) {
                insertionNode->next = head->next;
                head = insertionNode;
            }

            if (ret && (idx > 0)) {
                previousNode = find(idx - 1);

                if (ret && (previousNode == nullptr)) {
                    ret = false;
                    std::cout << "fail to find node" << std::endl;
                }
                if (ret && (previousNode == tail)) {
                    previousNode->next = insertionNode;
                    tail = insertionNode;
                } else if (ret && (previousNode != tail)) {
                    insertionNode->next = previousNode->next;
                    previousNode->next = insertionNode;
                } else {
                    // nothing
                }

            }

            if (idx == 0) {

            } else if (idx > 0) {
                previousNode = find(idx - 1);
                if (previousNode == nullptr) {
                    ret = false;
                    std::cout << "fail to find node" << std::endl;
                }
            } else {

            }

            if (ret && (previousNode == tail)) {
                previousNode->next = insertionNode;
                tail = insertionNode;
            } else if (ret && (previousNode != tail)) {
                insertionNode->next = previousNode->next;
                previousNode->next = insertionNode;
            } else {
                // nothing
            }

            return ret;
        }

        bool remove(int32_t idx) {
            bool ret = true;

            // remove linked list
            SingleNode<T>* previousNode = nullptr;
            SingleNode<T>* tmpRemoveNode = nullptr;
            if (idx == 0) {
                tmpRemoveNode = head;
                head = tmpRemoveNode->next;
            } else if (idx > 0) {
                previousNode = find(idx - 1);
                if (previousNode == nullptr) {
                    ret = false;
                    std::cout << "fail to find node" << std::endl;
                }
            } else {
                ret = false;
                std::cout << "exceed index, out of range" << " " << __FUNCTION__ << std::endl;
            }

            if (ret &&(tmpRemoveNode == tail)) {
                tmpRemoveNode = previousNode->next;
                previousNode->next = nullptr;
                tail = previousNode;
            } else if (ret && (tmpRemoveNode != tail)) {
                tmpRemoveNode = previousNode->next;
                previousNode->next = tmpRemoveNode->next;
            } else {
                // nothing
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
            }
            std::cout << "tail: " << tail << std::endl;
            std::cout << "=============================" << std::endl;
        }

    private:
        SingleNode<T>* head;
        SingleNode<T>* tail;
};

#endif // __SINGLY_LINKED_LIST_H__