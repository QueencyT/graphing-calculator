#ifndef INTEGER_H 
#define INTEGER_H 

#include "../../includes/token/token.h"

//Integers are type 1
class Integer : public Token{
    public: 
        //constructors --> just basically hand off all work to token
        Integer(double someNum); 
        Integer(string someNum); 
}; 

#endif 