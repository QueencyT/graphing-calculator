#include "../../includes/token/integer.h"
#include "../../includes/token/token.h"

Integer::Integer(double someNum) : Token(1, to_string(someNum)){ 
}

Integer::Integer(string someNum) : Token(1, someNum){
    
}
