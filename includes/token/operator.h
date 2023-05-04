#ifndef OPERATOR_H 
#define OPERATOR_H 

#include <iostream>
#include "../../includes/token/token.h"

using namespace std; 

class Operator : public Token{
    public: 
        //Constructor
        Operator(string opVal); 

        //Decider functions --> takes in arguments, does a certain mathematical operation on them and returns double 
        virtual double decider(double left, double right); //make virtual 
        virtual double decider(double left); 

        void set_number_of_args(int numberOfArgsVal); //sets the number of arguments the operator has 
        int get_number_of_args(); //gets the number of args
        int getPrecedence(); //gets the precednece of the operator 
        friend bool operator <= (const Operator& left, const Operator& right); //decides if an operator has lower precedence or not 
        
    private:
        string op; 
        int precedence; 
        void setPrecedence(); 
        int numberOfArgs; 
        
}; 

#endif 