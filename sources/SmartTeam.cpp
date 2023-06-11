#include "SmartTeam.hpp"
#include <limits>

namespace ariel{
 
    void SmartTeam::attack(Team* enemy) {
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
        if (!this->getLeader()->isAlive()) {
            this->setLeader(nearestChar(this, this->getLeader()));

            // if all team members are dead
            if (this->getLeader() == nullptr) {
                return; 
            }
        }

        // Calculate the midpoint of the team's positions
        double sumX = 0.0;
        double sumY = 0.0;

        for (Character* member : this->getTeam()) {
            sumX += member->getLocation().get_x();
            sumY += member->getLocation().get_y();
        }

        double midpointX = sumX / this->getTeam().size();
        double midpointY = sumY / this->getTeam().size();

        Point a(midpointX, midpointY); 

        // Find the nearest enemy to the midpoint
        Character* nearestEnemy = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* enemyMember : enemy->getTeam()) {
            double distance = a.distance(enemyMember->getLocation());

            if (distance < minDistance) {
                minDistance = distance;
                nearestEnemy = enemyMember;
            }
        }

        // Cowboys attack first
        for (Character* attacker : this->getTeam()) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                // if cowboy is not alive, go to the next member of the team
                if (!cowboy->isAlive()) {
                    continue;
                }

                if (cowboy->hasboolets()) {
                    cowboy->shoot(nearestEnemy);
                } else {
                    cowboy->reload();
                }
            }
        }

        // Ninjas attack after cowboys
        for (Character* attacker : this->getTeam()) {
            if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
                // if ninja is not alive, go to the next member of the team
                if (!ninja->isAlive()) {
                    continue;
                }

                if (ninja->distance(nearestEnemy) < 1.0) {
                    ninja->slash(nearestEnemy);
                } else {
                    ninja->move(nearestEnemy);
                }
            }
        }
    }


}