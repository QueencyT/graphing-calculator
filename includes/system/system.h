#ifndef SYSTEM_H 
#define SYSTEM_H 
//#include <SFML/Graphics.hpp>
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/Graph/graph.h"
#include "../../includes/constants/constants.h"
#include "../../includes/system/system.h"

//in charge of updating graph --> takes in commands and tells graph to update accordingly 
class System{
    public: 
        //CONSTRUCTORS 
        System(); 
        System(graph_info* graphInfoVal); 

        void draw(sf::RenderWindow& window); //call's graph's draw method
        void clear(sf::RenderWindow& window); //clears the graph --> leaving only axis and tick marks 
        void update(int command); //updates graph according to the command (pan, zoom, etc)
        void pan_right(); //pans graph right --> right arrow key
        void pan_left(); //pans graph left --> left arrow key
        void zoom_in(); //zgraph zooms_in -->up arrow key
        void zoom_out(); //graph zooms out --> down arrow key 
    private:
        Graph graph; 
        graph_info* graphInfo; 
        double zoom_scale = 1.5;
}; 
#endif 