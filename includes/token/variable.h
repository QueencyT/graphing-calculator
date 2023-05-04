#ifndef VARIABLE_H 
#define VARIABLE_H 

#include "../../includes/token/integer.h"

using namespace std; 
//class that handles x variables 
class Variable : public Integer{
    public: 
        //constructors 
        Variable(); 
        Variable(string variable); 
    private: 
        const int varType = 4; 
}; 
#endif 