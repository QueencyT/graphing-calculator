#ifndef ADD_ENTRY_FUNCTION
#define ADD_ENTRY_FUNCTION
#include "../../includes/array_functions/array_functions.h"

//let's operate on the fact that these lists will all be dynamic 

template<class T> 
void append(T* newListAddress, int& size_used, T new_entry){
    T* walker = newListAddress + size_used; //wanna go past one 
    *walker = new_entry; 
    size_used++; 
}

template<class T>
T* add_entry(T* list, const T& new_entry, int& size_used, int& capacity){
    T* walker; 
    T* newList; 

    if(size_used == capacity){
        capacity *= 2; 
        list = reallocate<T>(list, size_used, capacity); //hypothesis --> reallocate not working
    }
        // append(newList, size_used, new_entry); 
        // return newList; 
    append(list, size_used, new_entry); 
    return list; 

}

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size_used, int& capacity){ //removing at a certain index? 
//search for an entry 
//delete that entry --> if address found --> found != -1 
assert(size_used > 0); 

T* newList; 
const T* deleteAddress = &delete_me; 
shift_left(list, size_used, const_cast<T*>(deleteAddress)); //deleting at foundAddress 


if(size_used == (capacity / 4)){
    capacity /=2; 
    newList = reallocate<T>(list, size_used, capacity); 
    return newList; 
}
else{
    return list; 
}
return list;
}

template <class T>
T* remove_last_entry(T *list, T &popped,int &size_used, int &capacity){
    T* newList; 
    T* walker = list + size_used - 1;  
    popped = *walker;  
    newList = remove_entry(list, *walker, size_used, capacity);
    return newList; 
}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size_used, int &capacity){
    //insert at a certain index a certain value 
    T* newList; 
    T* walker;
    if(size_used == capacity){
        capacity*=2; 
        newList = allocate<T>(capacity); 
        copy_array(newList, list, size_used); 
        shift_right(newList,size_used,insert_here); 
    }
    else{
        newList = new T[capacity]; 
        copy_array(newList, list, size_used);
        shift_right(newList, size_used, insert_here); 
    }

    walker = newList + insert_here; 
    *walker = insert_this; 
    delete[] list; 
    list = nullptr; 
    return newList; 
}

template <class T>
T *erase_entry(T *list, int index,int &size_used, int &capacity){//remove an entry at a certain index
    T* delete_me = list + index; 
    T* newList = remove_entry(list, *delete_me, size_used, capacity); 
    return newList; 
}

#endif