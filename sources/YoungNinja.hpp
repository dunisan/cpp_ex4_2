#pragma once 

#include "Team.hpp"


constexpr int YOUNGSPEED = 14;
constexpr int YOUNGHITPOINTS = 100;


namespace ariel{

    class YoungNinja: public Ninja{
        public: 
            YoungNinja(const string& name, const Point location): Ninja(name,location,YOUNGSPEED,YOUNGHITPOINTS){}
    }; 

}