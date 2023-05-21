#include "Team2.hpp"

namespace ariel{
 
    void Team2::attack(Team* enemy){
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
                Cowboy* cowboy = dynamic_cast<Cowboy *>(attacker);

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
    string Team2::print(){return " ";} 

}