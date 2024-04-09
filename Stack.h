//
// Created by user on 09.04.2024.
//

#ifndef LISTS_STACK_H
#define LISTS_STACK_H
#include "Stack_node.h"
#include <stdexcept>

template<typename T>
class Stack{
    std::unique_ptr<stack_node::Stack_node<T>> head;
    int size;
public:
    Stack():head{nullptr},size{0}{};

    explicit Stack(T &value):head{std::make_unique<stack_node::Stack_node<T>>(value)},size{1}{}

    bool IsFull(){
        if (!size)
            return false;
        else
            return true;
    }

    void push(const T &value){
        std::unique_ptr<stack_node::Stack_node<T>> newNode = std::make_unique<stack_node::Stack_node<T>>(value);
        if (size == 0)
            head = std::move(newNode);
        else{
            newNode->previous = std::move(head);
            head = std::move(newNode);
        }
        size++;
    }

    void pop(){
        if (!IsFull())
            throw std::out_of_range("Nothing to pop, empty stack was called");
        head = std::move(head->previous);
        size--;
    }

    T peek(){
        if (!IsFull())
            throw std::out_of_range("Nothing to peek, empty stack was called");
        return head->data;
    }

    friend std::ostream &operator<<(std::ostream &os,Stack &value){
        if (!value.IsFull())
            throw std::out_of_range("Nothing to output, empty list was called");

        stack_node::Stack_node<T> *current = value.head.get();
        os << "Stack data: ";
        while (current != nullptr){
            os << current->data << " ";
            current = current->previous.get();
        }
        os << std::endl;
        return os;
    }
};

#endif //LISTS_STACK_H
