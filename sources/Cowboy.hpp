#pragma once 

#include "Point.hpp"
#include "Character.hpp"

constexpr int COWBOYBULLETS = 6; // indicate that a  object can be evaluated at compile time.
constexpr int COWBOYHITPOINTS = 110;
namespace ariel{

    class Cowboy: public Character{
        private:
            int num_of_bullets; // num of bullets left 

        public: 
            Cowboy(const string& name, const Point location):Character(name,location, COWBOYHITPOINTS), num_of_bullets(COWBOYBULLETS){}
            
            // class methods 
            void shoot(Character*); 
            bool hasboolets(); 
            void reload(); 

            // getter
            int getNumOfBullets(); 
    }; 

}