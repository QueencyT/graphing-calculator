#include "../../includes/token/function.h"


//num of args is just one --> 1
double Function::decider(double arg){
    string func = getToken(); 

    if(func == "sin"){
        return sin(arg); 
    }
    else if(func == "cos"){
        return cos(arg); 
    }
    else if(func == "tan"){
        return tan(arg); 
    }
    else if(func == "cot"){
        return (1.0/tan(arg)); 
    }
    else if(func == "csc"){
        return (1.0/sin(arg)); 
    }
    else if(func == "sec"){
        return (1.0/cos(arg)); 
    }
    else{
        cout<<"INVALID FUNCTION\n"; 
        assert(false); 
    }
}

double Function::decider(double arg1, double arg2){
    return log2(arg2)/log2(arg1); 
}

void Function::setArgs(){
    string func = getToken(); 
    if(func == "sin"){
        set_number_of_args(1); 
    }
    else if(func == "cos"){
        set_number_of_args(1); 
    }
    else if(func == "tan"){
        set_number_of_args(1); 
    }
    else if(func == "cot"){
        set_number_of_args(1); 
    }
    else if(func == "csc"){
        set_number_of_args(1); 
    }
    else if(func == "sec"){
        set_number_of_args(1); 
    }
    else if(func == "log"){
        set_number_of_args(2); 
    }
    else{
        cout<<"INVALID FUNCTION\n"; 
        assert(false); 
    }
}

int Function::get_num_of_args(){
    return num_of_args; 
}
Function::Function() : Operator("x"){
    setArgs(); 
}

Function::Function(string function) : Operator(function){
    setArgs(); 
}