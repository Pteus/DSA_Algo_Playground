#include <iostream>

#include "Stack.hpp"

int main() {
    auto stck = std::make_unique<Stack<int> >(0);
    stck->debug();

    std::cout << "pushing '1'" << std::endl;
    stck->push(1);
    stck->debug();

    std::cout << "pop" << std::endl;
    auto result = stck->pop();
    if (result.has_value()) {
        std::cout << "Popped: " << result.value() << '\n';
    } else {
        std::cout << "Stack was empty.\n";
    }
    stck->debug();

    std::cout << "pop" << std::endl;
    result = stck->pop();
    if (result.has_value()) {
        std::cout << "Popped: " << result.value() << '\n';
    } else {
        std::cout << "Stack was empty.\n";
    }
    stck->debug();

    std::cout << "pop" << std::endl;
    result = stck->pop();
    if (result.has_value()) {
        std::cout << "Popped: " << result.value() << '\n';
    } else {
        std::cout << "Stack was empty.\n";
    }
    stck->debug();
}
