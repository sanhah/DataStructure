#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>
#include <iostream>

template <typename T>
class Stack {
    public:
        Stack(int32_t initSize) {
            data = nullptr;
            stackSize = initSize;
            data = new T[stackSize];

            if (data == nullptr) {
                std::cout << "Failed to mallocate memory" << "\n";
            } else {
                std::cout << "Success!" << "\n";
                topIndex = -1;
            }
        }

        ~Stack(void) {
            stackSize = 0;
            topIndex = -1;
            delete data;
        }

        bool isEmpty(void) {
            bool ret = false;

            if (topIndex == -1) {
                ret = true;
            } else {
                ret = false;
            }

            return ret;
        }

        bool isFull(void) {
            bool ret = false;

            if (topIndex == (stackSize - 1)) {
                ret = true;
            } else {
                ret = false;
            }

            return ret;
        }

        void push(T element) {
            if (isFull()) {
                std::cout << "Failed to push element! stack overflow" << "\n";
            } else {
                topIndex++;
                data[topIndex] = element;
            }
        }

        void pop(void) {
            if (isEmpty()) {
                std::cout << "Failed to pop element! stack underflow" << "\n";
            } else {
                topIndex--;
            }
        }

        T peak(void) {
            T ret = -1;
            if (isEmpty()) {
                std::cout << "stack is empty! Failed to return peak" << "\n";
            } else {
                ret = data[topIndex];
            }

            return ret;
        }

        void printStack(void) {
            if (isEmpty()) {
                std::cout << "stack is empty" << std::endl;
            } else {
                for (int32_t idx = 0; idx <= topIndex; idx++) {
                    std::cout << "idx: " << idx << "  topIndex: " << topIndex << "  data: " << *(data + idx) << " address: " << data + idx << "\n";
                }
            }
            std::cout << " peak! : " << peak() << std::endl;
            std::cout << "==========================\n";
        }

    private:
        T* data;
        int32_t topIndex;
        int32_t stackSize;
};

#endif // __STACK_H__