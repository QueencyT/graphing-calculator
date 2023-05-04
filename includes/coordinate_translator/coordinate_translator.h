#ifndef COORDINATE_TRANSLATOR 
#define COORDINATE_TRANSLATOR 
#include <cmath>
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/point/point.h"


//class in charge of translating regular coordinates into screen coordinates 
class Coordinate_Translator{
    public:
        Coordinate_Translator(graph_info* graphInfoVal); //constructor 
        Point translate(Point point); //translates real point to screen point and returns the translated point

    private: 
        graph_info* graphInfo; 

};
#endif 