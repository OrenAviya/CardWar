//#ifndef Card
//#define Card
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "player.hpp"
namespace ariel{}
using namespace ariel;

class Card{

private:
    string color;
    int number;
    string shape;
public:

// constructor:
Card (int n , string shape , string col){
this->number = n;
this->color = col;
this->shape = shape;
}

 void printCard();
 int getNum();
 string getShape();
 string getColor();
};


//#endif Card