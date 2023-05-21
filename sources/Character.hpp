#pragma once

#include <iostream>
#include "Point.hpp" 
using namespace std; 

namespace ariel{
    class Character
    {
    private:

        const string name; 
        int hit_points;
        Point location; 
        bool is_fighting; 

    protected:
        Character(const string &name, const Point location, const int hit_points ):name(name), location(location),hit_points(hit_points),is_fighting(false){}
        virtual ~Character() = default;

        
    public:
        

        bool isAlive(); // return if hit_point are left
        double distance(const Character*); // distance from different character
        void hit(int); // got hit. reduce life points 
        string getName(); 
        Point getLocation(); 
        string print();  
        int getHitPoints();
        bool getIsFighting(); 
        void setIsFighting(bool); 
    };

}



