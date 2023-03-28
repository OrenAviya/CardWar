//
// Created by aviyaoren on 27/03/2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "doctest.h"
#include "sources/game.hpp"
#include "stdexcept"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "string"
using namespace std;


TEST_CASE("checking constructor of player"){
    CHECK_NOTHROW(Player p1("p1"));

}
TEST_CASE("checking methods of Player"){
    Player p1("p1");
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK(p1.stacksize()==26);
    CHECK(p1.cardesTaken() == 0);

}
TEST_CASE("checking constructor of Game"){
    Player one("one") ;
    Player two("two") ;
    CHECK_NOTHROW(Game ga( one , two ));

}
TEST_CASE("check if the playAll method is working "){
    //suppose to play until someone wins, means that the cards of someone is over.
    Player one("one") ;
    Player two("two") ;
    Game ga( one , two );
    CHECK_NOTHROW(ga.playAll());
    ga.playAll();
    bool B = true;
    if (one.stacksize() != 0 && two.stacksize()!=0)
        B = false;
    CHECK(B);
}

TEST_CASE("check if there is a winner after play "){
    // using playall:
cout << "check if there is a winner after play ";
    Player one("one") ;
    Player two("two") ;
    Game ga( one , two );
    ga.playAll();
    CHECK_NOTHROW(ga.printWiner());

    //  regular game:
    Player p1("one");
    Player p2("two");
    Game gam(p1,p2);
//   for now... actually shuld be while the two stacksize>0
   for (int i=0 ; i<5; i++)
        gam.playTurn();
    bool check;
    if(p1.stacksize() == 0 || p2.stacksize() == 0)
        check = true;
    else
        check = false;
    CHECK(check);
    CHECK_NOTHROW(ga.printWiner());
}

TEST_CASE("play turn ->at list minus 1 card each"){
    Player one("one") ;
    Player two("two") ;
    int s1First = one.stacksize();
    int s2First = two.stacksize();
    Game ga( one , two);
    CHECK_NOTHROW(ga.playTurn());
    ga.playTurn();

    CHECK(one.stacksize() < s1First );
    CHECK(two.stacksize() < s2First);
}

TEST_CASE("all cards together = 52"){
    Player one("one") ;
    Player two("two") ;
    int s1First = one.stacksize();
    int s2First = two.stacksize();
    bool  check = true;
    if (s1First + s2First != 52)
        check = false;
    Game g(one  , two);
    g.playTurn();
    if (s1First + s2First + one.cardesTaken()+two.cardesTaken() != 52)
        check = false;
    CHECK (check);
}
TEST_CASE("check if there is a winner every turn"){
    Player one("one") ;
    Player two("two") ;
    Game g(one  , two);
    g.playTurn();
    string name = g.printLastTurn();
    bool o = true;
    bool t = true;
    if(one.getName().compare(name))
        CHECK(o);
    if (two.getName().compare(name))
        CHECK(t);

}

TEST_CASE(" If the turn-winner take the cards"){
    Player one("one") ;
    Player two("two") ;
    Game g(one  , two);
    int hand1 = one.cardesTaken();
    int hand2 = two.cardesTaken();
    g.playTurn();
    string name = g.printLastTurn();
    if(one.getName().compare(name))
        CHECK(one.cardesTaken() > hand1);
    if (two.getName().compare(name))
        CHECK(two.cardesTaken() > hand2);
}


TEST_CASE(" You must not be able to play another turn after game ends")
{
    Player one("one") ;
    Player two("two") ;
    Game g(one  , two);
    CHECK_NOTHROW(g.playAll());
    CHECK_THROWS(g.playAll());
    CHECK_THROWS(g.playTurn());
}

TEST_CASE("check if every player gets 26 cards"){
    Player one("one") ;
    Player two("two") ;
    Game g(one  , two);
    int num = 26;
    bool division = true;
    if (one.stacksize() !=num || two.stacksize() != num)
        division = false;
CHECK(division);
}

TEST_CASE("Check if both players get their names ")
{
    Player one("one"); //Creating player objects
    Player two("two");
    Game g(one, two);
    CHECK(one.getName().compare("one"));
    CHECK(two.getName().compare("two"));
}

TEST_CASE("test card constructor"){
   CHECK_NOTHROW( Card c (1 , "daimond" , "red"));
    
}

TEST_CASE("check the values of the color card - just red/black "){
    Card c (1 , "daimond" , "red");
    if(c.getColor() == "red" || c.getColor() =="black")
    {
        CHECK_NOTHROW(Card c (1 , "daimond" , "red"));
    }
    else{
        CHECK_THROWS_AS(Card c(1 , "daimond" , "red") ,invalid_argument);
    }
}

TEST_CASE("check the intilization of a card"){
    Card c (1 , "daimond" , "red");
    bool ok = true; 
    if (! (c.getColor() != ""))
    ok = false;
    if (! (c.getNum()!= 0))
    ok = false;
    if (! (c.getColor() != ""))
    ok = false;
    CHECK(ok);
}

TEST_CASE("check the values of shape - just four options"){
    Card c (1 , "daimonds" , "red");
    bool correct =true;
    if (c.getShape() != "daimonds" && c.getShape() != "spades" && c.getShape() != "hearts"
    && c.getShape() != "clubs")
    correct = false;

    CHECK(correct);

}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}

TEST_CASE(""){
    
}
