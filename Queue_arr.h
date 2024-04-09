#ifndef LISTS_QUEUE_ARR_H
#define LISTS_QUEUE_ARR_H
#include <memory>
#include <stdexcept>

template<typename T>
class Queue_arr{
private:
    int size;
    int front;
    int rear;
    T *arr;
public:
    explicit Queue_arr(int c):size{c},front{0},rear{0}{
        arr = new T[size];
};

    ~Queue_arr(){delete[] arr;};


     bool IsFull(){
        if (rear== size)
            return true;
        else
            return false;
    }

    void enqueue(const T &value){
        if (IsFull()){
            throw std::out_of_range("Full list can't take any more objects");
        } else{
            arr[rear] = value;
            rear++;
        }
    }

    void dequeue(){
        if (rear == front)
            throw std::out_of_range("Empty queue, nothing to delete");

        for (int i = 0; i < rear-1; ++i) {
            std::swap(arr[i],arr[i+1]);
        }
        rear--;
    }

    T peek(){
        if (front == rear)
            throw std::out_of_range("Empty list,nothing to peek");
        else{
            return arr[front];
        }
     }

    friend std::ostream &operator <<(ostream &os,Queue_arr &value){
         os << "Queue: ";
        for (int i = 0; i < value.rear; ++i) {
            os << value.arr[i] << " ";
        }
        os << endl;
        return os;
     }
};
#endif //LISTS_QUEUE_ARR_H
