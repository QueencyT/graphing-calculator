#ifndef GRAPH_INFO_H 
#define GRAPH_INFO_H 
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std; 

//struct in charge of keeping track of info 
struct graph_info{
    //consturctors 
    graph_info(){}; 
    graph_info(string equ, sf::Vector2f dimensions, sf::Vector2f domain) : _equation(equ), _window_dimensions(dimensions), _domain(domain){};

    string _equation; 
    sf::Vector2f _window_dimensions; 
    sf::Vector2f _graph_dimensions = sf::Vector2f(_window_dimensions.x * 0.7, _window_dimensions.y); //graph dimensions 
    sf::Vector2f _domain; 
    double numOfPoints = 10;  
    double dist = fabs(_domain.x - _domain.y); //distance between the x and y domain --> - 3, -5 --> distance 2 
    double _scale = _graph_dimensions.x / dist; //how many screen cordinates equal one regular coordinate 
    sf::Vector2f _origin = sf::Vector2f(_graph_dimensions.x/2, _graph_dimensions.y/2); //origin of graph in screen coords 
}; 

#endif 