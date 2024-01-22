#ifndef __COMMON_H__
#define __COMMON_H__

template <typename T>
struct SingleNode {
    T data;
    SingleNode<T>* next;
};

#endif // __COMMON_H__