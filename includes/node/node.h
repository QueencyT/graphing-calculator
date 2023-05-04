#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std; 

template <typename ITEM_TYPE>
struct node
{
public:
    node(const ITEM_TYPE& item = ITEM_TYPE(), node* next = nullptr){
        _item = item; 
        _next = next; 
    }

      //output
    template <typename T>
    friend std::ostream& operator <<(std::ostream& outs, const node<T> &printMe);

    //public variables 
    ITEM_TYPE _item;
    node* _next; //pointer so we're supposed to make our own big three 
};

template <typename T>
ostream& operator <<(ostream& outs, const node<T> &printMe){
    outs<<"["<<printMe._item<<"]"<<" "; 
    return outs; 
}

 #endif