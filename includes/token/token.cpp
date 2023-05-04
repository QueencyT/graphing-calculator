#include <iostream>
#include "../../includes/token/token.h"

using namespace std; 

Token::Token(){
    type = -1;
    _token = ""; 
}

Token::Token(int typeVal, string tokVal){
    type = typeVal; 
    _token = tokVal; 
}

int Token::getType(){
    return type; 
}

void Token::setType(int typeVal){
    type = typeVal;
}

string Token::getToken(){
    return _token; 
}
