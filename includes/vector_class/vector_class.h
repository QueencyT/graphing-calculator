#ifndef VECTOR_H
#define VECTOR_H
#include "../../includes/add_entry/add_entry.h"
#include<iostream>
using namespace std; 


template <class T>
class Vector{
public:
    Vector(int capacity = 3){ //made test //setting CAPACITY to 100 according to notes
        size_used = 0; //newly changed
        cap = capacity; //should start off with room for at least two appends //newly changed
        ourVector = allocate<T>(cap); //allocating a dynamic array with capacity 100 and storing into private class member ourVector 
    }

    Vector(T *arr, int size){ //made test

        size_used = size;
        cap = size + 2; 
        ourVector = allocate<T>(cap);
        copy_array(ourVector, arr, size_used); 
    }

    Vector(const Vector<T>& vectorObj){//the copy constructor //made test
       size_used = vectorObj.size_used; 
       cap = vectorObj.cap; 
       T* newVector = new T[cap]; 
       copy_array(newVector, vectorObj.ourVector, size_used); 
       ourVector = newVector; 
    }
    
    Vector& operator =(const Vector<T>& vectorObj){//made test //the equal operator
       if(this == &vectorObj){ //newly added 
        return *this; 
       }
        T* newVector = new T[vectorObj.cap]; 
        copy_array(newVector, vectorObj.ourVector, vectorObj.size_used); 
        delete[] ourVector; 
        ourVector = nullptr; 
        ourVector = newVector; 
        size_used = vectorObj.size_used; 
        cap = vectorObj.cap; 
        return *this; 
    }

    ~Vector(){//the destructor 
        delete[] ourVector; 
        ourVector = nullptr; 
    }

    //member access functions:
    T& operator [](int index){ //returns a reference to the value at that index //made the test
        T* returnVal = ourVector + index; 
        return *returnVal;  
    } 

    const T& operator [](int index) const{ //made the test
        T* returnVal = ourVector + index; 
        return *returnVal; 
        //return ourVector[index];  --> try out later 
    }

    T& at(int index){ //made the test
        T* returnVal = ourVector + index; 
        return *returnVal; 
    }              //return reference to item at position index

    const T& at(int index) const{ //made the test
        T* returnVal = ourVector + index; 
        return *returnVal; 
    } //return a const item at position index

    T& front(){ //made test
        return *ourVector; 
    }                     //return item at position 0.
    
    T& back(){ //made test
    T* returnVal = ourVector + size_used - 1; 
        return *returnVal; 
    }                         //return item at the last position

    //Push and Pop functions:
    Vector& operator +=(const T& item){//made test
        //ourVector = add_entry(ourVector, item, size_used, cap); //append  
        ourVector = insert_entry(ourVector,item, size_used, size_used, cap); 
        return *this;
    }//push_back

    void push_back(const T& item){ //made test
        ourVector = add_entry(ourVector, item, size_used, cap); 
        //ourVector = insert_entry(ourVector, item, size_used, size_used, cap); 
    } 

    T pop_back(){ //made test
        T popped; 
        ourVector = remove_last_entry(ourVector, popped, size_used, cap); 
        return popped; 
    }                     //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this){ //made test
        ourVector = insert_entry(ourVector, insert_this, insert_here, size_used, cap); 
        cout<<size_used<<endl; 
        cout<<cap<<endl;
    } //insert at pos

    void erase(int erase_this_index){ //made test
        ourVector = erase_entry(ourVector, erase_this_index, size_used, cap); 
    }      //erase item at position

    int index_of(const T& item){ //made test
        int found = search(ourVector, size_used, item); 
        return found; 
    }            //search for item. retur index.

    //size and capacity:
    void set_size(int size){
        size_used = size; 

        T* newVector = new T [cap]; 
        copy_array(newVector, ourVector, size_used); 
        delete[] ourVector; 
        ourVector = newVector; 
        //reallocate<T>(ourVector, size_used, cap); 
        //cap = size_used + 2; delete this --> because if we call this we're not just setting size, we're also setting capacity 
        //ourVector = reallocate<T>(ourVector, size_used, size_used); 
    }             //enlarge the vector to this size

    void set_capacity(int capacity){
        cap = capacity; 
        T* newVector = new T [cap];
        copy_array(newVector, ourVector, size_used); 
        delete[] ourVector; 
        ourVector = newVector; 
        
        //reallocate<T>(ourVector, size_used, cap); 

        //ourVector = reallocate<T>(ourVector, size_used, cap); 
    }     //allocate this space

    int size() const { //made test
        return size_used;
    }  //return _size

    int capacity() const { //made test
        return cap;
    } //return _capacity

    bool empty() const{
        return (ourVector - (ourVector + size_used) == 0); 
    }                   //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator << (ostream& outs, const Vector<U>& _a); 

private:
    T* ourVector; 
    int cap;        //
    int size_used;  
};

//OUTPUT:
    template <class U>
    ostream& operator << (ostream& outs, const Vector<U>& _a){
        U* vectorWalker = _a.ourVector; 

        for(int i = 0; i < _a.size_used; i++, vectorWalker++){
            outs<<*vectorWalker<<" "; 
        }
        outs<<endl; 
        return outs; 
    }

#endif