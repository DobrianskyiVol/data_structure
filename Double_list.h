//
// Created by user on 04.04.2024.
//

#ifndef LISTS_DOUBLE_LIST_H
#define LISTS_DOUBLE_LIST_H
#include "Double_node.h"
#include <memory>
template<typename T>
class Double_list{
private:
    std::shared_ptr<double_node::Double_node<T>> head;
    int size;
    std::shared_ptr<double_node::Double_node<T>> tail;
    void check(int index){
        if (index == 0 || index>=size)
            throw std::out_of_range("Index out of range");
    }
public:
    Double_list():head{nullptr},tail{nullptr},size{0}{};

    Double_list(T &value):head{std::make_shared<double_node::Double_node<T>>(value)},tail{head},size{1}{};

    void InsertAtBeginning(const T &value){
        std::shared_ptr<double_node::Double_node<T>> newNode = std::make_shared<double_node::Double_node<T>>(value);
        if (!size){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    };

    void InsertAtEnd(const T &value){
        std::shared_ptr<double_node::Double_node<T>> newNode = std::make_shared<double_node::Double_node<T>>(value);
        if (!size){
            head = newNode;
            tail = newNode;
        } else{
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    void InsertAtIndex(int index,const T &value){

        check(index);

        if (index == 0){
            InsertAtBeginning(value);
            return;
        } else if(index == size){
            InsertAtEnd(value);
            return;
        }

        std::shared_ptr<double_node::Double_node<T>> newNode = std::make_shared<double_node::Double_node<T>>(value);
        std::shared_ptr<double_node::Double_node<T>> current = head;
        for (int i = 0; i < index-1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        size++;
    }

    void DeleteBeginning(){
        if (!head){
            return;
        } else if(size == 1){
            head->previous = head->next = nullptr;
            head.reset();
            return;
        }
        head = head->next;
        head->previous.reset()  ;
    }

    void DeleteEnd(){
        if (!head){
            return;
        }
        else if(size == 1){
           head = tail = nullptr;
        }
        else{
        tail = tail->previous.lock();
        tail->next = nullptr;
        }

        --size;
    }

    void RemoveAtIndex(int index){
        check(index);
        if (index == 0) {
            head = head->next;
            if (head) {
                head->previous.reset();
            } else {
                tail.reset();
            }
        } else if (index == size - 1) {
            tail = tail->previous.lock();
            tail->next.reset();
        } else {
           std::shared_ptr< double_node::Double_node<T> > current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            current->previous.lock()->next = current->next;
            current->next->previous = current->previous;
        }
        --size;
    }

    int getsize(){
        return size;
    }

    bool isEmptylist(){
        if (!head)
            return false;
        else
            return true;
    }

    friend std::ostream &operator <<(std::ostream &os, Double_list &value){
        if (!value.head) {
            return os;
        }
        double_node::Double_node<T> *current = value.head.get();
        os << "List data: " << "\n";
        while (current!= nullptr){
            os << current->data << " ";
            current = current->next.get();
        };
        os << std::endl;
        return os;
    }

    T operator [](int index){
        check(index);
        double_node::Double_node<T> *current = head.get();
        for (int i = 0; i < index; ++i){
            current = current->next.get();
        }
        return current->data;
    }


        bool search(const T &value) const{
//        if (EmptyList())
//            throw std::out_of_range("List is empty!");
           double_node::Double_node<T> *current = head.get();
            while (current){
                if (current->data == value){
                    return true;
                }
                current = current->next.get();
            }
            return false;
        }

};


#endif //LISTS_DOUBLE_LIST_H
