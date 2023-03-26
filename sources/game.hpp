#ifndef GAME
#define GAME 

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
        Player p1;
        Player p2;

void playTurn();
void printLastTurn(); 
int stacksize();
int cardesTaken();
void playAll();
void printWiner(); 
void printLog();
void printStats();

}

#endif GAME
