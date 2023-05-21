#pragma once 

#include "Point.hpp"
#include "Character.hpp"

constexpr int COWBOYBULLETS = 6;
constexpr int COWBOYHITPOINTS = 110;
namespace ariel{

    class Cowboy: public Character{
        private:
            int num_of_bullets;

        public: 
            Cowboy(const string& name, const Point location):Character(name,location, COWBOYHITPOINTS), num_of_bullets(COWBOYBULLETS){}
            void shoot(Character*); 
            bool hasboolets(); 
            void reload(); 

            int getNumOfBullets(); 
    }; 

}