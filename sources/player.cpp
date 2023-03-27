#include "../../CardWar/sources/player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{}
using namespace ariel;

void Player :: setName (string n){
     this->name = n;
}
int Player::stacksize() {
    return 26;
}
int Player :: cardesTaken(){
 return 0 ;
}