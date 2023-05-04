#include "../../includes/Graph/graph.h"

Graph::Graph(){

}

Graph::Graph(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    plotter = Plot(graphInfo); 
    points = plotter.getPoints(); 
    numOfPoints = graphInfo->numOfPoints; 
}

void Graph::update(){
    Plot plotter = Plot(graphInfo); //replot 
    points = plotter.getPoints(); 
}


void Graph::draw(sf::RenderWindow& tempWindow){
    Coordinate_Translator translator(graphInfo); 
    sf::CircleShape circle; 
    circle.setFillColor(sf::Color(255,255,255)); //white maybe?
    circle.setRadius(1); 
    drawAxis(tempWindow);
    drawTicks(tempWindow);
    for(int i = 0; i < numOfPoints; i++){
        Point origPoint = points.at(i); 
        Point translatedPoint = translator.translate(origPoint); 
        circle.setPosition(sf::Vector2f(translatedPoint.x,translatedPoint.y)); 
        tempWindow.draw(circle); 
    }
}

void Graph::clear(sf::RenderWindow& tempWindow){
    drawAxis(tempWindow);
    drawTicks(tempWindow);
}


void Graph::drawAxis(sf::RenderWindow& tempWindow){
    Point origin(graphInfo->_origin.x, graphInfo->_origin.y); 
    sf::Vertex xAxis[] = {sf::Vector2f(0, origin.y),sf::Vector2f(graphInfo->_window_dimensions.x,origin.y)}; 
    sf::Vertex yAxis[] = {sf::Vector2f(origin.x, 0), sf::Vector2f(origin.x,  graphInfo->_window_dimensions.y)}; 
    xAxis->color.r = 135; 
    xAxis->color.g = 135; 
    
    yAxis->color.r = 135; 
    yAxis->color.g = 135; 

    tempWindow.draw(xAxis, 2, sf::Lines); 
    tempWindow.draw(yAxis, 2, sf::Lines); 
}

void Graph::drawTicks(sf::RenderWindow& tempWindow){
    int prevCord; 
    sf::RectangleShape tick; 
    tick.setSize(sf::Vector2f(3,7)); 
    tick.setRotation(0); 

    for(int xScrCord = 0; xScrCord <= graphInfo->_window_dimensions.x; xScrCord += graphInfo->_scale){
        tick.setPosition(xScrCord, graphInfo->_origin.y); 
        tempWindow.draw(tick); 
    }
}
