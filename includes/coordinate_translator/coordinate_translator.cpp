#include "../../includes/coordinate_translator/coordinate_translator.h"
Coordinate_Translator::Coordinate_Translator(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
}

Point Coordinate_Translator::translate(Point point){
    sf::Vector2f org = graphInfo->_origin; 
    double scale = graphInfo->_scale;
    Point translatedPoint(org.x + (point.x * scale), org.y - (point.y * scale));  
    return translatedPoint; 
}
