#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>

class Queue {
    public:
        Queue(int32_t initSize);
        ~Queue(void);

        void enqueue(int32_t element);
        void dequeue(void);
        int32_t front(void);
        bool isEmpty(void);
        bool isFull(void);

    private:
        int32_t* data;
        int32_t rear;
        int32_t queueSize;
};

#endif // __QUEUE_H__