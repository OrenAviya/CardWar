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
    string getName() {return (name);}
    // define in cpp file
    void setName (string n) ;

// // Constructors:
    Player() : name{"defult"} {
      //std::cout << "defult player" << std::endl; 
    }

    Player(string name):
   // std::cout << "Player: "+ std::to_string(z) << std::endl; 
    name {std::move(name)}
    {}

int stacksize();
int cardesTaken();
};
