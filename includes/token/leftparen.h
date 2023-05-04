#ifndef LEFT_PAREN 
#define LEFT_PAREN 

#include "../../includes/token/operator.h"

class LeftParen : public Operator{
    public: 
        LeftParen(); //hands off all work to token, just sets _token = "("
}; 
#endif 