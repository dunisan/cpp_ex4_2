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
    public:

        // this part i got a little help from web - up to the isAlive() function  
        Character(const string &name, const Point location, const int hit_points ):name(name), location(location),hit_points(hit_points),is_fighting(false){}
        virtual ~Character() = default;
        Character(Character& character):name(character.name),location(character.location), hit_points(character.hit_points), is_fighting(character.is_fighting){};
        Character (Character&& character) noexcept: name(character.name),location(character.location), hit_points(character.hit_points), is_fighting(character.is_fighting){};
        
        Character& operator = (const Character& other){
            if (this != &other) {
            }
            return *this;
        }
        Character& operator=(Character&& other ) noexcept{
             if (this != &other) {
            }
            return *this;
        } 


        // character methods 
        
        bool isAlive(); // return if hit_point are left
        double distance(const Character*); // distance from different character
        void hit(int); // got hit. reduce life points ]

        // getters and setters 
        string getName(); 
        Point getLocation(); 
        string print();  
        int getHitPoints(); 
        bool getIsFighting(); 
        void setIsFighting(bool); 
        void setLocation(Point); 
    };

}



