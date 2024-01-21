#include <iostream>
#include <src/Stack.h>

using namespace std;

Stack::Stack(int32_t initSize) {
    data = nullptr;
    stackSize = initSize;
    data = new int32_t(stackSize);

    if (data == nullptr) {
        cout << "Failed to mallocate memory" << "\n";
    } else {
        cout << "Success!" << "\n";
        topIndex = -1;
    }
}

Stack::~Stack(void) {
    stackSize = 0;
    topIndex = -1;
    delete data;
}

bool Stack::isEmpty(void) {
    bool ret = false;

    if (topIndex == -1) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

bool Stack::isFull(void) {
    bool ret = false;

    if (topIndex == (stackSize - 1)) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

void Stack::push(int32_t element) {
    if (isFull()) {
        cout << "Failed to push element! stack overflow" << "\n";
    } else {
        topIndex++;
        data[topIndex] = element;
    }
}

void Stack::pop(void) {
    if (isEmpty()) {
        cout << "Failed to pop element! stack underflow" << "\n";
    } else {
        topIndex--;

    }
}

int32_t Stack::peak(void) {
    int32_t ret = -1;
    if (isEmpty()) {
        cout << "stack is empty! Failed to return peak" << "\n";
    } else {
        ret = data[topIndex];
    }

    return ret;
}