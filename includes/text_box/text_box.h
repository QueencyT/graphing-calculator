#ifndef TEXT_BOX_H 
#define TEXT_BOX_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../includes/graph_info/graph_info.h"

using namespace std; 

//text box class --> in charge of any text that is in a box
class Text_Box{
    public: 
        //Constructors 
        Text_Box(); 
        Text_Box(graph_info* graphInfoVal, string str); 

        void draw(sf::RenderWindow& tempWindow, string someStr); //draws textbox to screen 
        bool onClicked(double x, double y); //checks if the textbox has been clicked --> returns true if yes 


        //getter and setter methods that replicate sfml's getters and setters 
        sf::Vector2f getPosition(); 
        sf::Vector2f getSize(); 
        void setColor(sf::Color color); 
        void setOutlineColor(sf::Color color); 
        void setPosition(double x, double y); 
        void setSize(sf::Vector2f size); 
    
    private: 
        sf::RectangleShape textBox; 
        sf::RectangleShape backgroundBox; 
        graph_info* graphInfo; 
}; 
#endif 