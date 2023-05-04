#ifndef FUNCTION_H 
#define FUNCTION_H 
#include <iostream>
#include <cassert>
#include <cmath>

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"

using namespace std; 
//function will be type 2 
//make it inherit from operator

class Function : public Operator{
    public: 
        //Constructors 
        Function(); 
        Function(string function); 

        //decider functions that puts the args into a function (sin, cos, etc) and returns a double 
        virtual double decider(double arg); 
        virtual double decider(double arg1, double arg2); 

        //sets number of args the function has 
        virtual void setArgs(); 

        //gets the number of args
        int get_num_of_args(); 
    private: 
        const int funcType = 5; 
        int num_of_args; 
}; 

#endif 