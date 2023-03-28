
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
#include "player.hpp"

using namespace std;


void Card::printCard(){
   string res="";
   if (this->number > 10 || this->number ==1){
    switch(this->number){
    case 11:
        res+= "Jack";
        break;
    case 12:
        res+= "Queen";
        break;
    case 13:
        res+= "King";
        break;
    case 1:
        res += "Ace";
        break;
   }
   }
   else {
   switch(this->number){
    case 2:
        res+= "Two";
        break;
    case 3:
        res+= "Three";
        break;
    case 4:
        res+= "Four";
        break;
    case 5:
        res += "Five";
        break;
    case 6:
        res+= "Six";
        break;
    case 7:
        res+= "Sevem";
        break;
    case 8:
        res+= "Eight";
        break;
    case 9:
        res+= "Nine";
        break;
   }
 }
res+= "of";
// needed to add the shape and the color
   cout<< res;
}
 int Card::getNum(){
    return this->number;
 }
 string Card::getShape(){
    return this->shape;
 }
 string Card:: getColor(){
    return this->color;
 }