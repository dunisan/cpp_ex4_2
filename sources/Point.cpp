#include "Point.hpp"
#include <math.h> 

namespace ariel{

    double Point::distance(const Point& other){
 
        return sqrt(pow(other._x - this->_x, 2) + pow(other._y - this->_y, 2) * 1.0);
    }

    std::string Point::print(){
        return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + ")";
    }
    
    
    
    Point Point::moveTowards(Point source, Point distination, double range){
        if(range<0){
            throw std::invalid_argument("no such as negitive distance!");
        }
        
        //double distance = sqrt(pow(distination._x - source._x, 2) + pow(distination._y - source._y, 2) * 1.0);
        double curr_dist = source.distance(distination);

        
        if (curr_dist <= range) {
        // If the distance is less than or equal to the range, return the destination point
            return distination;
        } else {
            double ratio = range / curr_dist;

            // Calculate the new coordinates based on the ratio
            double newX = source._x + (distination._x - source._x) * ratio;
            double newY = source._y + (distination._y - source._y) * ratio;

            // Return the new point with the updated coordinates
        return Point(newX, newY);
        }
    }

    double Point::get_x(){
        return _x; 
    }

    double Point::get_y(){
        return _y; 
    } 

    


}