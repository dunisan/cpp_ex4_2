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

        SUBCASE("simple distance"){
            Point a(0,0); 
            Point b(5,0);

            CHECK_EQ(a.distance(b), 5); 
        }

        SUBCASE("complex distance"){
            Point a(2.34,6.227);
            Point b(-23.33, 5.33);
            CHECK_EQ(a.distance(b), 25.6781); 

        }

        SUBCASE("same point - error"){
            Point a(1,2); 
            CHECK_THROWS_AS(a.distance(a),std::invalid_argument);
        }
    }

    TEST_CASE("print") {
        Point a(1.2,3); 
        Point b(-3.3,-2); 

        CHECK_EQ(a.print() , "(1.2,3)");
        CHECK_EQ(b.print(), "(-3.3,-2)"); 
    }

    TEST_CASE("moveTowards") {
        SUBCASE("faraway"){
            Point source(0,0); 
            Point dest(20,20);
            double distance= 10; 


            Point expected(0,0);
            expected = source.moveTowards(source, dest, distance);

            CHECK_EQ(expected.get_x(), 7.07107);
            CHECK_EQ(expected.get_y(), 7.07107); 
        }

        SUBCASE("close"){

            Point source(2,3); 
            Point dest(2,6); 
            double distance = 10; 
            Point expected(0.0,0.0);
            expected = source.moveTowards(source, dest, distance);
            CHECK_EQ(expected.get_x(), dest.get_x());
            CHECK_EQ(expected.get_y(), dest.get_x());
        }
    }

}

TEST_SUITE("CHARACTER - cowboy") {

    
    TEST_CASE("constructor") {

        Cowboy a("Ploni", Point(1,1));
        CHECK_EQ(a.getHitPoints(), 110); 
        CHECK_EQ(a.getNumOfBullets(), 6); 
        CHECK_EQ(a.getName() , "Ploni");  
    }

    TEST_CASE("Is_Alive"){

        Cowboy a("Ploni", Point(1,1));
        a.hit(100);  
        CHECK(a.isAlive()); 
        a.hit(50);
        CHECK(!a.isAlive());
    }

    TEST_CASE("distance") {

        SUBCASE("simple distance"){
            Cowboy a("Ploni", Point(0,0));
            Cowboy b("Almoni", Point(5,0));

            //CHECK_EQ(a.distance(b), 5); 
        }
        SUBCASE("complex distance"){
            Cowboy a("Ploni", Point(2.34,6.227));
            Cowboy b("Almoni", Point(-23.33, 5.33));
           // CHECK_EQ(a.distance(b), 25.6781); 
        }
    }

    TEST_CASE("hit") {
         Cowboy a("Ploni", Point(1,1));
         a.hit(55);
         CHECK_EQ(a.getHitPoints(), 55); 
        
    }



    TEST_CASE("getName") {
        // check in constructor 
    }
        
    TEST_CASE("getLocation") {
        Cowboy a("Ploni", Point(1,1));
        Cowboy c("Almoni", Point(2,1));
        Cowboy* b = &c; 
        a.shoot(b); 
        a.shoot(b); 
        CHECK_EQ(a.getNumOfBullets(),4); 
    }
    
    TEST_CASE("print") {
        Cowboy a("Ploni", Point(1,1));
        CHECK_NOTHROW(a.print()); 
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

    TEST_CASE("hasBullets") {
        Cowboy a("Ploni", Point(1,1));
        Cowboy c("Almoni", Point(2,1));
        Cowboy* b = &c; 

        for (int i = 0; i < 6; i++)
        {
            CHECK(a.hasboolets());
            a.shoot(b);
        }
         
        CHECK(!a.hasboolets()); 
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
        CHECK_EQ(b.getSpeed(), 12);
        CHECK_EQ(c.getSpeed(), 8);
        CHECK_EQ(a.getHitPoints(), 100);
        CHECK_EQ(a.getHitPoints(), 120);
        CHECK_EQ(a.getHitPoints(), 150);
    }

    TEST_CASE("move") {
        YoungNinja a("Almoni", Point(2,2)); //100,14
        OldNinja b("Ploni", Point(2,20));// 120,12
        TrainedNinja c("Shalmoni", Point(2,2)); // 150, 8

        YoungNinja* d = &a; 
        OldNinja* e = &b; 
        TrainedNinja* g = &c; 
    
        a.move(e); // 2,16 
        b.move(g); // 2,8
        c.move(e); // 8,8
        
        CHECK_EQ(a.getLocation().get_x(), 2); 
        CHECK_EQ(a.getLocation().get_y(), 16); 
        CHECK_EQ(b.getLocation().get_x(), 8); 
        CHECK_EQ(b.getLocation().get_y(), 8); 
        CHECK_EQ(c.getLocation().get_x(), 8); 
        CHECK_EQ(c.getLocation().get_y(), 8); 

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
TEST_SUITE("Team") {
    TEST_CASE("constructor") {
        YoungNinja a("Almoni", Point(3,3)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        TrainedNinja c("Shalmoni", Point(2,3)); 
        Cowboy d("Hevroni", Point(1,1.1)); 
        
        Team w(&a); 
        
        CHECK_EQ(w.getLeader()->getName(), "Almoni"); 
        CHECK_EQ(w.stillAlive(), 1); 
    }

    TEST_CASE("add") {
        YoungNinja a("Almoni", Point(3,3)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        TrainedNinja c("Shalmoni", Point(2,3)); 
        Cowboy d("Hevroni", Point(1,1.1)); 

        Team w(&a); 
        w.add(&b);
        w.add(&c); 

        CHECK_EQ(w.stillAlive(), 3); 
    }


    TEST_CASE("attack") {
        YoungNinja a("Almoni", Point(0,0)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        TrainedNinja c("Shalmoni", Point(2,2)); 
        Cowboy d("Hevroni", Point(3,3)); 

        Team w(&a); 
        w.add(&b);
        w.add(&c);
 

        Team q(&d); 

        w.attack(&q);        
     
        CHECK_EQ(q.stillAlive(),0); 
    }

    
    TEST_CASE("still alive") {
        YoungNinja a("Almoni", Point(0,0)); //100,14
        OldNinja b("Ploni", Point(1,1));// 120,12
        TrainedNinja c("Shalmoni", Point(2,2)); 
        Cowboy d("Hevroni", Point(3,3)); 

        Team w(&a);
        CHECK_EQ(w.stillAlive(),1); 
        w.add(&b);
        CHECK_EQ(w.stillAlive(),0); 
        w.add(&c);
        CHECK_EQ(w.stillAlive(),0); 


        Team q(&d); 

        w.attack(&q);        
     
        CHECK_EQ(q.stillAlive(),0); 
    }
    TEST_CASE("print") {
        YoungNinja a("Almoni", Point(3,3));
        OldNinja b("Ploni", Point(1,1)); 
        TrainedNinja c("Shalmoni", Point(2,3)); 
        Cowboy d("Hevroni", Point(1,1.1)); 
        Team w(&a); 
        w.add(&b);
        w.add(&c); 
        w.add(&d); 

        CHECK_NOTHROW(w.print()); 
    }
}

