#include <iostream>
#include "Double_list.h"
#include "Single_list.h"
#include <stdexcept>
#include "Queue.h"
#include "Queue_arr.h"
#include "Stack.h"
#include "Stack_arr.h"
#include "Output_Restricted_Queue.h"

//void single_list(){
//    Single_list<int> list;
//    std::cout << "Start: " << endl;
//    std::cout << "Initial list: ";
//    list.InsertAtBeginning(96);
//    list.InsertAtBeginning(80);
//    list.InsertAtBeginning(15);
//    std::cout << list;
//
//    std::cout << "Insert by index 2: ";
//    list.insertByIndex(26,2);
//    std :: cout << list;
//
//    std::cout << "Remove on index 2: ";
//    list.removeAtIndex(2);
//    std::cout << list;
//
//    std::cout << "Operator << ";
//    std :: cout << list[2] << endl;
//
//    std::cout << "Insert at end: 25 and 22";
//    list.InsertAtEnd(25);
//    std::cout << list;
//
//    list.InsertAtEnd(22);
//    std::cout << list;
//
//    std::cout << "Delete first element: " << endl;
//    list.DeleteFirst();
//    std::cout << list;
//
//    std::cout << "Delete last element: " << endl;
//    list.DeleteTail();
//    std::cout << list;
//
//
//    std::cout << "Checking bool methods: ";
//    if (list.search(92))
//        std::cout << "true" << endl;
//    else
//        std::cout << "false" << endl;
//    if(!list.EmptyList())
//        std:: cout << "Empty list" << endl;
//    else
//        std::cout << "Non-empty list" << endl;
//    std::cout <<"List size: "<< list.GetSize();
//
//    std::cout << "End..." << endl;
//}
//
//void double_list(){
//   Double_list<int> list;
//
//    std::cout << "Start: " << endl;
//    std::cout << "Initial list: ";
//    list.InsertAtBeginning(96);
//    list.InsertAtBeginning(80);
//    list.InsertAtBeginning(15);
//    std::cout << list;
//
//    std::cout << "Insert by index 2: ";
//    list.InsertAtIndex(2,25);
//    std :: cout << list;
//
//    std::cout << "Remove on index 2: ";
//    list.RemoveAtIndex(2);
//    std::cout << list;
//
//    std::cout << "Operator << ";
//    std :: cout << list[2] << endl;
//
//    std::cout << "Insert at end: 25 and 22";
//    list.InsertAtEnd(25);
//    std::cout << list;
//
//    list.InsertAtEnd(22);
//    std::cout << list;
//
//    std::cout << "Delete first element: " << endl;
//    list.DeleteBeginning();
//    std::cout << list;
//
//    std::cout << "Delete last element: " << endl;
//    list.DeleteEnd();
//    std::cout << list;
//
//
//    std::cout << "Checking bool methods: ";
//    if (list.search(92))
//        std::cout << "true" << endl;
//    else
//        std::cout << "false" << endl;
//    if(!list.isEmptylist())
//        std:: cout << "Empty list" << endl;
//    else
//        std::cout << "Non-empty list" << endl;
//
//    std::cout << "List size "<<list.getsize();
//
//    std::cout << "End..." << endl;
//}

int main() {
//    try {
//        Queue_arr<int> q(5);
//        q.enqueue(2);
//        q.enqueue(5);
//        q.enqueue(65);
//        q.enqueue(65);
//        q.enqueue(65);
//        q.dequeue();
//        q.dequeue();
//        int a = q.peek();
//        std::cout << q;
//        std::cout << a;
//    }catch (std::out_of_range &msg){
//        std::cout << msg.what();
//    }
//try {
//    Stack<int> stack;
//    stack.push(12);
//    stack.push(14);
//    stack.push(13);
//    std::cout << stack;
//    stack.pop();
//    std::cout << stack;
//    int b = stack.peek();
//    std::cout << b;
//    stack.pop();
//    stack.pop();
//    stack.pop();
//}catch (std::out_of_range &msg){
//    std:: cerr << msg.what();
//}

//Stack_arr<int> arr(5);
//arr.push(5);
//arr.push(6);
//arr.push(7);
//std::cout << arr;
//arr.pop();
//std::cout << arr;
//    arr.push(9);
//    std::cout << arr;


Output_Restricted_Queue<int> queue;
int a =  25;
queue.enqueue_end(25);
queue.enqueue_start(26);
std::cout << queue;
queue.dequeue();
std::cout << queue;

    return 0;
}
