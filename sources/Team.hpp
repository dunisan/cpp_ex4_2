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

            Team(Character* leader):leader(leader){}
             virtual ~Team() {}
            Team(const Team& other):leader(other.leader){}            

            Team& operator=(const Team& other) {
                if(this == &other){
                    return *this; 
                } 
                return *this;
            }
            Team(Team&& other) noexcept : leader(other.leader) {}

            Team& operator=(Team&& other) noexcept {
                if(this == &other){
                    return *this; 
                }
                return *this;
            }


        
            void add(Character*); 
            virtual void attack(Team*);
            int stillAlive(); 
            virtual void print();
            Character *getLeader(){return this->leader;}; 

            static Character* nearestChar(Team*, Character*); 


    };

}