#include "../../includes/utilities/utilities.h"

Utility::Utility(){

}

Utility::Utility(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    clearAll.setColor(sf::Color::Blue); 
    clearAll.setSize(sf::Vector2f(120,100)); 
    clearAll.setPosition(graphInfo->_graph_dimensions.x + 20, graphInfo->_graph_dimensions.y * 0.15);
    clearAll.setOutlineColor(sf::Color::White); 
}


Text_Box Utility::getClear(){
    return clearAll; 
}

void Utility::draw(sf::RenderWindow& tempWindow){
    clearAll.draw(tempWindow, "clear"); 
}

