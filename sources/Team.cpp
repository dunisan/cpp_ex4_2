#include "Team.hpp"
#include <limits>
#include <typeinfo>
#include <unordered_set>

namespace ariel{
 
    void Team::add(Character* fighter){
        if(this->team.size() < 10){
            team.push_back(fighter);  
        }
        else
            throw std::runtime_error("More then 10 fighters in team!"); 
        
    }

    void Team::attack(Team* enemy){


        // error checking
        if(enemy == nullptr){
            throw std::invalid_argument("null object for teanm!"); 
        }
        
        if(this == enemy){
            throw std::invalid_argument("Team attack itself"); 
        }


        // choose new leader if needed 
        if(!this->leader->isAlive()){
            this->leader = nearestChar(this, this->leader);
        }

        
        for (Character *attacker : this->team) {
            
            // if Attacker is not alive - continue; 
            if(!attacker->isAlive()){
                continue;
            }
            

            // find the nearest enemy to the teamleader
            Character* enemy_to_attack = nearestChar(enemy, enemy->getLeader()); 

            // attack him! 

            if(typeid(attacker)== typeid(Cowboy)){
                            std::cout << "!!!!!!!!!!!111"<< std::endl;

                Cowboy* cowboy = dynamic_cast<Cowboy *>(attacker);

                if(cowboy->hasboolets()){
                    cowboy->shoot(enemy_to_attack); 
                }
                else{
                    cowboy->reload(); 
                }
            }else{
                std::cout << "333333333333"<< std::endl;

                Ninja* ninja = dynamic_cast<Ninja *>(attacker);

                if(ninja->distance(enemy_to_attack) < 1.0){
                    ninja->slash(enemy_to_attack);
                }
                else{
                    ninja->move(enemy_to_attack); 
                }
            }
                                std::cout << "22222222"<< std::endl;

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

