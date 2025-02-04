#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T>
void    swap(T &value1, T &value2) {
    T   tmp;

    tmp = value1;
    value1 = value2;
    value2 = tmp;
}

template <typename T>
const T&   min(const T &value1, const T &value2) {
    return (value1 < value2) ? value1 : value2;
}

template <typename T>
const T&   max(const T &value1, const T &value2) {
    return (value1 > value2) ? value1 : value2;
}

#endif /* TEMPLATE_HPP */
