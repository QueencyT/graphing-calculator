#ifndef MY_STACK_H
#define MY_STACK_H
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

template <typename T>
class Stack{
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
            return _ptr; 
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

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();

    Stack<T>& operator=(const Stack<T>& RHS){
        if(this == &RHS){
            return *this; 
        }

        _clear_list(_top); 
        _top = _copy_list(RHS._top); 
        return *this; 
        //4 <--- top 
        //3
        //2
        //1
    }

    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename TT>
    friend ostream& operator<<(ostream& outs, 
                                        const Stack<TT>& printMe);

    Iterator begin() const;              //Iterator to the head node
    Iterator end() const;                //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};



template <typename T>
Stack<T>::Stack(){//empty stack 
    _top = nullptr; 
    _size = 0; 

}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _top = _copy_list(copyMe._top);
    _size = copyMe._size; 
}

template <typename T>
Stack<T>::~Stack(){
    _clear_list(_top);
}

template <typename T>
T Stack<T>::top(){
    return _top ->_item;
}

template <typename T>
bool Stack<T>::empty(){
    return _top == nullptr; 
}

template <typename T>
void Stack<T>::push(T item){ //LIFO, all action happens on one end 
   _top = _insert_head(_top, item); 
   _size++; 
}

template <typename T>
T Stack<T>::pop(){
    _size--; 
    return _delete_node(_top, _top); 
}

template<typename TT>
ostream& operator<<(ostream& outs, const Stack<TT>& printMe){

    node<TT>* nodeWalker = printMe._top; 
    while(nodeWalker != nullptr){
    cout<<"["<<nodeWalker->_item<<"] "; 
    nodeWalker = nodeWalker->_next; 
    }

    outs<<endl; 
    return outs; 
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    Stack<T>::Iterator beginIter(_top); 
    return beginIter; 
}             //Iterator to the head node

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const{
    Stack<T>::Iterator endIter; 
    return endIter; 
}              //Iterator to NULL

#endif