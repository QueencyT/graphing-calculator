#ifndef RIGHT_PAREN_H 
#define RIGHT_PAREN_H 

#include "../../includes/token/operator.h"

class RightParen : public Operator{
    public: 
        RightParen(); //hands off most work to token, just sets _token as ")"
}; 
#endif