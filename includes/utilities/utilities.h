#ifndef UTILITES_H 
#define UTILITES_H 

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../includes/text_box/text_box.h"
#include "../../includes/graph_info/graph_info.h"


//class for possible future utilities --> clear, polar, zoom in buttons etc

class Utility : public Text_Box{
    public: 
        //basic constructors 
        Utility(); 
        Utility(graph_info* graphInfoVal); 
        //gets the clear button
        Text_Box getClear();
        //draws to screen 
        void draw(sf::RenderWindow& tempWindow); 
    private: 
        graph_info* graphInfo; 
        Text_Box clearAll; 
};

#endif