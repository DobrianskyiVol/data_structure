#ifndef LISTS_SINGLE_NODE_H
#define LISTS_SINGLE_NODE_H

#include <memory>

namespace single_node{
    template<typename T>
    struct singleNode{
        T data;
        std::shared_ptr<singleNode> next;

        singleNode(const T &data):data{data},next{nullptr}{};
    };
}
#endif //LISTS_SINGLE_NODE_H
