#ifndef PLAYER
#define PLAYER

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
    Player() {
      //std::cout << "defult player" << std::endl; 
      name = "defult"; 
    }

    Player(string z) { 
   // std::cout << "Player: "+ std::to_string(z) << std::endl; 
    name = z; 
    }

void stacksize();
void cardesTaken();
};


#endif PLAYER