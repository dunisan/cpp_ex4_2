#include "Team.hpp"
#include <limits>
#include <typeinfo>
#include <unordered_set>

namespace ariel{
    
    void Team::add(Character* fighter){
        // error checking 
        if(fighter->getIsFighting()){
            throw std::runtime_error("fighter is already fighting!"); 
        }
        if(this->team.size() == 10){
            throw std::runtime_error("More then 10 fighters in team!"); 
        }
        
        team.push_back(fighter); 
        fighter->setIsFighting(true); 
        
    }

    void Team::attack(Team* enemy){
        // error checking
        if(enemy == nullptr){
            throw std::invalid_argument("null object for team!"); 
        }        
        if(this == enemy){
            throw std::invalid_argument("Team attack itself"); 
        }
        if(enemy->stillAlive() == 0){
            throw std::runtime_error("can't attack a dead team"); 
        }

        // choose new leader if needed 
        if(!this->leader->isAlive()){
            this->leader = nearestChar(this, this->leader);

            // if all team are dead 
            if(this->leader == NULL){
                return; 
            }
        }

        // go over the team
        for (Character *attacker : this->team) {
            //1. if Attacker is not alive - go on to next member of the team.  
            if(!attacker->isAlive()){
                continue;
            }

            //2. find the nearest enemy to the teamleader
            Character* enemy_to_attack = nearestChar(enemy, this->leader);
            
            // enemy team is dead 
            if(enemy_to_attack == NULL){
                return; 
            } 

            //3. attack him the enemy - check if attacker is cowboy or ninja 
            if(Cowboy* cowboy = dynamic_cast<Cowboy *>(attacker)){
                
                if(cowboy->hasboolets()){
                    cowboy->shoot(enemy_to_attack); 
                }
                else{
                    cowboy->reload(); 
                }
            }else{

                Ninja* ninja = dynamic_cast<Ninja *>(attacker);

                if(ninja->distance(enemy_to_attack) < 1.0){
                    ninja->slash(enemy_to_attack);
                }
                else{
                    ninja->move(enemy_to_attack); 

                }
            }
        }
    }


    int Team::stillAlive(){

        int counter=0; 
        for (Character *attacker : this->team) {
            if(attacker->isAlive()){
                counter++; 
            }
        }
        return counter;
    }

    string Team::print(){
        std::string toprint; 
        for (Character *attacker : this->team) {
            toprint += attacker->print();
            toprint += '\n'; 
        }
        return toprint; 
    } 


    Character *Team::nearestChar(Team* team, Character* leader){
        // check that team nor leader are null 
        if(team == nullptr || leader == nullptr){
            throw std::invalid_argument("null pointers!"); 
        }
        
        double min_distance = std::numeric_limits<double>::max();
        double curr_distance;
        Character* nearest = NULL; 
        
        // loop over the team, and find the nearset char to leader. 
        for (Character *fighter : team->team) {
            if(fighter->isAlive()){
                curr_distance = fighter->distance(leader);
                if(curr_distance < min_distance){
                    min_distance = curr_distance; 
                    nearest = fighter; 
                }
            }
        }
        return nearest; 

    }

}

