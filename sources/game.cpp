
#include "game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
namespace ariel{}
using namespace ariel;



void Game :: playTurn(){

}

string Game :: printLastTurn(){
    cout << "Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.";
//if one is win
    return this->p1.getName();
    //else return this->p2.getName();
}


void Game ::  playAll(){

}
void Game ::  printWiner(){

}
void Game :: printLog(){

}
void Game :: printStats(){
    
}