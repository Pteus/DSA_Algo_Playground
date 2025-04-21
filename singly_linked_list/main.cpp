#include "LinkedList.hpp"
#include <memory>  // include this!

int main() {
        const auto my_linked_list = std::make_unique<LinkedList<int> >(5);

        my_linked_list->debug();

        std::cout << "\nappending to '50' list\n" << std::endl;

        my_linked_list->append(50);
        my_linked_list->debug();

        std::cout << "\nappending to '100' list\n" << std::endl;

        my_linked_list->append(100);
        my_linked_list->debug();
        /*std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->debug();

        std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->debug();

        std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->debug();

        std::cout << "\nprepending \n" << std::endl;

        my_linked_list->prepend(2);
        my_linked_list->debug();

        std::cout << "\nprepending \n" << std::endl;

        my_linked_list->prepend(20);
        my_linked_list->debug();

        std::cout << "\ndeleting first \n" << std::endl;

        my_linked_list->deleteFirst();
        my_linked_list->debug();

        std::cout << "\ndeleting first \n" << std::endl;

        my_linked_list->deleteFirst();
        my_linked_list->debug();

        std::cout << "\nappending to '100' list\n" << std::endl;

        my_linked_list->append(100);
        my_linked_list->debug();

        std::cout << "\nappending to '200' list\n" << std::endl;

        my_linked_list->append(200);
        my_linked_list->debug();

        std::cout << "\ngetting at index '1'" << std::endl;
        std::cout << my_linked_list->getNodeAt(1)->data << std::endl;

        std::cout << "\nsetting '1000' at index '1'" << std::endl;
        my_linked_list->setNodeAt(1, 1000);
        my_linked_list->debug();*/

        std::cout << "\ninserting '99' at index 0" << std::endl;
        my_linked_list->insert(0, 99);
        my_linked_list->debug();

        std::cout << "\ndeleting at index 1" << std::endl;
        my_linked_list->deleteNodeAt(1);
        my_linked_list->debug();

        std::cout << "\ndeleting at index 0" << std::endl;
        my_linked_list->deleteNodeAt(0);
        my_linked_list->debug();

        std::cout << std::endl << "reverse list" << std::endl;
        my_linked_list->reverse();
        my_linked_list->debug();
}

