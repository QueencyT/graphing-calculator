#include "../../includes/point/point.h"

ostream& operator <<(ostream& outs, const Point& printMe){
    outs<<"("<<printMe.x<<","<<printMe.y<<")"<<" "; 
    return outs; 
}
