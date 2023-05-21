#pragma once 

#include <iostream> 

namespace ariel{

    class Point{ 
        private:
            double _x; 
            double _y; 

        public:
            Point(const double x_axis, double y_axis): _x(x_axis), _y(y_axis){}
            double distance(const Point&); 
            std::string print(); 
            static Point moveTowards(const Point& ,const Point& , double); 

            double get_x(); 
            double get_y(); 
        //    void set_x(const double); 
        //    void set_y(const double); 


    };

}