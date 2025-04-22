#pragma once

#include <iostream>
#include "Node.hpp"

/**
 * @brief A simple implementation of a doubly linked list.
 *
 * Supports basic operations like construction, destruction, appending elements,
 * and utility functions for printing and debugging the list.
 *
 * @tparam T The type of data stored in each node.
 */
template<typename T>
class DoublyLinkedList {
private:
    Node<T> *head; ///< Pointer to the first node in the list.
    Node<T> *tail; ///< Pointer to the last node in the list.
    int length; ///< Number of elements in the list.

public:
    /**
     * @brief Constructs a new DoublyLinkedList with an initial node.
     *
     * Initializes the list with one node containing the provided data.
     * Sets both head and tail to point to this node.
     *
     * @param nodeData The value to initialize the list with.
     */
    explicit DoublyLinkedList(const T &nodeData) {
        std::cout << "Doubly Linked List constructor" << std::endl;

        auto newNode = new Node<T>(nodeData);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    /**
     * @brief Destructor that frees all allocated memory in the list.
     *
     * Iterates from head to tail, deleting each node.
     * Prevents memory leaks on destruction.
     */
    ~DoublyLinkedList() {
        std::cout << "Doubly Linked List destructor" << std::endl;

        auto *node = head;
        while (head) {
            head = head->next;
            delete node;
            node = head;
        }
    }

    /**
     * @brief Appends a new node with the given data to the end of the list.
     *
     * If the list is empty, the new node becomes both head and tail.
     * Otherwise, the current tail links to the new node, and tail is updated.
     *
     * @param nodeData The value to store in the new node.
     */
    void append(const T &nodeData) {
        auto *newNode = new Node<T>(nodeData);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        length++;
    }

    void deleteLast() {
        if (length == 0) {
            return;
        }

        auto *node = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete node;
        length--;
    }


    void prepend(const T &nodeData) {
        auto *newNode = new Node<T>(nodeData);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        length++;
    }

    void deleteFirst() {
        if (length == 0) {
            return;
        }

        auto *toDelete = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete toDelete;
        length--;
    }

    Node<T> *getNodeAt(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        auto *temp = head;
        if (index < length / 2) {
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; --i) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool setAtIndex(int index, T nodeData) {
        auto *temp = getNodeAt(index);
        if (temp) {
            temp->data = nodeData;
            return true;
        }

        return false;
    }

    bool insertAt(int index, T nodeData) {
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            append(nodeData);
            return true;
        }
        if (index == length) {
            prepend(nodeData);
            return true;
        }

        auto *newNode = new Node<T>(nodeData);
        auto *beforeNode = getNodeAt(index - 1);
        auto *afterNode = beforeNode->next;

        newNode->prev = beforeNode;
        newNode->next = afterNode;
        beforeNode->next = newNode;
        afterNode->prev = newNode;
        length++;

        return true;
    }

    bool deleteAt(int index) {
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            deleteFirst();
            return true;
        }
        if (index == length) {
            deleteLast();
            return true;
        }

        auto *toDelete = getNodeAt(index);
        auto *beforeNode = toDelete->prev;
        auto *afterNode = toDelete->next;

        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;

        delete toDelete;
        length--;

        return true;
    }

    /**
     * @brief Prints all elements in the list to the standard output.
     *
     * Iterates from head to tail, printing each node's data.
     */
    void traverse() const {
        auto *node = head;
        std::cout << "List: ";
        while (node) {
            std::cout << node->data << " <-> ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prints the data stored in the head node.
     */
    void printHead() const {
        if (head) {
            std::cout << "Head: " << head->data << std::endl;
        }
    }

    /**
     * @brief Prints the data stored in the tail node.
     */
    void printTail() const {
        if (tail) {
            std::cout << "Tail: " << tail->data << std::endl;
        }
    }

    /**
     * @brief Prints the number of elements currently in the list.
     */
    void printLength() const {
        std::cout << "Length: " << length << std::endl;
    }

    /**
     * @brief Prints the internal state of the linked list for debugging purposes.
     *
     * Outputs the head and tail values, current length of the list,
     * and all elements in order. Useful for quickly verifying list
     * structure after operations like insertions or deletions.
     */
    void debug() const {
        printHead();
        printTail();
        printLength();
        traverse();
        std::cout << std::endl << "------------------\n";
    }
};
