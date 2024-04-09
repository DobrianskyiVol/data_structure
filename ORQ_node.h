#ifndef LISTS_ORQ_NODE_H
#define LISTS_ORQ_NODE_H
#include <iostream>
#include <memory>

namespace orq_node {
    template<typename T>
    struct ORQ_node{
        T data;
        std::shared_ptr<orq_node::ORQ_node<T>> previous;

        explicit ORQ_node(const T &data):data{data},previous{nullptr}{};
    };
}


#endif //LISTS_ORQ_NODE_H
