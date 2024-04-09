//
// Created by user on 09.04.2024.
//

#ifndef LISTS_STACK_ARR_H
#define LISTS_STACK_ARR_H
#include <iostream>

template<typename T>
class Stack_arr{
    private:
        int size;
        int front;
        int rear;
        T *arr;
    public:
        explicit Stack_arr(int c):size{c},front{0},rear{0}{
            arr = new T[size];
        };

        ~Stack_arr(){delete[] arr;};


        bool IsFull(){
            if (front == size)
                return true;
            else
                return false;
        }

        void push(const T &value){
            if (IsFull()){
                throw std::out_of_range("Full list can't take any more objects");
            } else{
                arr[front] = value;
                front++;
            }
        }

        void pop(){
            if (rear == front)
                throw std::out_of_range("Empty queue, nothing to delete");

            front--;
        }

        T peek(){
            if (front == rear)
                throw std::out_of_range("Empty list,nothing to peek");
            else{
                return arr[front];
            }
        }

        friend std::ostream &operator <<(std::ostream &os,Stack_arr &value){
            os << "Stack: ";
            for (int i = 0; i < value.front; ++i) {
                os << value.arr[value.front-(i+1)] << " ";
            }
            os << std::endl;
            return os;
        }
};
#endif //LISTS_STACK_ARR_H
