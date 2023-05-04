#ifndef MY_QUEUE_H
#define MY_QUEUE_H 
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Queue
{
public:
   class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator(){
            _ptr = nullptr; //point to null by default 
        }                                     //default ctor
        Iterator(node<T>* p){
            _ptr = p; 
        }                   //Point Iterator to where p is pointing to
        operator bool(){
            return _ptr != nullptr; 
        }                               //casting operator: true if _ptr not NULL
                                                        //this turned out to be a pain!
        T& operator *(){
            return _ptr->_item; 
        }                      //dereference operator
        T* operator ->(){ //hmm? 
            //this is being used on a custom class obj Iterator, must make it so it works on ptr types 
            //-> works on ptrs 
            return &(_ptr->_item); 
        }                       //member access operator //need to see if this works 

        bool is_null(){
            return _ptr == nullptr; 
        }                              //true if _ptr is NULL

        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr; 
        } //true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr; //true if left == right
        }

        Iterator& operator++(){ //point to next ptr //returning ref, so create dynamic obj or obj that exists beyond this
            if(_ptr == nullptr){
                //Iterator nextIter = new Iterator; //creating a dyanmic null iterator 
                return *this; 
            }
            _ptr = _ptr->_next; //increment our iterator pointer 
            return *this; 
        }                      //member operator: ++it; or ++it = new_value //prefix version

        friend Iterator operator++(Iterator& it, int unused){ //friend function so cant just do _ptr, must be relative to something
            if(it._ptr == nullptr){
                Iterator nullIter; 
                return nullIter; 
            }
            Iterator returnIter(it._ptr); 
            it._ptr = it._ptr->_next; 
            return returnIter; 
        }         //friend operator: it++ //postfix version //return the orign val first then inc

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };      

    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();

    Queue& operator=(const Queue<T>& RHS){
        if(this == &RHS){//same obj
            return *this; 
        }
        //delete old list 
        _clear_list(_front); 
        _front = nullptr; //just make sure here its nullptr 
        _rear = _copy_list(_front, RHS._front); //previous to nullptr? 
        //_front = RHS._front; 
        return *this; 
    } //leave operators in class 

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const;            //Iterator to the head node
    Iterator end() const;              //Iterator to NULL
    void print_pointers();
    int size() const { return _size; }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe);
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};


 template <typename T>
    Queue<T>::Queue(){//empty queue //basically just a linked list 
        _front = nullptr; 
        _rear = nullptr; 
        _size = 0;
    }

    template <typename T>
    Queue<T>::Queue(const Queue<T>& copyMe){ //copy ctor
        _front = nullptr; 
        _rear = _copy_list(_front, copyMe._front); 
        
        //_front = _copy_list(copyMe._front);  //need to get access to rear --> last node maybe? 
        //_rear = new node<T>(copyMe._rear, nullptr); //pretty sure we need to allocate new addess so that itll have same val but a new add 
        //if rear I'm pretty sure it's the last node and we point it to rear 
        //_rear = copyMe._rear; 
        _size = copyMe._size; 
    }

    template <typename T>
    Queue<T>::~Queue(){
        _clear_list(_front); 
    }

    template <typename T>
    bool Queue<T>::empty(){
        return _front == nullptr; //if beginning == end, then empty, if else then there's at least one 
        //could just do begin()==nullptr but I guess let's do this way for aesthetics~
    }

    template <typename T>
    T Queue<T>::front(){ //return item at front 
        return _front->_item; 
    }

    template <typename T>
    T Queue<T>::back(){
        return _rear->_item; 
    }

    template <typename T>
    void Queue<T>::push(T item){//enqueue //insert from BACK 
        _rear = _insert_after(_front, _rear, item); //insert after the ele that points to nullptr; 
        _size++; 
        //then update rear cause there's a new rear now 
        //test for empty and one item case later 
    }

    template <typename T>
    T Queue<T>::pop(){ //dequeue //removing from front //and return the deletion
        //T returnVal = _front->_item; //current front item 
        //_front = _delete_node(_front, _front);  //that means we need to update head, because old head was deleted 
        _size--; 
        return _delete_node(_front, _front); 
    }

    template <typename T>
    typename Queue<T>::Iterator Queue<T>::begin() const{
        Queue<T>::Iterator beginIter(_front); 
        return beginIter; 
    }            //Iterator to the head node

    template <typename T>
    typename Queue<T>::Iterator Queue<T>::end() const{ //just set to nullptr 
        Queue<T>::Iterator endIter; //remember dont do Iterator endIter() b/c thats a funciton call 
        return endIter; 
    }             //Iterator to NULL

    template <typename T>
    void Queue<T>::print_pointers(){
        _print_list(_front); 
    }

    template<typename TT>//if declared outside, declare like this with a specific template 
    ostream& operator << (ostream& outs, const Queue<TT>& printMe){
        cout<<"Queue: "; 

        for(node<TT>* nodeWalker = printMe._front; nodeWalker != nullptr; nodeWalker = nodeWalker->_next){
            outs<<"["<<nodeWalker->_item<<"] ";
        }

        outs<<endl; 
        return outs; 
    }

#endif