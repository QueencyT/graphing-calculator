#ifndef SHUNTING_YARD_H 
#define SHUNTING_YARD_H 

#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/stack/MyStack.h"

//job is to convery 3+5 --> into 35+ 
class ShuntingYard{
    public: 
        //constructors 
        ShuntingYard(); 
        ShuntingYard(const Queue<Token*>& someQueue); 

        Queue<Token*> postfix(); //function to turn an infix equation into a postfix equation --> uses te infix equ class variable
        Queue<Token*> postfix(const Queue<Token*>& someQueue); //turns the infix argument into a postfix equ 
        void infix(const Queue<Token*>& someQueue); //initializes class variable infix 

    private: 
        const int operatorType = 3; 
        const int parenType = 2; 
        const int functionType = 5; 
        Queue<Token*> inFix; 
        void popRest(Queue<Token*>& output, Stack<Token*>& operators); 
        void operatorDecider(Token* popped, Queue<Token*>& numbers, Stack<Token*>& operators); 
        void parenDecider(Token* popped, Queue<Token*>& numbers, Stack<Token*>& operators); 
}; 
#endif