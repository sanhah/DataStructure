#include "Stack.hpp"

using namespace std;


int main(void) {
    Stack<double> stack(5);
    stack.printStack();
    stack.push(0.0);
    stack.printStack();
    stack.push(1.1);
    stack.printStack();
    stack.push(2.2);
    stack.printStack();
    stack.pop();
    stack.printStack();
    stack.push(3.3);
    stack.printStack();
    stack.push(4.4);
    stack.printStack();
    stack.push(5.5);
    stack.printStack();
    stack.push(6.6);
    stack.printStack();

    stack.isFull();
    stack.isEmpty();
    std::cout << "\n======push DONE======\n\n" << std::endl;
    double peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();
    peak = stack.peak();
    stack.pop();
    std::cout << "popping peak: " << peak << std::endl;
    stack.printStack();

    stack.isFull();
    stack.isEmpty();
    std::cout << "\n======pop DONE======\n\n" << std::endl;

    return -1;
}