/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "Virologist.hpp"

/**
 *  A Virologist can treat a disease not only in the city he is in, but also in any city by using
 *  The proper card.
**/

namespace pandemic{

  // A special method allowing to treat a disease regardless of the city the Virologist is in
  // By using the proper card.
  Player& Virologist::treat(City city){
    if(current_ != city){
      if(!cards_.contains(city)){ // check if player has the right card
        throw invalid_argument{"you don't have the right card"};
        }

      cards_.erase(city); // if he does then throw the card
    }

    if(board_[city] == 0){throw invalid_argument{"level of disease is already equal to zero"};}

    if(board_.checkDiscoverCure(city)){board_[city]=0;} // if there's a cure reset level to zero
    else{ board_[city]--;} // else jsut decrease level by one

    return *this;
  }
}
