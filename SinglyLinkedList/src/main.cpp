#include "SinglyLinkedList.hpp"
#include <iostream>

using namespace std;


int main(void) {
    SinglyLinkedList<double> list(0.1);
    list.printList();
    list.append(0.2);
    list.printList();
    list.append(0.3);
    list.printList();
    list.append(0.4);
    list.printList();
    std::cout << "\n======append DONE======\n\n" << std::endl;

    list.insert(-1.0, -1);
    list.printList();
    list.insert(0.0, 0);
    list.printList();
    list.insert(1.1, 1);
    list.printList();
    list.insert(2.2, 2);
    list.printList();
    list.insert(8.8, 8);
    list.printList();
    list.insert(7.7, 7);
    list.printList();
    list.insert(6.6, 6);
    list.printList();
    std::cout << "\n======insert DONE======\n\n" << std::endl;

    list.remove(-1);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(5);
    list.printList();
    list.remove(6);
    list.printList();
    list.remove(100);
    list.printList();
    list.remove(5);
    list.printList();
    std::cout << "\n======remove DONE======\n\n" << std::endl;

    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    list.remove(0);
    list.printList();
    std::cout << "\n======DONE======\n\n" << std::endl;

    return -1;
}