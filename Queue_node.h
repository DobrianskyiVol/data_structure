#ifndef LISTS_QUEUE_NODE_H
#define LISTS_QUEUE_NODE_H
#include <memory>
#include <iostream>

namespace queue_node{
    template <typename T>
    struct Queue_node
            {
            std::weak_ptr<queue_node::Queue_node<T>> next;
            T data;
            std::shared_ptr<queue_node::Queue_node<T>> previous;
            explicit Queue_node(const T &data):data{data}{};

            };
}
#endif //LISTS_QUEUE_NODE_H
