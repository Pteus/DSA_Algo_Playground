#include <iostream>

#include "DoublyLinkedList.hpp"

int main() {
    const auto list = std::make_unique<DoublyLinkedList<int> >(1);
    list->debug();

    std::cout << "appending '2'" << std::endl;
    list->append(2);
    list->debug();

    std::cout << "appending '3'" << std::endl;
    list->append(3);
    list->debug();

    std::cout << "appending '4'" << std::endl;
    list->append(4);
    list->debug();

    std::cout << "deleting last" << std::endl;
    list->deleteLast();
    list->debug();

    std::cout << "deleting last" << std::endl;
    list->deleteLast();
    list->debug();

    std::cout << "prepending '0'" << std::endl;
    list->prepend(0);
    list->debug();

    std::cout << "deleting first" << std::endl;
    list->deleteFirst();
    list->debug();

    std::cout << "prepending '0'" << std::endl;
    list->prepend(0);
    list->debug();


    std::cout << "getting node at index '1'" << std::endl;
    if (const auto node = list->getNodeAt(1)) {
        std::cout << node->data << std::endl;
    } else {
        std::cout << "Node at index 1 does not exist." << std::endl;
    }

    std::cout << "setting node at index 1 with '100'" << std::endl;
    list->setAtIndex(1, 100);
    list->debug();

    list->insertAt(1, 1);
    list->debug();

    list->deleteAt(2);
    list->debug();
}
