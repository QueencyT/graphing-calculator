#include "../../includes/text_box/text_box.h"

Text_Box::Text_Box(){

}

Text_Box::Text_Box(graph_info* graphInfoVal, string str){
    graphInfo = graphInfoVal;

    //text box
    double width = graphInfo->_window_dimensions.x - graphInfo->_graph_dimensions.x - 40; //40 for padding
    textBox.setSize(sf::Vector2f(width,graphInfo->_window_dimensions.y * 0.08)); 
    textBox.setPosition(graphInfo->_graph_dimensions.x + graphInfo->_graph_dimensions.x * 0.015, graphInfo->_graph_dimensions.y * 0.05); 
    textBox.setFillColor(sf::Color(0,0,0)); 
    textBox.setOutlineThickness(3); 
    textBox.setOutlineColor(sf::Color::Blue);
    //
}

void Text_Box::setPosition(double x, double y){
    textBox.setPosition(x,y); 
    textBox.setPosition(x,y); 
}

void Text_Box::setSize(sf::Vector2f size){
    textBox.setSize(size); 
    backgroundBox.setSize(size); 
}

void Text_Box::setColor(sf::Color color){
    textBox.setFillColor(color); 
}

void Text_Box::setOutlineColor(sf::Color color){
    backgroundBox.setOutlineColor(color); 
}

sf::Vector2f Text_Box::getPosition(){
    return textBox.getPosition(); 
}

sf::Vector2f Text_Box::getSize(){
    return textBox.getSize(); 
}

bool Text_Box::onClicked(double x, double y){
    return (x > textBox.getPosition().x && (y > textBox.getPosition().y && y < textBox.getPosition().y + textBox.getSize().y)); 
}

void Text_Box::draw(sf::RenderWindow& tempWindow, string someStr){
    sf::Font font; 
    sf::Text text; 
    if(!font.loadFromFile("munro.ttf")){
        cout<<"failed to load font\n"; 
    }

    text.setFont(font); 
    text.setCharacterSize(50); 
    text.setStyle(sf::Text::Bold); 
    text.setFillColor(sf::Color::White); 
    text.setPosition(textBox.getPosition().x + 10, textBox.getPosition().y + 10);
    text.setString(someStr);
    
    tempWindow.draw(textBox);
    tempWindow.draw(text);   
}