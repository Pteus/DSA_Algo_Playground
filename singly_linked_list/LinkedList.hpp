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

    /**
     * @brief Inserts a new node at the beginning of the list.
     *
     * Creates a new node containing the given data and places it at the head.
     * Updates the head pointer, and if the list was empty, also sets the tail.
     *
     * @param data The data to store in the new head node.
     */
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

    /**
     * @brief Deletes the first node in the list.
     *
     * Safely removes the head node, updates the head pointer to the next node,
     * and deallocates memory. If the list becomes empty, both head and tail are set to nullptr.
     */
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

    /**
     * @brief Retrieves the node at a specified index.
     *
     * Iterates from the head to return a pointer to the node at the given index.
     * Returns nullptr if the index is out of bounds.
     *
     * @param index The position of the node to retrieve (0-based).
     * @return Pointer to the node at the index, or nullptr if invalid.
     */
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

    /**
     * @brief Sets the data of the node at the specified index.
     *
     * Modifies the value stored in a node if the index is valid.
     *
     * @param index The index of the node to modify.
     * @param nodeData The new data to assign to the node.
     * @return true if the operation succeeded, false if the index was invalid.
     */
    bool setNodeAt(int index, T nodeData) {
        auto *node = getNodeAt(index);
        if (node) {
            node->data = nodeData;
            return true;
        }
        return false;
    }

    /**
     * @brief Inserts a new node at the specified index.
     *
     * Handles insertion at the beginning, end, or middle of the list.
     * Returns false if the index is invalid.
     *
     * @param index The position to insert the new node at (0-based).
     * @param nodeData The data to store in the new node.
     * @return true if insertion succeeded, false otherwise.
     */
    bool insert(int index, T nodeData) {
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            prepend(nodeData);
            return true;
        }
        if (index == length) {
            append(nodeData);
            return true;
        }

        auto *newNode = new Node<T>(nodeData);
        auto *temp = getNodeAt(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;

        length++;
        return true;
    }

    /**
     * @brief Deletes the node at the specified index.
     *
     * Removes the node from the list and deallocates its memory.
     * Safely handles edge cases for the first and last node.
     *
     * @param index The index of the node to delete.
     */
    void deleteNodeAt(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == length - 1) {
            deleteLast();
            return;
        }

        auto *prevNode = getNodeAt(index - 1);
        auto *toDelete = prevNode->next;
        prevNode->next = toDelete->next;
        delete toDelete;
        length--;
    }

    /**
     * @brief Reverses the order of the linked list in place.
     *
     * Iteratively reverses all node links so the head becomes the tail and vice versa.
     * Does not allocate any new nodes.
     */
    void reverse() {
        auto *temp = head;
        head = tail;
        tail = temp;

        Node<T> *before = nullptr;
        Node<T> *after = nullptr;
        for (int i = 0; i < length; ++i) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
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
            std::cout << node->data << " -> ";
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
