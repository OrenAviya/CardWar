//#ifndef PLAYER
//#define PLAYER
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel{}
using namespace ariel;

class Player{
    private:
        string name;

    public:
    // define inline
    string getName() {return (this->name);}
    // define in cpp file
    void setName (string n) ;

// // Constructors:
    Player() {
      //std::cout << "defult player" << std::endl; 
      name = "defult"; 
    }

    Player(string z) { 
   // std::cout << "Player: "+ std::to_string(z) << std::endl; 
    name = z; 
    }

int stacksize();
int cardesTaken();
};


//#endif PLAYER