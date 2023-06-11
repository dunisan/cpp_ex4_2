#include "sources/Team.hpp"
#include <iostream>
#include <sstream>
#include "doctest.h"

#include <limits>
#include <vector>

using namespace ariel;
using namespace std; 


TEST_SUITE("POINT") {
    TEST_CASE("constructor") {
        Point a(2,4.5); 

        CHECK_EQ(a.get_x(),2);
        CHECK_EQ(a.get_y(),4.5);  
    }

    TEST_CASE("distance") {

        SUBCASE("distance"){
            Point a(0,0); 
            Point b(5,0);
            Point c(0,3); 

            CHECK_EQ(a.distance(b), 5); 
            CHECK_EQ(a.distance(c), 3); 

        }
    }

    TEST_CASE("moveTowards") {
        
        SUBCASE("close"){

            Point source(0,3); 
            Point dest(0,6); 
            double distance = 10; 
            Point endpoint(0,0); 
            endpoint = source.moveTowards(source, dest, distance);
            CHECK_EQ(endpoint.get_x(), 0);
            CHECK_EQ(endpoint.get_y(), 6);
            endpoint = source.moveTowards(dest, source, distance);
            CHECK_EQ(endpoint.get_x(), 0);
            CHECK_EQ(endpoint.get_y(), 3);

        }
    }

}

TEST_SUITE("CHARACTER") {
    TEST_CASE("constructor") {
        Point location(1, 1);
        Character chara("ploni", location, 100);

        CHECK_EQ(chara.getName(), "ploni");
        CHECK_EQ(chara.getLocation().get_x(), 1);
        CHECK_EQ(chara.getLocation().get_y(), 1);
        CHECK_EQ(chara.getHitPoints(), 100);
        CHECK_EQ(chara.getIsFighting(), false);
    }

    TEST_CASE("isAlive") {
        Point location(0, 0);
        Character chara("ploni", location, 100);

        SUBCASE("alive") {
            CHECK_EQ(chara.isAlive(), true);
        }

        SUBCASE("dead") {
            chara.hit(100); 
            CHECK_EQ(chara.isAlive(), false);
        }
    }

    TEST_CASE("distance") {
        Point a(0, 0);
        Point b(0, 2);
        Character charaA("ploni", a, 100);
        Character charaB("almoni", b, 100);

        CHECK_EQ(charaA.distance(&charaB), 2);
    }

    TEST_CASE("hit") {
        Point location(0, 0);
        Character chara("ploni", location, 100);

        chara.hit(50);

        CHECK_EQ(chara.getHitPoints(), 50);
    }

    TEST_CASE("getters and setters") {
        Point location(0, 0);
        Character chara("John", location, 100);

        CHECK_EQ(chara.getName(), "John");
        CHECK_EQ(chara.getLocation().get_x(), 0);
        CHECK_EQ(chara.getLocation().get_y(), 0);
        CHECK_EQ(chara.getHitPoints(), 100);
        CHECK_EQ(chara.getIsFighting(), false);

        Point newLocation(2, 2);
        chara.setLocation(newLocation);
        chara.setIsFighting(true);

        CHECK_EQ(chara.getLocation().get_x(), 2);
        CHECK_EQ(chara.getLocation().get_y(), 2);
        CHECK_EQ(chara.getIsFighting(), true);
    }
}

TEST_SUITE("CHARACTER - cowboy") {

    
    TEST_CASE("constructor") {

        Cowboy a("Ploni", Point(1,1));

        CHECK_EQ(a.getHitPoints(), 110); 
        CHECK_EQ(a.getNumOfBullets(), 6); 
        CHECK_EQ(a.getName() , "Ploni");  
        CHECK_EQ(a.getLocation().get_x() , 1);  
        CHECK_EQ(a.getLocation().get_y() , 1);  
        CHECK_EQ(a.getIsFighting(), false);

    }

    TEST_CASE("shoot") {
        Point location(0, 0);
        Cowboy a("ploni", location);

        SUBCASE("shoot with bullets left") {
            Character b("Enemy", location, 100);
            a.shoot(&b);

            CHECK_EQ(a.getNumOfBullets(), 5);
            CHECK_EQ(b.getHitPoints(), 90);
        }

        SUBCASE("shoot with no bullets left") {
            Character b("Enemy", location, 90);
            a.shoot(&b);
            a.shoot(&b); 
            a.shoot(&b);
            a.shoot(&b);
            a.shoot(&b);
            a.shoot(&b);
            CHECK_EQ(a.getNumOfBullets(), 0);
            CHECK_EQ(b.getHitPoints(), 30);
        }
    }

    TEST_CASE("hasboolets") {
        Point location(0, 0);
        Cowboy cowboy("John", location);

        SUBCASE("has bullets") {
            CHECK_EQ(cowboy.hasboolets(), true);
        }

        SUBCASE("no bullets") {
            Character b("Enemy", Point(1,1), 100);
            cowboy.shoot(&b); 
            cowboy.shoot(&b); 
            cowboy.shoot(&b); 
            cowboy.shoot(&b); 
            cowboy.shoot(&b); 
            cowboy.shoot(&b); 

            CHECK_EQ(cowboy.hasboolets(), false);
        }
    }

    TEST_CASE("reload") {
        Cowboy a("Ploni", Point(1,1));
        Cowboy c("Almoni", Point(2,1));
        Cowboy* b = &c; 
        for (int i = 0; i < 6; i++)
        {
            a.shoot(b);
        }
        
        a.reload(); 

        CHECK_EQ(a.getNumOfBullets(), 6); 
    }
    

}

TEST_SUITE("CHARACTER - ninja") {
    TEST_CASE("constructor") {
        YoungNinja a("Almoni", Point(2,2)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        TrainedNinja c("Shalmoni", Point(3,3)); // 150, 8

        CHECK_EQ(a.getName(), "Almoni");
        CHECK_EQ(b.getName(), "Ploni");
        CHECK_EQ(c.getName(), "Shalmoni");

        CHECK_EQ(a.getSpeed(), 14);
        CHECK_EQ(b.getSpeed(), 8);
        CHECK_EQ(c.getSpeed(),12);
        CHECK_EQ(a.getHitPoints(), 100);
        CHECK_EQ(b.getHitPoints(), 150);
        CHECK_EQ(c.getHitPoints(), 120);
    }

    TEST_CASE("move") {
        YoungNinja a("Almoni", Point(0,0)); //100,14
        OldNinja b("Ploni", Point(0,20));// 120,12
        TrainedNinja c("Shalmoni", Point(0,6)); // 150, 8

        a.move(&b); // 0,14
        b.move(&c); // 0,12
        c.move(&a); // 0,14

        
        CHECK_EQ(a.getLocation().get_x(), 0); 
        CHECK_EQ(a.getLocation().get_y(), 14); 
        CHECK_EQ(b.getLocation().get_x(), 0); 
        CHECK_EQ(b.getLocation().get_y(), 12); 
        CHECK_EQ(c.getLocation().get_x(), 0); 
        CHECK_EQ(c.getLocation().get_y(), 14); 

    }

    TEST_CASE("slash") {
        YoungNinja a("Almoni", Point(3,3)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        Cowboy c("Hevroni", Point(1,1.1)); 
        Cowboy* d = &c;

        a.slash(&c);
        CHECK_EQ(c.getHitPoints(), 110); 
        b.slash(&c); 
        CHECK_EQ(c.getHitPoints(), 70); 


    }
}
TEST_SUITE("TEAM") {
    TEST_CASE("constructor") {
        Cowboy *a = new Cowboy("ploni", Point(0,0));
        Team team(a);

        CHECK_EQ(team.getLeader()->getName(), "ploni");
        CHECK_EQ(team.stillAlive(), 1);
    }

    TEST_CASE("add") {
        Cowboy *c = new Cowboy("a", Point(0,4));
        Team team(c);

        YoungNinja *yn = new YoungNinja("A", Point(0,10));
        OldNinja *on = new OldNinja("A", Point(0,20));
        TrainedNinja *tn = new TrainedNinja("A", Point(0,30));
        team.add(yn);
        team.add(on);
        team.add(tn);
        CHECK_EQ(team.getTeam().size(), 4);
    }

    TEST_CASE("attack") {
        Cowboy *c = new Cowboy("a", Point(0,4));
        Team teamA(c);

        
        YoungNinja *yn = new YoungNinja("A", Point(0,10));
        OldNinja *on = new OldNinja("A", Point(0,20));
        TrainedNinja *tn = new TrainedNinja("A", Point(0,30));
        teamA.add(yn);
        teamA.add(on);
        teamA.add(tn);

        Cowboy *cb = new Cowboy("a", Point(0,0));
        Team teamB(cb);

 
        YoungNinja *ynb = new YoungNinja("A", Point(0,0));
        OldNinja *onb = new OldNinja("A", Point(0,2));
        TrainedNinja *tnb = new TrainedNinja("A", Point(0,5));
        teamB.add(ynb);
        teamB.add(onb);
        teamB.add(tnb);

        teamA.attack(&teamB); // first try attack Traind ninja

        CHECK_EQ(yn->getLocation().get_x(), 0);
        CHECK_EQ(yn->getLocation().get_y(), 5);
        CHECK_EQ(on->getLocation().get_x(), 0);
        CHECK_EQ(on->getLocation().get_y(), 12);
        CHECK_EQ(tn->getLocation().get_x(), 0);
        CHECK_EQ(tn->getLocation().get_y(), 18);
        CHECK_EQ(tnb->getHitPoints(), 110);


        teamA.attack(&teamB);

        CHECK_EQ(yn->getLocation().get_x(), 0);
        CHECK_EQ(yn->getLocation().get_y(), 5);
        CHECK_EQ(on->getLocation().get_x(), 0);
        CHECK_EQ(on->getLocation().get_y(), 5);
        CHECK_EQ(tn->getLocation().get_x(), 0);
        // CHECK_EQ(tn->getLocation().get_y(), 6);


        CHECK_EQ(tnb->getHitPoints(), 60);
        CHECK_EQ(teamA.stillAlive(), 4);
        CHECK_EQ(teamB.stillAlive(), 4);

        teamA.attack(&teamB);
        

        CHECK_EQ(yn->getLocation().get_x(), 0);
        CHECK_EQ(yn->getLocation().get_y(), 5);
        CHECK_EQ(on->getLocation().get_x(), 0);
        CHECK_EQ(on->getLocation().get_y(), 5);
        CHECK_EQ(tn->getLocation().get_x(), 0);
        CHECK_EQ(tn->getLocation().get_y(), 2);

        CHECK_EQ(teamB.stillAlive(), 3);
        CHECK_EQ(onb->getHitPoints(), 150);

        teamA.attack(&teamB);

        CHECK_EQ(teamB.stillAlive(), 3);
        CHECK_EQ(onb->getHitPoints(), 100);

        teamA.attack(&teamB);

        CHECK_EQ(teamB.stillAlive(), 2);
        teamA.attack(&teamB);
        teamA.attack(&teamB);
        CHECK_EQ(teamB.stillAlive(), 1);

        CHECK_EQ(yn->getLocation().get_x(), 0);
        CHECK_EQ(yn->getLocation().get_y(), 0);
        CHECK_EQ(on->getLocation().get_x(), 0);
        CHECK_EQ(on->getLocation().get_y(), 0);
        CHECK_EQ(tn->getLocation().get_x(), 0);
        CHECK_EQ(tn->getLocation().get_y(), 0);




        

    }

    TEST_CASE("stillAlive") {
        Point location(0, 0);
        Cowboy* leader = new Cowboy("John", location);
        Team team(leader);

        CHECK_EQ(team.stillAlive(), 1);

        leader->hit(110); 

        CHECK_EQ(team.stillAlive(), 0);
    }

    TEST_CASE("nearestChar") {
        Cowboy* leaderA = new Cowboy("ploni", Point(0,0));
        Team teamA(leaderA);

        Cowboy* leaderB = new Cowboy("almoni", Point(3,4));
        Team teamB(leaderB);
        YoungNinja *a = new YoungNinja("d", Point(5,5));
        YoungNinja *b = new YoungNinja("d", Point(4,4));
        YoungNinja *c = new YoungNinja("d", Point(3,4));


        Cowboy* nearest = dynamic_cast<Cowboy*>(Team::nearestChar(&teamB, leaderA));
        CHECK_EQ(nearest, leaderB);
    }
}
