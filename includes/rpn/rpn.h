#ifndef RPN_H
#define RNP_H

#include "../../includes/token/token.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/operator.h"

//shunting yard converts to RPN --> rpn evaluates 
//class that evaluates a postfix equ 
class RPN{
    public: 
        //constructors 
        RPN(const Queue<Token*>& someQueue); 

        double evaluation(double funcVal); //evaluates a postfix expression and plugs in a double for the variable value
        double evaluation(); //overload of previous function 

        void set_input(const Queue<Token*>& postFix); //basically takes in a postFix queue and sets it to token 

        //operators that basically just call the eval functions --> does exact same thing just with different syntax 
        double operator()(){
            return evaluation(); 
        }

        double operator()(double funcVal){
            return evaluation(funcVal); 
        }
    private: 
        Queue<Token*> tokens; 
        double result; 
        const int typeOperator = 3; 
        const int typeFunction = 5; 
        const int typeVariable = 4; 
        const int typeParen = 2; 
}; 
#endif 