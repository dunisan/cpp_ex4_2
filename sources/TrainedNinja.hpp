#pragma once 

#include "Team.hpp"
#include "Ninja.hpp"


constexpr int TRAINEDSPEED = 8; 
constexpr int TRAINEDHITPOINTS = 150;



namespace ariel{

    class TrainedNinja: public Ninja{
        public: 
            TrainedNinja(const string& name, const Point location): Ninja(name,location,TRAINEDSPEED,TRAINEDHITPOINTS){}
    }; 

}