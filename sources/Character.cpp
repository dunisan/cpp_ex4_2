#include "Character.hpp"

namespace ariel{
        
        bool Character::isAlive(){
                if(this->hit_points>0)
                        return false;
                return true; 
        } 
        
        double Character::distance(const Character* other){
                return this->location.distance(other->location); 
        } 

        void Character::hit(int num_of_hits){
                this->hit_points -= num_of_hits; 
        }

        string Character::getName(){
                return this->name; 
        } 
        Point Character::getLocation(){
                return this->location;
        } 
        string Character::print(){
         
                return this->name + " " + std::to_string(this->hit_points) + " " + this->location.print();
        } 

        int Character::getHitPoints(){
                return this->hit_points;
        }   
        
}