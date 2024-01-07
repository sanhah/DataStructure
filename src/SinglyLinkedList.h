#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

#include <stdint.h>

template <typename T>
struct SingleNode {
    T data;
    SingleNode<T>* next;
};

template <typename T>
class SinglyLinkedList {
    public:
        SinglyLinkedList(T initElement);
        ~SinglyLinkedList(void);

        void append(T additionElement);
        bool insert(T insertionElement, int32_t idx);
        bool remove(int32_t idx);
        bool find(SingleNode<T>* item, int32_t idx);
        void printList(void);

    private:
        SingleNode<T>* head;
        SingleNode<T>* tail;
};

#endif // __SINGLY_LINKED_LIST_H__