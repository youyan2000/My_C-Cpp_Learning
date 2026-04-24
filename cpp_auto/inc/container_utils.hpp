#ifndef CONTAINER_UTILS_HPP
#define CONTAINER_UTILS_HPP

#include <vector>

template<typename Container>
decltype(auto) getFirstElement(Container&& c) {
    return std::forward<Container>(c)[0];
}

void demonstrateAutoInContainers();

#endif