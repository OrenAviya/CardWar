//
// Created by aviyaoren on 27/03/2023.
//
#include "doctest.h"
#include  "sources/game.hpp"
#include "stdexcept"


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

    Player one("one") ;
    Player two("two") ;
    Game ga( one , two );
    ga.playAll();
    CHECK_NOTHROW(ga.printWiner());

    //  regular game:
    Player p1("one");
    Player p2("two");
    Game gam(p1,p2);
    while(p1.stacksize()>0 && p2.stacksize()>0)
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

TEST_CASE(" If you start a game with more than 2 players"){

}

TEST_CASE(" if you can`t play another turn after game ends")
{
    Player one("one") ;
    Player two("two") ;
    Game g(one  , two);
    CHECK_NOTHROW(g.playAll());
    CHECK_THROWS(g.playAll());
    CHECK_THROWS(g.playTurn());
}
