/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */


//Includes
#include "FieldDoctor.hpp"

/**
 *  A Field Doctor can treat diseases not only in the city he is in but also in all the nearby ones,
 *  without needing the proper card.
**/

namespace pandemic{

  //Special treat method than can treat a disease not only in current city but also in nearby ones.
  Player& FieldDoctor::treat(City city){

    //throws
    if(current_ != city && !Board::checkConnect(current_,city)){throw invalid_argument{"cities not connected"};}

    if(board_[city]==0){throw invalid_argument{"level of disease already equals to zero"};}

    //updates
    if(board_.checkDiscoverCure(city)){ //If a cure has been discovered
      board_[city]=0; // reduce level of diseae to zero
    }
    else {board_[city]--;} //reduce level of disease by one

    return *this;
  }
}
