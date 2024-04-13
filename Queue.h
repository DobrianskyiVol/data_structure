#ifndef LISTS_QUEUE_H
#define LISTS_QUEUE_H
#include <memory>
#include <iostream>
#include "Queue_node.h"

template<typename T>
class Queue{
private:
    std::shared_ptr<queue_node::Queue_node<T>> head;
    std::shared_ptr<queue_node::Queue_node<T>> tail;
    int size;
public:
    Queue():head{nullptr},tail{nullptr},size{0}{};

    Queue(T &data):head{std::make_shared<>(data)},
    tail{head},size{1}{};

    void enqueue(const T &value){
        std::shared_ptr<queue_node::Queue_node<T>> newNode = std::make_shared<queue_node::Queue_node<T>>(value);
        if (size == 0){
            head = newNode;
            tail = newNode;
        }else{
            tail->previous = newNode;
            newNode->next = tail;
            tail = newNode;
           // tail->previous = nullptr;
        }
        size++;

    }
    T dequeue(){
        if (size == 0){
            throw out_of_range("Size equal to null, nothing to return");
        }
        T dequeddata = head->data;
        if (size == 1){
            head = nullptr;
            tail = nullptr;
        } else{
            head = head->previous;
            head->next.lock() = nullptr;
        }
        size--;
        return dequeddata;
    }


    T peek(){
        if (size == 0)
            throw out_of_range("Size equal to null, nothing to return");

        return head->data;
    }

    bool IsEmpty(){
        if (!size)
            return false;
        else
            return true;
    }

    friend std::ostream &operator<<(std::ostream &os, Queue &value){
        if (!value.size)
            throw out_of_range("Empty queue, nothing to show");
        queue_node::Queue_node<T> *current = value.head.get();
        while (current != nullptr){
            os << current->data << " ";
            current = current->previous.get();
        }
        os << std::endl;
        return os;
    }
};

#endif //LISTS_QUEUE_H
