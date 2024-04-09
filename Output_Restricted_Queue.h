#ifndef LISTS_OUTPUT_RESTRICTED_QUEUE_H
#define LISTS_OUTPUT_RESTRICTED_QUEUE_H
#include "ORQ_node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Output_Restricted_Queue{
private:
    std::shared_ptr<orq_node::ORQ_node<T>> head;
    std::shared_ptr<orq_node::ORQ_node<T>> tail;
    int size;
public:
    Output_Restricted_Queue():head{nullptr},tail{nullptr},size{0}{};

    explicit Output_Restricted_Queue(const T &value):head{std::make_shared<orq_node::ORQ_node<T>>(value)},tail{head},size{1}{};

    void enqueue_end(const T &value){
        std::shared_ptr<orq_node::ORQ_node<T>> newNode = std::make_shared<orq_node::ORQ_node<T>>(value);
        if (size == 0){
            head = newNode;
            tail = newNode;
        }else{
            tail->previous = std::move(newNode);
            tail = newNode;
            // tail->previous = nullptr;
        }
        size++;

    }

    void enqueue_start(const T &value){
        std::shared_ptr<orq_node::ORQ_node<T>> newNode = std::make_shared<orq_node::ORQ_node<T>>(value);
        if (size == 0){
            head = newNode;
            tail = newNode;
        }
        newNode->previous = std::move(head);
        head = newNode;
        size++;
    }

    T dequeue(){
        if (size == 0){
            throw out_of_range("Size equal to null, nothing to return");
        }
        T dequeddata = head->data;
        if (size == 1){
            head = head->previous;
            head.reset();
        } else{
            head = head->previous;
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

    friend std::ostream &operator<<(std::ostream &os, Output_Restricted_Queue &value){
        if (!value.size)
            throw out_of_range("Empty queue, nothing to show");
        orq_node::ORQ_node<T> *current = value.head.get();
        while (current != nullptr){
            os << current->data << " ";
            current = current->previous.get();
        }
        os << std::endl;
        return os;
    }
};




#endif //LISTS_OUTPUT_RESTRICTED_QUEUE_H
