#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../../SinglyLinkedList/src/SinglyLinkedList.hpp"

template <typename T>
class Queue {
    public:
        Queue(int32_t maxSize) {
            frontPtr = nullptr;
            rearPtr = nullptr;
            queueMaxSize = maxSize;
            queueSize = 0;
        }

        ~Queue(void) {
            frontPtr = nullptr;
            rearPtr = nullptr;        
        }

        bool isEmpty(void) {
            return (queueSize == 0);
        }

        bool isFull(void) {
            return (queueSize == queueMaxSize);
        }

        bool enqueue(T element) {
            bool ret = true;

            if (isFull()) {
                ret = false;
                std::cout << "fail to enqueue data, queue is full" << std::endl;
            }

            if (ret) {
                // create node
                SingleNode<T>* additionNode = new SingleNode<T>;
                additionNode->data = element;
                additionNode->next = nullptr;

                if (isEmpty()) {
                    frontPtr = additionNode;
                } else {
                    rearPtr->next = additionNode;
                }

                rearPtr = additionNode;
                queueSize++;
            }

            return ret;
        }

        bool dequeue(void) {
            bool ret = true;

            if (isEmpty()) {
                ret = false;
                std::cout << "fail to dequeue data, queue is empty" << std::endl;
            }

            if (ret) {
                SingleNode<T>* tmpRemoveNode = frontPtr;
                frontPtr = tmpRemoveNode->next;
                queueSize--;

                delete tmpRemoveNode;
            }

            return ret;
        }

        T front(void) {
            return frontPtr->data;
        }

    private:
        SingleNode<T>* frontPtr;
        SingleNode<T>* rearPtr;
        int32_t queueMaxSize;
        int32_t queueSize;
};

#endif // __QUEUE_H__