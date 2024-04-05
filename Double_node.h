//
// Created by user on 04.04.2024.
//

#ifndef LISTS_DOUBLE_NODE_H
#define LISTS_DOUBLE_NODE_H
#include <memory>
#include <iostream>

namespace double_node{
    template<typename T>
    struct Double_node{
        std:: shared_ptr<double_node::Double_node<T>> next;
        T data;
        std:: weak_ptr<double_node::Double_node<T>> previous;

        Double_node(const T &data):data{data}{};
    };
}

#endif //LISTS_DOUBLE_NODE_H
