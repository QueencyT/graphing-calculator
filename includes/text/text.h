#ifndef TEXT_H 
#define TEXT_H 

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../includes/graph_info/graph_info.h"

//no longer used 
class Text{
    public: 
        Text();
        Text(graph_info* graphInfo, string str, sf::Vector2f pos); 
        void draw(sf::RenderWindow& tempWindow); 
    private: 
        sf::Font font; 
        sf::Text text; 
}; 

#endif 