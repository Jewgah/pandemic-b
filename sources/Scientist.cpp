/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "Scientist.hpp"

/**
 *  A Scientist can discover a cure by using only n cards instead of 5 (n is passed as parameter in the constructor)
**/

namespace pandemic{

  // A special method to discover a cure by using only n cards instead of 5
  Player& Scientist::discover_cure(Color color){
    if(!board_.checkStation(current_)){throw invalid_argument{"no research station"};}

    int cnt=0;
    for(const auto & card : cards_){
        cnt++; // counts the number of cards in hand
    }

  if(cnt<n){throw invalid_argument{"you have less than n cards"};}
  cnt = 1;
  
  for(auto k = cards_.begin(); k != cards_.end(); cnt++){
      if(cnt == n) { break; } // stops after throwing n cards
      if(color == color_city[*k]) {k = cards_.erase(k);} // throw a card of the right color
      else { k++;}
  }

    //add new discovered cure for this color
    board_.insertDiscoverCure(color);
    return *this;
  }
}
