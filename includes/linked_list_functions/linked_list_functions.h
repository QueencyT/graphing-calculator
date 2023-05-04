#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include "../../includes/node/node.h"
#include <cassert>

//Linked List General Functions:
    template <typename ITEM_TYPE>
    void _print_list(node<ITEM_TYPE>* head){ //need to test
        node<ITEM_TYPE>* nodeWalker = head; 
        
        while(nodeWalker != nullptr){//might be off by one, check the ends 
            cout<<*nodeWalker; 
            nodeWalker = nodeWalker ->_next; 
        }
        cout<<endl; 
    }

    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE>* head){//let's just do recursively for now 
        if(head -> _next == nullptr){
            cout<<*head<<endl; 
            return; 
        }
        else{
            _print_list_backwards(head ->link); 
            cout<<*head<<endl; 
        }
    }

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key){//think about the empty case, does it work or not? --> pretty sure it works 
        node<ITEM_TYPE>* returnVal; 
        for(node<ITEM_TYPE>* node = head; node != nullptr; node = node-> _next){ //walking through the list until reach the end, may be off by one, check the ends 
            if(node->_item == key){ //if the node value == the key
                returnVal = node; 
                return returnVal; 
            }
        }
        return nullptr; //if not found, nullptr returned 
    }


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this){//insrrt at beginning 
        node<ITEM_TYPE>* insertNode = new node<ITEM_TYPE>(insert_this, head); //we want it to point to head and then let head == inser_node 
        head = insertNode; 
        return head;  //ask prof what we want to return, we want to return head?
    } //working so far 

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this){//assuming that after_this is inside the list? 
       if(head == nullptr){ //empty case 
        _insert_head(head, insert_this);
        return head;
       }

        node<ITEM_TYPE>* insertNode = new node<ITEM_TYPE>(insert_this, after_this -> _next); //point to the object after_this 
        after_this->_next = insertNode;  
        return insertNode;  //return the insertedNode? //ask Prof
    }

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this){ //maybe use this in before this function? 
        node<ITEM_TYPE>* nextNode; 
      //assuming there is a previous node to prev_to_this (so assuming valid input)

       for(node<ITEM_TYPE>* node = head; node != nullptr; node = node -> _next){//one off on purpose
            nextNode = node->_next; 
            if(nextNode == prev_to_this){
                return node;  
            }
       }
       return nullptr; //for empty case //pretty sure this return statement shouldn't be run, but jsut in case 
    }


    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this){ //assuming before this is inside the list? 
        node<ITEM_TYPE>* nextNode; 
        node<ITEM_TYPE>* insertNode; 
        node<ITEM_TYPE>* prevNode; 

        if(head == before_this){ //inserting before head //head == nullptr is also covered by this 
            insertNode = _insert_head(head, insert_this); 
            return insertNode; 
        }

        prevNode = _previous_node(head, before_this); 
        insertNode = new node<ITEM_TYPE>(insert_this, before_this); //points to before this 
        prevNode->_next = insertNode; //trying to clean up code 
        return insertNode; //ask prof 
    }

    
    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this){//successful so far //assuming delete_this exists withing func 

        if(head == delete_this){//one item case covered here 
            node<ITEM_TYPE>* next = head->_next; 
            ITEM_TYPE returnVal = head->_item; 
            delete head; 
            head = nullptr; 
            head = next; 
            return returnVal; //return what temp was pointing to 
        }

        //assuming at this point we're not deleting the head, and the list has more than one 
        ITEM_TYPE returnVal = delete_this->_item; 
        node<ITEM_TYPE>* prevNode = _previous_node(head, delete_this); 
        node<ITEM_TYPE>* nextNode = delete_this->_next; 
        delete delete_this; 
        delete_this = nullptr; 
        prevNode->_next = nextNode; 
        return returnVal; 
    }

    template <typename T>
    node<T> *_copy_list(node<T>* &dest, node<T> *src){
        node<T>* newHead = nullptr; 
        node<T>* srcWalker = src; 
        node<T>* destWalker = newHead; 

        if(src  == nullptr){ 
            dest = nullptr; 
            return nullptr; 
        }
      
        while(srcWalker != nullptr){
            destWalker = _insert_after(newHead, destWalker, srcWalker->_item); //newHead is updated by insert_after 
            srcWalker = srcWalker->_next; 
        }
        dest = newHead; 
        return destWalker; //at this point destwalker should be pointing to last node
    }
    
    

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head){//head being srcHead
        node<ITEM_TYPE>* destHead;
        node<ITEM_TYPE>* temp = _copy_list(destHead, head); 
        return destHead; 
    }
   
    //delete all the nodes
    
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head){//probably just delete all the way through
        node<ITEM_TYPE>* nextNode; 
 
        for(node<ITEM_TYPE>* node = head; node != nullptr; ){ //should be working, but double check 
            nextNode = node ->_next; 
            _delete_node(head, node); 
            node = nextNode;
        }
        head = nullptr; //added so head is updated, and not just some random pointer that has been deleted
    }

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos){ 
        node<ITEM_TYPE>* nodeWalker = head; 
        for(int i = 0; i < pos; i++){
            nodeWalker = nodeWalker -> _next; 
        }

        return nodeWalker->_item; 
    }

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending=true){ //assuming at this point at least one item //what about one item case 
        node<ITEM_TYPE>* nextNode; 
        node<ITEM_TYPE>* nodeWalker; 
        for(nodeWalker = head; nodeWalker->_next != nullptr; nodeWalker = nodeWalker -> _next){
            nextNode = nodeWalker->_next; 
            if(ascending && item <= nextNode->_item){
                return nodeWalker; //whihc is the one before and do insert_after 
            }
            else if(!ascending && item >= nextNode->_item){
                return nodeWalker; 
            }
        }
        return nodeWalker; 
    }

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=true){
        //one item case?
        //1,2,3,5,6,7,8,9,10 --> trying to insert 4, 11 , assuming sorted 
        //10,9,8,7,6,5,3,2,1 --> trying to insert 4, 
        node<ITEM_TYPE>* nextNode; 
        node<ITEM_TYPE>* insertNode; 
        if(head == nullptr){//empty case 
            _insert_head(head, item); 
            return head; 
        }

        if(ascending && item <= head->_item){
            _insert_head(head, item); 
            return head; 
        }

        if(!ascending && item >= head->_item){
            _insert_head(head, item); 
            return head; 
        }

        node<int>* insert_after = _where_this_goes(head, item, ascending); //finds the address to insert before 
        insertNode = _insert_after(head, insert_after, item); 
        return insertNode; 
    }

    //insert or add if a dup
    template <typename ITEM_TYPE> //like actually add? --> must ask prof
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=true){
        //what if one item, and what if inserting at head 
        node<int>* foundAddress = _search_list(head, item);
        node<ITEM_TYPE>* nextNode; 
        node<ITEM_TYPE>* insertNode; 


        if(foundAddress != nullptr){//if item exists --> add 
            foundAddress->_item += item; 
            return foundAddress; 
        }

        //else that means it isn't a dupe and we can just insert_sort like normal 
        insertNode = _insert_sorted(head, item, ascending); 
        return insertNode; 
    }

    

    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head){//modified
        node<ITEM_TYPE>* nodeWalker; 
        
        if(head == nullptr){//empty case
            return nullptr; 
        }

        for(nodeWalker = head; nodeWalker->_next != nullptr; nodeWalker = nodeWalker -> _next){ //if condition is nodeWalker != nullptr, we're always returning nodeWalker wit nullptr val
            //empty body, any way to make this less ugly hmmmmmmmmmmmmmmmmmmmmm? 
        }
        return nodeWalker; 
    };  //why did i need this here ???
    //don't use, inefficient, what if 1,000,000 nodes? are we going to cycle through them? 

#endif