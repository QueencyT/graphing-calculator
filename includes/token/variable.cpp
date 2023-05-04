#include "../../includes/token/variable.h"

Variable::Variable() : Integer("X"){
    setType(varType); 
}

Variable::Variable(string variable) : Integer(variable){
    setType(varType); 
}