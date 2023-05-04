#ifndef SIDEBAR_H 
#define SIDEBAR_H 
#include <SFML/Graphics.hpp>
#include "../../includes/graph_info/graph_info.h"

//class in charge of sidebar 
class Sidebar{
    public: 
        //CONSTRUCTORS
        Sidebar(); 
        Sidebar(graph_info* graphInfoVal); 
        void draw(sf::RenderWindow& tempWindow); //draws the sidebar to the window
    private: 
        sf::RectangleShape sidebarRect; 
        sf::Font font; 
        graph_info* graphInfo;
        int width; 
};

#endif 