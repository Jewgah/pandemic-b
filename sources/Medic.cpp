/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Include
#include "Medic.hpp"

/**
 *  A Medic reduces the level of a disease to 0 when he treats it.
 *  Moreover, if a cure has already been discovered for a disease, the Medic
 *  Automatically reduces the level of the disease to 0 just by being in the city,
 *  Without needing to treat it.
 **/

namespace pandemic {
// Special method that reduces the level of disease to 0.
Player& Medic::treat(City city){

        if(current_!=city) {throw invalid_argument{"you're not here"};}
        if(board_[city]==0) {throw invalid_argument{"level of disease is already equal to zero"};}

        //update level of disease
        board_[city]=0;

        return *this;
}

// update function that resets the level of disease if there is a discovered cure for a given city ('s color)
void Medic::update() {
        if(board_.checkDiscoverCure(current_)) {
                board_[current_] = 0;
        }
}

Player& Medic::fly_direct(City city){
  Player::fly_direct(city);
  Medic::update();

  return *this;
}
Player& Medic::drive(City city){
   Player::drive(city);
   Medic::update();

  return *this;
}
Player& Medic::fly_charter(City city){
  Player::fly_charter(city);
  Medic::update();

  return *this;
}
Player& Medic::fly_shuttle(City city){
  Player::fly_shuttle(city);
  Medic::update();

  return *this;
}
}
