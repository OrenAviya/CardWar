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
    int number {};
    string shape {};
    string color {};
public:

// constructor:
Card (int n , string shape , string col):
number{n} , shape{std::move(shape)} , color{std::move(col)} 
{
// using member initializer for tidy
}

 void printCard();
 int getNum();
 string getShape();
 string getColor();
};


//#endif Card