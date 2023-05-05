#include "../../includes/user_input/user_input.h"


User_Input::User_Input(){
    
}

User_Input::User_Input(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
}

User_Input::User_Input(graph_info* graphInfoVal, Graph_History* graphHistoryVal){
    graphInfo = graphInfoVal;
    graphHistory = graphHistoryVal; 
}

void User_Input::setUserInput(string newEqu){
    graphInfo->_equation = newEqu; 
    graphHistory->addEquation(newEqu); 
}

//get user input 
//set user input 
//function to return past input 

Queue<Token*> User_Input::parser(){
    const char* equ = graphInfo->_equation.c_str(); 
    const string delims[] = {"^","(",")","/","+","-","*","sin","cos","cot","tan","csc","sec","x"}; 
    int size_used = 14; 
    string token = ""; 

    while(*equ != NULL){
        token += *equ; 
        typeSetter(infix, token); 
        equ++; 
    }
    return infix; 
}

void User_Input::typeSetter(Queue<Token*>& infix, string& someStr){
    if(someStr == "sin" || someStr == "cos" || someStr == "tan" || someStr == "csc" || someStr == "sec" || someStr == "cot" || someStr == "log"){
        infix.push(new Function(someStr)); 
        cout<<someStr<<endl; 
        someStr =""; 
    }
    else if(someStr == "^" || someStr == "/" || someStr == "*" || someStr == "+" || someStr == "-"){
        infix.push(new Operator(someStr));
        cout<<someStr<<endl;
        someStr = ""; 
    }
    else if(someStr == "("){
        infix.push(new LeftParen());
        cout<<someStr<<endl;
        someStr = "";  
    }
    else if(someStr == ")"){
        infix.push(new RightParen());
        cout<<someStr<<endl;
        someStr = ""; 
    }
    else if(someStr == "x"){
        infix.push(new Variable(someStr));
        cout<<someStr<<endl;
        someStr= "";  
    }
    else if(isdigit(someStr[0])){
        infix.push(new Integer(someStr)); 
        cout<<someStr<<endl;
        someStr =""; 
    }
}
