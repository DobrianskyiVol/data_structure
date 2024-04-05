//
// Created by user on 03.04.2024.
//

#ifndef LISTS_SINGLE_LIST_H
#define LISTS_SINGLE_LIST_H

#include "Single_node.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Single_list{
private:
    std::unique_ptr<single_node::singleNode<T>> head;
    int size;
    void check(int index){
        if (index == 0 || index>=size)
            throw std::out_of_range("Index out of range");
    }
public:
    Single_list(): head{nullptr}, size{0}{};

    Single_list(const T &data): head{make_unique<>(data)}, size{1}{};

    void InsertAtBeginning(const  T &value){
        std::unique_ptr<single_node::singleNode<T>> newNode = make_unique<single_node::singleNode<T>>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }



    void InsertAtEnd(const T &value){
        std::unique_ptr<single_node::singleNode<T>> newNode = make_unique<single_node::singleNode<T>>(value);
        single_node::singleNode<T> *current = head.get();
        if (!current){
            head = std::move(newNode);
            size++;
            return;
        }else{
            while (current->next){
                current = current->next.get();
            }
            current->next = std::move(newNode);
            size++;
        }
    }


    void DeleteFirst(){
        if (!head){
            throw std::out_of_range("List is empty!");
        }
        head = std::move(head->next);
        --size;
    }

    void  DeleteTail(){
        if (!head){
            throw std::out_of_range("List is empty!");
        }
        if(size == 1){
            head.reset();
            --size;
            return;
        }
        single_node::singleNode<T> *current = head.get();
        while (current->next){
            current = current->next.get();
        }
        current->next.reset();
        --size;

    }

    void insertByIndex(const T &value,int index){
        check(index);
        if (index == 0) {
            InsertAtBeginning(value);
            return;
        } else if (index == size) {
            InsertAtEnd(value);
            return;
        }

        std::unique_ptr<single_node::singleNode<T>> newNode = make_unique<single_node::singleNode<T>>(value);
        single_node::singleNode<T> *current = head.get();

        for (int i = 0; i < index-1; ++i) {
            current = current->next.get();
        }

        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        size++;
    }

    void removeAtIndex(int index){
        check(index);
        if (index == 0){
            DeleteFirst();
            return;
        } else if(index == size){
            DeleteTail();
            return;
        }

        single_node::singleNode<T> *current = head.get();
        for (int i = 0; i < index-1; ++i) {
            current = current->next.get();
        }
         current->next = std::move(current->next->next);
        --size;
    }

    int GetSize(){
        return size;
    }

    bool search(const T &value) const{
//        if (EmptyList())
//            throw std::out_of_range("List is empty!");
        single_node::singleNode<T> *current = head.get();
        while (current){
            if (current->data == value){
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

    bool EmptyList(){
        if (!head)
            return false;
        else
            return true;
    }

   friend ostream &operator<<(ostream &os, const Single_list &obj){
       if (!obj.head) {
           return os;
       }
       single_node::singleNode<T> *current = obj.head.get();
        os << "List Data: " << endl;
       while (current!= nullptr){
           os << current->data << " ";
            current = current->next.get();
       }
        os << endl;
       return os;
    }

    T operator [](int index){
        check(index);
        single_node::singleNode<T> *current = head.get();
        for (int i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }



};

#endif //LISTS_SINGLE_LIST_H
