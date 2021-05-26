/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "GeneSplicer.hpp"

/**
 *  A Gene Splicer can discover a cure by using any 5 cards, not necessarily of the same disease's color.
**/

namespace pandemic{
  //A special method allowing the discovery of a cure by using any 5 cards, not necessarily of the same disease's color
  Player& GeneSplicer::discover_cure(Color color){
    if(!board_.checkStation(current_)){throw invalid_argument{"no station"};
    }

    const int num_of_cards = 5;
    int c = 1;

    if(cards_.size()<num_of_cards){throw invalid_argument{"Less than 5 cards in hand"};}

    for(auto k = cards_.begin(); k != cards_.end(); c++){
        if(c == num_of_cards) { break; } //stops after throwing 5 cards
        k = cards_.erase(k); //throw card
    }

    board_.insertDiscoverCure(color);
    return *this;

  }
}
