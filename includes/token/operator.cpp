#include <iostream>
#include "../../includes/token/operator.h"
#include "../../includes/token/token.h"
#include "assert.h"
#include <math.h>

using namespace std; 

//OPERATOR has type 3
Operator::Operator(string opVal) : Token(3, opVal){ //will replace later 
    op = opVal; 
    setPrecedence(); 
    set_number_of_args(2); 
}

void Operator::set_number_of_args(int numberOfArgsVal){
    numberOfArgs = numberOfArgsVal; 
}

int Operator::get_number_of_args(){
    return numberOfArgs; 
}

double Operator::decider(double left){
    double temp = 0.0; 
    return temp; 
}

double Operator::decider(double left, double right){ //might change later 
    char opr = op[0]; 
    switch(opr){
        case '^':
            return pow(left, right); 
        case '*': 
            return left * right; 
        case '/': 
            return left / right; 
        case '+':
            return left + right; 
        case '-':
            return left - right; 
        default:
            break; 
            return 0.0; 
            //cout<<"INVALID OPERATOR";  
            //assert(false); 
    }
}

void Operator::setPrecedence(){
    char opr = op[0]; 
    switch(opr){
        case ')': 
            precedence = 3; 
            break; 
        case '^': 
            precedence = 3;
        case '*': 
            precedence = 2; 
            break; 
        case '/': 
            precedence = 2; 
            break; 
        case '+':
            precedence = 1; 
            break; 
        case '-':
            precedence = 1; 
            break; 
        case '(':
            precedence = 0; 
            break; 
        default:
            precedence = 12; 
            //cout<<"INVALID OPERATOR";
            //assert(false); //invalid operand   
            break; 
    }
}

int Operator::getPrecedence(){
    return precedence; 
}

bool operator <= (const Operator& left, const Operator& right){
    return (left.precedence <= right.precedence); 
}