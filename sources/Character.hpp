#pragma once

#include <iostream>
#include "Point.hpp" 
using namespace std; 

namespace ariel{
    class Character
    {
    private:

        const string name; // name of char
        int hit_points; // hit points that are left 
        Point location; // current location 
        bool is_fighting; // is in middle of a fight 

    public:
        // constructors and disructor and assignment 
        Character(const string &name, const Point location, const int hit_points ):name(name), location(location),hit_points(hit_points),is_fighting(false){}
        virtual ~Character() = default;
        Character(Character& character):name(character.name),location(character.location), hit_points(character.hit_points), is_fighting(character.is_fighting){};
        Character (Character&& character) noexcept: name(character.name),location(character.location), hit_points(character.hit_points), is_fighting(character.is_fighting){};
        
        Character& operator = (Character& other){
            if (this != &other) {
            }
            return other;
        }

        Character& operator=(Character&& other ) noexcept{
             if (this != &other) {
            }
            return other;
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



