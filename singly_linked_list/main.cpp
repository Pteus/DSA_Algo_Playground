#include "LinkedList.hpp"

int main() {
        auto *my_linked_list = new LinkedList<int>(5);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nappending to '50' list\n" << std::endl;

        my_linked_list->append(50);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nappending to '100' list\n" << std::endl;

        my_linked_list->append(100);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ndeleting last\n" << std::endl;

        my_linked_list->deleteLast();
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nprepending \n" << std::endl;

        my_linked_list->prepend(2);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nprepending \n" << std::endl;

        my_linked_list->prepend(20);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ndeleting first \n" << std::endl;

        my_linked_list->deleteFirst();
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ndeleting first \n" << std::endl;

        my_linked_list->deleteFirst();
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nappending to '100' list\n" << std::endl;

        my_linked_list->append(100);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\nappending to '200' list\n" << std::endl;

        my_linked_list->append(200);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        std::cout << "\ngetting at index '1'" << std::endl;
        std::cout << my_linked_list->getNodeAt(1)->data << std::endl;

        std::cout << "\nsetting '1000' at index '1'" << std::endl;
        my_linked_list->setNodeAt(1, 1000);
        my_linked_list->printHead();
        my_linked_list->printTail();
        my_linked_list->printLength();
        my_linked_list->printList();

        delete my_linked_list;
}
