#include "Team.hpp"
#include <limits>
#include <typeinfo>

namespace ariel{
 
    void Team::add(Character* fighter){
        if(this->team.capacity() < 10){
            team.push_back(fighter);  
        }
        else
            throw std::invalid_argument("More then 10 fighters in team!"); 
        
    }

    void Team::attack(Team* enemy){

        if(enemy == nullptr){
            throw std::invalid_argument("null object for teanm!"); 
        }
        
        if(this == enemy){
            throw std::invalid_argument("Team attack itself"); 
        }

        if(!this->leader->isAlive()){
            this->leader = nearestChar(this, this->leader); 
        }


        //enemy_to_attack = nearestEnemy();
        for (Character *charPtr : this->team) {
            
            // go over the cowboys

            // if(charPtr->isAlive() && enemy_to_attack.isAlive()){
            //     // if memeber is cowboy 
            //         // if has boolets  - shoot 
            //         // else - reload
                
            //     // if enemy is dead - choose new enemy 
            //     // if enemy team is dead - stop attacking  
            // }

        // anoter for loop to go ever the ninja in the tame way. 

        // neet to implement fund leader and choose enemy- instead - find nearest point from a specific source.. 

        
}

    // Nearesr char(team, char leader)


    }
    int Team::stillAlive(){return 0;}
    void Team::print(){} 


    Character *Team::nearestChar(Team* team, Character* leader){
        
        if(team == nullptr || leader == nullptr){
            throw std::invalid_argument("null pointers!"); 
        }
        
        double min_distance = std::numeric_limits<double>::max();
        double curr_distance;
        Character* nearest; 

        for (Character *fighter : team->team) {
            if(fighter->isAlive())
                curr_distance = fighter->distance(leader);
                if(curr_distance < min_distance){
                    min_distance = curr_distance; 
                    nearest = fighter; 
                }
        }

        return nearest; 

    }

}

