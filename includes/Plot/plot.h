#ifndef PLOT_H 
#define PLOT_H 

#include<iostream>

#include "../../includes/graph_info/graph_info.h"
#include "../../includes/vector_class/vector_class.h"
#include "../../includes/point/point.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/function.h"
#include "../../includes/token/token.h"
#include "../../includes/token/variable.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/user_input/user_input.h"

using namespace std; 

//class in charge of finding the points of the equation according to the domain
class Plot{
    public: 
        //constructors 
        Plot();
        Plot(graph_info* graphInfo); 
        Vector<Point> getPoints(); //returns a vector of points from the equation within the domain
    private: 
        graph_info* graphInfo; 
        User_Input userInput;
        Queue<Token*> infixEqu;  
}; 

#endif