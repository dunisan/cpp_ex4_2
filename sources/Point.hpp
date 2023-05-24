#pragma once 

#include <iostream> 

namespace ariel{

    class Point{ 
        private:
            double _x; 
            double _y; 

        public:
            // constructor 
            Point(const double x_axis, double y_axis): _x(x_axis), _y(y_axis){} 

            // class functions 
            double distance(const Point&); 
            std::string print(); 
            static Point moveTowards(Point ,Point, double); 
            
            // getters 
            double get_x(); 
            double get_y(); 
        

    };

}