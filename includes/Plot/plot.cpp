#include "../../includes/Plot/plot.h"

Plot::Plot(){

}

Plot::Plot(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    userInput = User_Input(graphInfo); 
    infixEqu = userInput.parser(); //turns a string into tokens --> a method of the user input class 
    //cout<<"plot ctor fired\n"; 
}

Vector<Point> Plot::getPoints(){
    string equ = graphInfo->_equation;
    Vector<Point> points; 
    double xCoord = graphInfo->_domain.x; 
    double xMax = graphInfo->_domain.y; 
    double numPoints = graphInfo->numOfPoints;  
    double increment = 0.01;

    //move into constructor later 
    ShuntingYard shuntYard(infixEqu); 
    Queue<Token*> postFixEqu = shuntYard.postfix(); 
    RPN rpn(postFixEqu); 

    int index; 
    for(index = 0; xCoord <= xMax; index++, xCoord+=increment){ //x-coord should start at domain x 
        double yCoord = rpn.evaluation(xCoord); 
        Point newPoint(xCoord, yCoord); 
        points.push_back(newPoint); //(0,0), (1,1); --> supposedly 
    }
    graphInfo->numOfPoints = index; 
    return points; 
}
