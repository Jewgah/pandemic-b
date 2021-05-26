/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "OperationsExpert.hpp"

/**
 *  An Operations Expert can build a Research Station in the city he currently is without needing the proper card *
**/


namespace pandemic{

  // Builds a Research Station in the city the Player is currently in.
  // The card isn't needed
  Player& OperationsExpert::build(){

    //builds the research station
    board_.insertStation(current_);

  return *this;
  }
}
