#include "../../includes/rpn/rpn.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token.h"
#include "../../includes/token/function.h"

RPN::RPN(const Queue<Token*>& someQueue){
    tokens = someQueue; 
}

double RPN::evaluation(double funcVal){
    double right, left; 
    Stack<double> nums; 
    Queue<Token*> copyTokens(tokens);
    while(!copyTokens.empty()){
        Token* popped = copyTokens.pop(); 
        if(popped->getType() == typeOperator){ //if popped is an operator
            int args = static_cast<Operator*>(popped)->get_number_of_args();  
            right = nums.pop(); 
            if(args > 1){
                left = nums.pop(); 
                result = static_cast<Operator*>(popped)->decider(left,right); 
            }
            else{
                result = static_cast<Operator*>(popped)->decider(right); 
            }
            nums.push(result); 
            continue; 
        }
        else if(popped->getType() == typeVariable){
            nums.push(funcVal); 
        }
        else{
            double num = stod(popped->getToken()); 
            nums.push(num); 
        }
    } 
    double finalRes = nums.pop();
    return finalRes; 
}

double RPN::evaluation(){
    double placeHolder = 0.0;
    return evaluation(0.0); 
}

void RPN::set_input(const Queue<Token*>& postFix){
    tokens = postFix; 
}
