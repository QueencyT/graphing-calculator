#ifndef GRAPH_H 
#define GRAPH_H 

#include <SFML/Graphics.hpp>
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/Plot/plot.h"
#include "../../includes/point/point.h"
#include "../../includes/vector_class/vector_class.h"
#include "../../includes/coordinate_translator/coordinate_translator.h"

//class in charge of graph --> drawing 
class Graph{
    public: 
        //constructors 
        Graph(); 
        Graph(graph_info* graph_info); 
        void update(); //updates the graph --> basically replotting graph (called when zooming, panning or redrawing)
        void draw(sf::RenderWindow& tempWindow); //draws graph to the window
        void clear(sf::RenderWindow& tempWindow); //clears graph (leaves only tick marks and axis)

    private: 
        graph_info* graphInfo; 
        Plot plotter;
        Vector<Point> points; //keeps track of the points earned from plot class 
        int numOfPoints;  
        void drawAxis(sf::RenderWindow& tempWindow); //private method to draws axis
        void drawTicks(sf::RenderWindow& tempWindow); //private method to draw the tick marks 
}; 
#endif 