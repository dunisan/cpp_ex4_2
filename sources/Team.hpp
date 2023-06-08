#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

#include <vector>


namespace ariel{

    class Team{
        private:
            vector<Character*> team; 
            Character* leader; 

        public: 

            Team(Character* leader):leader(leader){
                if(leader->getIsFighting()){
                    throw std::runtime_error("leader is in a different fight");
                }
                team.push_back(leader); // push leader into team 
                leader->setIsFighting(true); // set isfighting -> true 
                
            }
            // (virtual to desruct the derived classes)
            virtual ~Team() {
                for (Character *fighter: team) {
                    delete fighter;
                }   
            }

            Team(const Team& other):leader(other.leader),team(other.team){}            

            Team& operator=(const Team& other) {
                if(this == &other){
                    return *this; 
                } 
                this->leader = other.leader; 
                this->team = other.team; 
                return *this;
            }
            Team(Team&& other) noexcept : leader(other.leader) {}
            
            Team& operator=(Team&& other) noexcept {
                if(this == &other){
                    return *this; 
                }
                return other;
            }

        
            void add(Character*); // add character to team 
            virtual void attack(Team*); // atack another team. 
            int stillAlive(); // team is still alive
            virtual string print(); // print the team 
            Character *getLeader(){return this->leader;}; // get leader of team 
            void setLeader(Character* leader){this->leader = leader;} // set new leader for team 
            vector<Character*> getTeam(){return team;}  // get team
            static Character* nearestChar(Team*, Character*);  // get nearest character from team to character that is given
            
    };

}