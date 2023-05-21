#pragma once 

#include "Team.hpp"
#include "Ninja.hpp"


constexpr int OLDSPEED = 8;
constexpr int OLDHITPOINTS = 150;
namespace ariel{

    class OldNinja: public Ninja{
        public: 
            OldNinja(const string& name, const Point location): Ninja(name,location,OLDSPEED,OLDHITPOINTS){}
    }; 

}