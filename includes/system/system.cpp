#include "../../includes/system/system.h"

System::System(){

}

System::System(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    graph = Graph(graphInfo); 
}

void System::update(int command){
    switch(command){
        case CMD_NO_ACTION: 
            break; 
        case CMD_ZOOM_IN: 
            zoom_in();
            break; 
        case CMD_ZOOM_OUT: 
            zoom_out(); 
            break; 
        case CMD_PAN_RIGHT: 
            pan_right(); 
            break; 
        case CMD_PAN_LEFT:
            pan_left();  
            break; 
        case CMD_REDRAW: 
            graph.update(); 
            break;
        default: 
            cout<<"ERROR: INVALID COMMAND IN SYSTEM UPDATE\n"; 
            cout<<"COMMAND: "<<command<<endl; 
            //assert(false);
    }
}

void System::zoom_in(){ 
    graphInfo->_scale *= zoom_scale; 
    graph.update();
}

void System::zoom_out(){
    graphInfo->_scale /= zoom_scale; 
    graph.update(); 
}


void System::pan_right(){
    graphInfo->_origin.x -= (graphInfo->_scale); 
    graphInfo->_domain.x+=1; 
    graphInfo->_domain.y+=1; 
    Point domain(graphInfo->_domain.x, graphInfo->_domain.y);
    Point origin(graphInfo->_origin.x, graphInfo->_origin.y); 
    graph.update(); 
}

void System::pan_left(){
    graphInfo->_origin.x += (graphInfo->_scale); 
    graphInfo->_domain.x-=1; 
    graphInfo->_domain.y-=1; 
    graph.update(); 
}

void System::clear(sf::RenderWindow& window){
    graph.clear(window);
}

void System::draw(sf::RenderWindow& window){
    graph.draw(window); 
}