#include "Ninja.hpp"

namespace ariel{
    void Ninja::move(Character* enemy){
        Point newpoint = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed); 
    }
    void Ninja::slash(Character* enemy){

        if(this->distance(enemy)<1){
            enemy->hit(40); 
        }
    } 
    int Ninja::getSpeed(){
        return this->speed;
    } 
}