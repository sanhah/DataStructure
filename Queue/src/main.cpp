#include "Queue.hpp"
#include <iostream>

using namespace std;


int main(void) {
    Queue<double> queue(5);
    queue.printQueue();
    queue.enqueue(1.0);
    queue.printQueue();
    queue.enqueue(2.0);
    queue.printQueue();
    queue.enqueue(3.0);
    queue.printQueue();
    queue.enqueue(4.0);
    queue.printQueue();
    queue.enqueue(5.0);
    queue.printQueue();
    queue.enqueue(6.0);
    queue.printQueue();
    queue.enqueue(7.0);
    queue.printQueue();

    std::cout << "\n======enqueue DONE======\n\n" << std::endl;

    double front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    std::cout << "\n======dequeue DONE======\n\n" << std::endl;

    queue.enqueue(10.0);
    queue.printQueue();
    queue.enqueue(20.0);
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    queue.enqueue(30.0);
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    front = queue.front();
    queue.dequeue();
    std::cout << "front value: " << front << std::endl;
    queue.printQueue();

    queue.enqueue(40.0);
    queue.printQueue();
    std::cout << "\n======integration DONE======\n\n" << std::endl;

    std::cout << "\n======DONE======\n\n" << std::endl;

    return -1;
}