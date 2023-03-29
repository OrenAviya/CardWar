// #ifndef GAME
// #define GAME 
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "player.hpp"
namespace ariel{}
using namespace ariel;

class Game{
    private: 
        Player p1{};
        Player p2{};
    
    public:
//constructors
Game (Player pl1 , Player pl2) :
    p1{std::move(pl1)},
    p2{std::move(pl2)}
  {
//std :: cout << "new game with : " + std::to_string(p1)+" "+ std::to_string(p2) << std::end1;
  }  
void playTurn();
string printLastTurn();

void playAll();
void printWiner(); 
void printLog();
void printStats();

};

// #endif GAME
