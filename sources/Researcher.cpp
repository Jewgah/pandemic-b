/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

/**
 *  A Researcher can discover a cure in any city, without needing to be a Researcher Station there.
**/

//Includes
#include "Researcher.hpp"

namespace pandemic{
  // A special method to discover a cure without needing a Researcher Station in the city
  Player& Researcher::discover_cure(Color color){
            int cnt=0;
            for(const auto & card : cards_){
              if(color == color_city[card]){
                ++cnt;
              }
            }
            const int num_of_cards = 5;
                 
            if(cnt<num_of_cards){throw invalid_argument{"you have less than 5 cards"};}

            cnt = 1;
            for(auto k = cards_.begin(); k != cards_.end(); cnt++){
                if(cnt == num_of_cards) { break; } // stops after throwing 5 cards
                if(color == color_city[*k]) { k = cards_.erase(k);} // throw a card of the same color
                else { k++;}
            }

            board_.insertDiscoverCure(color);
    return *this;
  }
}
