#include "../../includes/text/text.h"



Text::Text(){
    //cout<<"no arg fired text\n";
}

Text::Text(graph_info* graphInfo, string str, sf::Vector2f pos){
    if(!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"failed to load font\n"; 
    }
 
    text.setFont(font); 
    text.setCharacterSize(20); 
    text.setStyle(sf::Text::Bold); 
    text.setFillColor(sf::Color::Magenta); 
    text.setPosition(100,100);
}

void Text::draw(sf::RenderWindow& tempWindow){
    text.setString("HELLLOOOOO"); 
    tempWindow.draw(text); 
}