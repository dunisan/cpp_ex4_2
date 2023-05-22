#include "Team.hpp"
#include <limits>
#include <typeinfo>
#include <unordered_set>

namespace ariel{
 
    void Team::add(Character* fighter){
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

            if(this->leader == NULL){
                return; 
            }
        }

        

        
        for (Character *attacker : this->team) {
            // if Attacker is not alive - continue; 
            if(!attacker->isAlive()){
                continue;
            }
            // find the nearest enemy to the teamleader
            Character* enemy_to_attack = nearestChar(enemy, this->leader);
            if(enemy_to_attack == NULL){
                return; 
            } 

            // attack him!
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
        
        if(team == nullptr || leader == nullptr){
            throw std::invalid_argument("null pointers!"); 
        }
        
        double min_distance = std::numeric_limits<double>::max();
        double curr_distance;
        Character* nearest = NULL; 
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

