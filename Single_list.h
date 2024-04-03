//
// Created by user on 03.04.2024.
//

#ifndef LISTS_SINGLE_LIST_H
#define LISTS_SINGLE_LIST_H

#include "Single_node.h"

using namespace std;

template<typename T>
class Single_list{
private:
    std::unique_ptr<single_node::singleNode<T>> head;
    int size;
public:
    Single_list(): head{nullptr}, size{0}{};

    Single_list(const T &data): head{make_unique<>(data)}, size{1}{};


};




#endif //LISTS_SINGLE_LIST_H
