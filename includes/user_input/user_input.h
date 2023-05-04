#ifndef USER_INPUT_H 
#define USER_INPUT_H 

#include<iostream>
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/graph_history/graph_history.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/function.h"
#include "../../includes/token/token.h"
#include "../../includes/token/variable.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

using namespace std; 


class User_Input{
    public: 
        //CONSTRUCTORS 
        User_Input(); 
        User_Input(graph_info* graphInfoVal); 
        User_Input(graph_info* graphInfoVal, Graph_History* graphHistoryVal); 


        Queue<Token*> parser(); //gets the equ string and turns into a queue of tokens
        void setUserInput(string newEqu); //takes in the new equation from user and updates graphInfo, also adds equation to graphHistory
    private: 
        graph_info* graphInfo; 
        Graph_History* graphHistory; 
        Queue<Token*> infix; 
        void typeSetter(Queue<Token*>& infix, string& someStr); //sets the type of the broken up string 
    
}; 

#endif