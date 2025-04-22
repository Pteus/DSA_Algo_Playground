#pragma once
#include "Node.hpp"

template<typename T>
class Stack {
private:
    Node<T> *top;
    int height;

public:
    explicit Stack(T nodeData) : height(1) {
        auto *node = new Node<T>(nodeData);
        top = node;
    }

    void printStack() {
        auto temp = top;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
    }

    void push(T nodeData) {
        auto *node = new Node<T>(nodeData);
        node->next = top;
        top = node;
        height++;
    }

    std::optional<T> pop() {
        if (height == 0) {
            return std::nullopt;
        }

        auto *node = top;
        T popped = top->data;
        top = top->next;
        height--;
        delete node;

        return popped;
    }

    void printTop() {
        if (top == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Top: " << top->data << std::endl;
    }

    void printHeight() {
        std::cout << "Height: " << height << std::endl;
    }

    void debug() {
        printTop();
        printHeight();
        printStack();
        std::cout << "\n------------------\n";
    }
};
