#ifndef LISTS_QUEUE_NODE_H
#define LISTS_QUEUE_NODE_H
#include <memory>
#include <iostream>

namespace queue_node{
    template <typename T>
    struct Queue_node
            {
            T data;
            std::shared_ptr<queue_node::Queue_node<T>> previous;
            Queue_node(const T &data):data{data},previous{nullptr}{};

            };
}
#endif //LISTS_QUEUE_NODE_H