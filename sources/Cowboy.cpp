#include "Cowboy.hpp"

namespace ariel{
    void Cowboy::shoot(Character* enemy){
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
        this->num_of_bullets = 6;
    } 

    int Cowboy::getNumOfBullets(){
        return this->num_of_bullets;
    } 


}