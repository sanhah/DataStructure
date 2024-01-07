#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>

class Stack {
    public:
        Stack(int32_t initSize);
        ~Stack(void);

        void push(int32_t element);
        void pop(void);
        int32_t peak(void);
        bool isEmpty(void);
        bool isFull(void);

    private:
        int32_t* data;
        int32_t topIndex;
        int32_t stackSize;
};

#endif // __STACK_H__