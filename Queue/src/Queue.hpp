#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>
#include <iostream>
#include "../../common/common.h"

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

            if (isEmpty()) {
                rearPtr = nullptr;
            }

            return ret;
        }

        T front(void) {
            T ret;
            if (isEmpty()) {
                std::cout << "fail to pop data, queue is empty" << std::endl;
            } else {
                ret = frontPtr->data;
            }
            return ret;
        }

        void printQueue(void) {
            SingleNode<T>* tmp = frontPtr;
            std::cout << "frontPtr: " << frontPtr << std::endl;
            int32_t count = 0;
            while (tmp != nullptr) {
                std::cout << "idx: " << count << "  data: " << tmp->data << " address: " << tmp << "\n";
                tmp = tmp->next;
                count++;
            }
            std::cout << "rear: " << rearPtr << std::endl;
            std::cout << "=============================\n" << std::endl;
        }

    private:
        SingleNode<T>* frontPtr;
        SingleNode<T>* rearPtr;
        int32_t queueMaxSize;
        int32_t queueSize;
};

#endif // __QUEUE_H__