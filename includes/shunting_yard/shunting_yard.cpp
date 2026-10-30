#include "../../includes/shunting_yard/shunting_yard.h"

ShuntingYard::ShuntingYard(){
    Queue<Token*> nullQueue; 
    inFix = nullQueue; 
}

ShuntingYard::ShuntingYard(const Queue<Token*>& someQueue){
    inFix = someQueue; 
}

void ShuntingYard::infix(const Queue<Token*>& someQueue){
    inFix = someQueue; 
}

Queue<Token*> ShuntingYard::postfix(const Queue<Token*>& someQueue){
    infix(someQueue); 
    return postfix(); 
}
 
Queue<Token*> ShuntingYard::postfix(){
    Queue<Token*> numbers;
    Stack<Token*> operators; 
    while(!inFix.empty()){ 
        Token* popped = inFix.pop(); //pop an operator
        if(popped->getToken() == ")" || popped->getToken() == "("){
            parenDecider(popped, numbers,operators); 
        }
        else if(popped->getType() == operatorType){
            operatorDecider(popped, numbers, operators); 
            continue; 
        }
        else{
            numbers.push(popped); 
        }
    }
    popRest(numbers, operators);  
    return numbers; 
}

void ShuntingYard::popRest(Queue<Token*>& output, Stack<Token*>& operators){
    while(!operators.empty()){
        Token* op = operators.pop();
        if(!(op->getToken() == ")" || op->getToken() == "(")){
            output.push(op); 
        }
    }
}

void ShuntingYard::operatorDecider(Token* popped, Queue<Token*>& numbers, Stack<Token*>& operators){
     Token* stackOp; 
     int precedence = static_cast<Operator*>(popped)->getPrecedence(); 
     
     //while operators stack not empty and the precedence of the popped operator is lower than the precednece of the operator on the stack 
     while(!operators.empty() && precedence <= static_cast<Operator*>(*(operators.begin()))->getPrecedence()){
        stackOp = operators.pop(); 
        numbers.push(stackOp); //add to output 
    }

    operators.push(popped); //push the popped op onto stack now in correct place 
}


void ShuntingYard::parenDecider(Token* popped, Queue<Token*>& numbers, Stack<Token*>& operators){
    string tokVal = popped->getToken(); 
    if(tokVal == ")"){ 
        while(!operators.empty() && operators.top()->getToken() != "("){
            numbers.push(operators.pop());
        }
        if(!operators.empty()) //guard against mismatch case
            operators.pop(); //remove the matching "(" from the stack
    }
    else{
        operators.push(popped);
    }
}

/*
void ShuntingYard::parenDecider(Token* popped, Queue<Token*>& numbers, Stack<Token*>& operators){
    string tokVal = popped->getToken(); 
    if(tokVal == ")"){
        popRest(numbers, operators); 
    }
    else{
        operators.push(popped);
    }
}
*/
