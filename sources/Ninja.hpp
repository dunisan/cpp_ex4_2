#pragma once 

#include "Character.hpp"
#include "Point.hpp"


namespace ariel{

    class Ninja: public Character{
        private:

            const int speed; 

        public: 
            Ninja(const string& name, const Point location, const int hit_points, int speed):Character(name,location,hit_points), speed(speed){}
            void move(Character*);
            void slash(Character*); 

            int getSpeed(); 

    }; 

}