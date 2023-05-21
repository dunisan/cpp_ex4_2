#include "Ninja.hpp"

namespace ariel{
    void Ninja::move(Character* enemy){
        Point newpoint = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed); 
    }
    void Ninja::slash(Character* enemy){
        if(!this->isAlive()){
            throw std::runtime_error("Attacking with dead man");
        }
        if(this == enemy){
            throw std::runtime_error("no self harm");
        }
        if(!enemy->isAlive()){
            throw std::runtime_error("Attacking dead enemy");
        }

        if(this->distance(enemy)<1.0){
            enemy->hit(40); 
        }
    } 
    int Ninja::getSpeed(){
        return this->speed;
    } 
}