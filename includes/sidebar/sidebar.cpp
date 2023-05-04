#include "../../includes/sidebar/sidebar.h"

Sidebar::Sidebar(){
    
}

Sidebar::Sidebar(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    width = graphInfo->_window_dimensions.x - graphInfo->_graph_dimensions.x; 
    sidebarRect.setFillColor(sf::Color(207,207,207)); 
    sidebarRect.setPosition(sf::Vector2f(graphInfo->_graph_dimensions.x,0)); 
    sidebarRect.setSize(sf::Vector2f(width, graphInfo->_window_dimensions.y)); 
}

void Sidebar::draw(sf::RenderWindow& tempWindow){
    tempWindow.draw(sidebarRect); 
}
