#include "Cowboy.hpp"

namespace ariel{
    void Cowboy::shoot(Character* enemy){

        if(!this->isAlive()){
            throw std::runtime_error("Attacking with dead man");
        }
        if(this == enemy){
            throw std::runtime_error("no self harm");
        }
        if(!enemy->isAlive()){
            throw std::runtime_error("Attacking dead man");
        }
    
        if(this->num_of_bullets > 0){
            enemy->hit(10);  
            this->num_of_bullets--; 
            return;
        }
    } 
    
    bool Cowboy::hasboolets(){
        if(this->num_of_bullets>0){
            return true; 
        }
        return false;
    }
    void Cowboy::reload(){
        if(!this->isAlive()){
            throw std::runtime_error("Dead cowboy can't reload");
        }
        this->num_of_bullets = 6;
    } 

    int Cowboy::getNumOfBullets(){
        return this->num_of_bullets;
    } 


}