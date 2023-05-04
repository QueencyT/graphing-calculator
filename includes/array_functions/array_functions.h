#ifndef POINTER_FUNCS_H
#define POINTER_FUNCS_H
#include <iostream>
#include "assert.h"

using namespace std; 

const int MINIMUM_CAPACITY = 3; //min capacity = 3

template<class T>
void shift_right(T *arr, int& size_used, T* shift_here){ //made the function definition //made the test
  const int things_to_shift = shift_here - arr; //5
  T* ptr; 
  T* prevPtr;
  assert(size_used > 0); 
    for(int i = size_used; i > things_to_shift; i--){
      ptr = arr + i; 
      prevPtr = arr + i - 1; 
      *ptr = *prevPtr; 
    }

       size_used++; 
} 

template<class T>
void shift_right(T *arr, int& size_used, int shift_here){//made the function definition //made the test
 shift_right(arr, size_used, (arr+shift_here)); 
} 

template<class T>
void shift_left(T *arr, int& size_used, T* shift_here){//fixed 
  const int startingIndex = shift_here - arr + 1; //index of the index after shift_here's 
 
  T* current; 
  T* previous; 

  for(int i = startingIndex; i < size_used; i++){//will loop until we reach the specified size 
    current = (arr + i); //current memory address 
    previous = (current - 1); 
    *(previous) = *(current); 
    //previous memory address gets the value stored in the currentMemoryAddres we are pointing to 
  }
       size_used--; 
}

template<class T>
void shift_left(T *arr, int& size_used, int shift_here){ //made the function definition made the test
shift_left(arr, size_used, (arr+shift_here)); 
}

template<class T>
void print(T *arr, int number_to_print){
  T* arrVal; 
      for(int i = 0; i < number_to_print; i++){
        arrVal = arr + i; 
    cout<<*arrVal<<endl; 
  }
} //made the function definition //prob no need to make a test for this

template<class T>
void print_array(T* arr, int size_used, int capacity = 0){
  T* arrVal; 
      for(int i = 0; i < size_used; i++){
        arrVal = arr + i; 
    cout<<*arrVal<<" "; 
  }
  cout<<endl; 
} //made the definition - might need to revise? //prob no need to make a test

template<class T>
T* search_entry(T* arr, int size_used, const T& find_me){
  T* arrVal; 
     for(int i = 0; i <  size_used; i++){
      arrVal = arr+i; 
    if(*arrVal == find_me){ 
      return (arrVal); 
    }
  }
  return nullptr; //when not found, we will return nullptr
} //made the definition //made the test 

template<class T>
int search(T* arr, int size_used, const T& find_me){//this returns first instance 
  T* arrVal; 
    for(int i = 0; i < size_used; i++){
      arrVal = arr + i; 
    if(*arrVal == find_me){//if we ever get another issue with removing stuff and it not removing correctly. Look here, and put it equal to address
      return i; 
    }
  }
  return -1; //when not found 
} //made the definition //made the test


template<class T>
void copy_array(T* dest, const T* src, int many_to_copy){
 T* destVal; 
  const T* srcVal; 
  for(int i = 0; i < many_to_copy; i++){
    destVal = dest + i;
    srcVal = src + i; 
    *destVal = *srcVal; 
  }
} //made the definition //made the test


template<class T>
T* copy_array(const T* arr, int size_used){//made the definition //made the test
     T* newArr = new T[size_used]; //with the new keyword this array is now created on the heap not the stack
     copy_array(newArr, arr, size_used);
    return newArr; //newArr is no longer pointing to the first one, we're returning the last address in newArr
  //and in order to properly pass an array the pointer needs to point to the first element 
} 



template<class T> 
string array_string(T *arr, int size_used){
  string resultString = ""; 
  double remainder; 
  bool hasRemainder;
  
  T* arrVal; 

  for(int i = 0; i < size_used; i++){
    remainder = *(arr + i) - (int)*(arr + i); 
    hasRemainder = (remainder != 0);  
    arrVal = arr + i; 
    
    if(isalpha(*arrVal) && !hasRemainder){ //for when it is a char
      resultString+= *arrVal; 
    }
    else{ //is not char aka everything else 
      resultString += to_string(*arrVal) + " "; 
    }
  }
  return resultString; 
}

/*template<class T> //comment out for now? and use professor's?
T* allocate(int capacity = MINIMUM_CAPACITY){
  T* arr = new T[capacity];
  return arr; 
}*/


template <class T> 
T* allocate(int capacity = MINIMUM_CAPACITY){ //this is from professor so no need to debug 
    const bool debug = false;
    //if (debug) cout<<"allocate: capacity: "<<capacity<<endl;
    //cout<<"allocate: capacity: "<<capacity<<endl;
    return new T[capacity];
}

template<class T>
T* reallocate(T* a, int size, int capacity){
  T* newArr = allocate<T>(capacity); //allocating new capacity
  copy_array(newArr, a, size);
  delete [] a;  //delete the old array 
  return newArr; 
}

#endif