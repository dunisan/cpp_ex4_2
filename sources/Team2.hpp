// #pragma once

#include "Team.hpp"

namespace ariel{

    class Team2: public Team{

        public: 
            Team2(Character* leader):Team(leader) {}
            void attack(Team* enemy) override;
            void print() override; 
    };
}