#include "Team2.hpp"

namespace ariel{
 
    void Team2::attack(Team* enemy){
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
        if(!this->getLeader()->isAlive()){
            this->setLeader(nearestChar(this, this->getLeader())); 

            if(this->getLeader() == NULL){
                return; 
            }
        }

        

        
        for (Character *attacker : this->getTeam()) {
            // if Attacker is not alive - continue; 
            if(!attacker->isAlive()){
                continue;
            }
            // find the nearest enemy to the teamleader
            Character* enemy_to_attack = nearestChar(enemy, this->getLeader());
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

}