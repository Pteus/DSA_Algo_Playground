#pragma once

/**
 * @brief A node in a doubly linked list.
 *
 * Represents a node that holds data along with pointers to both the next
 * and previous nodes.
 *
 * @tparam T Type of data the node will store.
 */
template<typename T>
struct Node {
    T data; ///< The value stored in the node.
    Node<T> *next; ///< Pointer to the next node in the list.
    Node<T> *prev; ///< Pointer to the previous node in the list.

    /**
     * @brief Constructs a node with the given data.
     *        Initializes both next and prev to nullptr.
     *
     * @param data The value to store in the node.
     */
    explicit Node(const T &data) : data(data), next(nullptr), prev(nullptr) {
    }
};
