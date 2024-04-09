//
// Created by user on 09.04.2024.
//

#ifndef LISTS_STACK_NODE_H
#define LISTS_STACK_NODE_H
#include <iostream>
#include <memory>

namespace stack_node {
    template<typename T>
    struct Stack_node{
       T data;
       std::unique_ptr<stack_node::Stack_node<T>> previous;

       Stack_node(const T &data):data{data},previous{nullptr}{};
    };

}
#endif //LISTS_STACK_NODE_H
