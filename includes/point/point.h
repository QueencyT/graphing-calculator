#ifndef POINT_H 
#define POINT_H 

#include<iostream> 
using namespace std; 

//a struct that groups x and y together 
struct Point{
    //constructors 
    Point() : x(0),y(0){}; 
    Point(double xVal, double yVal) : x(xVal), y(yVal){}; 
    double x;
    double y; 
    friend ostream& operator <<(ostream& outs, const Point& printMe); //just something to help print out points 
}; 

#endif