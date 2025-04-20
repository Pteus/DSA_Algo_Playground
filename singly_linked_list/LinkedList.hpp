#pragma once
#include <iostream>

#include "Node.hpp"

/**
 * @brief A singly linked list implementation.
 *
 * This class provides basic operations to manipulate a singly linked list,
 * such as inserting, deleting, and traversing nodes.
 *
 * @tparam T Type of the data stored in the list.
 */
template<typename T>
class LinkedList {
    static_assert(std::is_default_constructible_v<T>, "T must be default constructible");
    static_assert(std::is_copy_constructible_v<T>, "T must be copy constructible");
    static_assert(
        std::is_same_v<decltype(std::declval<std::ostream &>() << std::declval<T>()), std::ostream &>,
        "T must be streamable (i.e., support operator<<)"
    );

private:
    Node<T> *head; ///< Pointer to the first node in the list
    Node<T> *tail; ///< Pointer to the last node in the list
    int length; ///< Number of elements in the list

public:
    /**
     * @brief Constructs a new LinkedList with an initial node.
     *
     * Initializes the list with a single node containing the given data.
     * Sets both the head and tail to point to this node.
     *
     * @param data The data to initialize the list with.
     */
    explicit LinkedList(const T &data) : head(nullptr), tail(nullptr), length(1) {
        std::cout << "LinkedList constructor" << std::endl;

        auto *node = new Node<T>(data);
        head = node;
        tail = node;
    }

    /**
     * @brief Destroys the LinkedList and frees all allocated memory.
     *
     * Iterates through the list and deletes each node to prevent memory leaks.
     */
    ~LinkedList() {
        std::cout << "LinkedList destructor" << std::endl;

        Node<T> *node = head;
        while (head) {
            head = head->next;
            delete node;
            node = head;
        }
    }

    /**
     * @brief Appends a new node with the given data to the end of the list.
     *
     * If the list is empty, the new node becomes both the head and tail.
     * Otherwise, it is added after the current tail and the tail pointer is updated.
     *
     * @param data The data to insert at the end of the list.
     */
    void append(const T &data) {
        auto *newNode = new Node<T>(data);

        // If the list is empty, set both head and tail to the new node.
        // Otherwise, link the new node to the end of the list and update the tail pointer.
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    /**
     * @brief Deletes the last node in the list.
     *
     * If the list is empty, the function does nothing.
     * If the list has only one node, it deletes it and resets head and tail to nullptr.
     * Otherwise, it removes the last node and updates the tail pointer accordingly.
     */
    void deleteLast() {
        if (length == 0) {
            return;
        }


        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }


        auto *node = head;
        while (node->next->next) {
            node = node->next;
        }

        delete tail;
        tail = node;
        tail->next = nullptr;
        length--;
    }

    void prepend(const T &data) {
        auto *newNode = new Node<T>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        length++;
    }

    void deleteFirst() {
        if (length == 0) {
            return;
        }

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }

        auto *node = head;
        head = head->next;
        delete node;
        length--;
    }

    Node<T> *getNodeAt(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        auto *node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }

    bool setNodeAt(int index, T nodeData) {
        auto *node = getNodeAt(index);
        if (node) {
            node->data = nodeData;
            return true;
        }
        return false;
    }

    /**
     * @brief Prints all elements in the list to the standard output.
     *
     * Iterates from head to tail, printing each node's data.
     */
    void printList() {
        auto *node = head;
        std::cout << "List: ";
        while (node) {
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prints the data stored in the head node.
     */
    void printHead() {
        if (head) {
            std::cout << "Head: " << head->data << std::endl;
        }
    }

    /**
     * @brief Prints the data stored in the tail node.
     */
    void printTail() {
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
};
