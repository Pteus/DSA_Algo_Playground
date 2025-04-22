#pragma once

/**
 * @brief A single node in a singly linked list.
 *
 * Represents a node that holds data and a pointer to the next node.
 * This is a simple, lightweight struct with public members—ideal for
 * basic data structure implementations.
 *
 * @tparam T Type of data the node will store.
 */
template<typename T>
struct Node {
    T data; ///< The value stored in the node.
    Node<T> *next; ///< Pointer to the next node in the list.

    /**
     * @brief Constructs a node with the given data.
     * @param data The value to store in the node.
     */
    explicit Node(const T &data) : data(data), next(nullptr) {
    }
};
