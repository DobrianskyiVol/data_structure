#include <iostream>
#include "Double_list.h"
#include "Single_list.h"
#include <exception>

void single_list(){
    Single_list<int> list;
    std::cout << "Start: " << endl;
    std::cout << "Initial list: ";
    list.InsertAtBeginning(96);
    list.InsertAtBeginning(80);
    list.InsertAtBeginning(15);
    std::cout << list;

    std::cout << "Insert by index 2: ";
    list.insertByIndex(26,2);
    std :: cout << list;

    std::cout << "Remove on index 2: ";
    list.removeAtIndex(2);
    std::cout << list;

    std::cout << "Operator << ";
    std :: cout << list[2] << endl;

    std::cout << "Insert at end: 25 and 22";
    list.InsertAtEnd(25);
    std::cout << list;

    list.InsertAtEnd(22);
    std::cout << list;

    std::cout << "Delete first element: " << endl;
    list.DeleteFirst();
    std::cout << list;

    std::cout << "Delete last element: " << endl;
    list.DeleteTail();
    std::cout << list;


    std::cout << "Checking bool methods: ";
    if (list.search(92))
        std::cout << "true" << endl;
    else
        std::cout << "false" << endl;
    if(!list.EmptyList())
        std:: cout << "Empty list" << endl;
    else
        std::cout << "Non-empty list" << endl;
    std::cout <<"List size: "<< list.GetSize();

    std::cout << "End..." << endl;
}

void double_list(){
   Double_list<int> list;

    std::cout << "Start: " << endl;
    std::cout << "Initial list: ";
    list.InsertAtBeginning(96);
    list.InsertAtBeginning(80);
    list.InsertAtBeginning(15);
    std::cout << list;

    std::cout << "Insert by index 2: ";
    list.InsertAtIndex(2,25);
    std :: cout << list;

    std::cout << "Remove on index 2: ";
    list.RemoveAtIndex(2);
    std::cout << list;

    std::cout << "Operator << ";
    std :: cout << list[2] << endl;

    std::cout << "Insert at end: 25 and 22";
    list.InsertAtEnd(25);
    std::cout << list;

    list.InsertAtEnd(22);
    std::cout << list;

    std::cout << "Delete first element: " << endl;
    list.DeleteBeginning();
    std::cout << list;

    std::cout << "Delete last element: " << endl;
    list.DeleteEnd();
    std::cout << list;


    std::cout << "Checking bool methods: ";
    if (list.search(92))
        std::cout << "true" << endl;
    else
        std::cout << "false" << endl;
    if(!list.isEmptylist())
        std:: cout << "Empty list" << endl;
    else
        std::cout << "Non-empty list" << endl;

    std::cout << "List size "<<list.getsize();

    std::cout << "End..." << endl;
}

int main() {
    try {
    single_list();

    double_list();
    }catch (const std::out_of_range &exc){
        std::cout << exc.what();
    }
    return 0;
}
