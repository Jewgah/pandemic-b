/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

#include "Player.hpp"

/* Each action should update the board status and player position accordingly.
   If the operation is invalid, an appropriate exception must be thrown.
   There can be more than one player in a city. */

namespace pandemic{

  // Move from the current city to a nearby city (according to the map)
  Player& Player::drive(City city){

    if(current_==city){throw invalid_argument{"you already here"};}

    if(!Board::checkConnect(current_,city)) {throw invalid_argument{"cities not connected"};}

    current_=city;

    return *this;
  }

  // Uses the card of a city and move there.
  // The card is then thrown.
  Player& Player::fly_direct(City city){

    if(!cards_.contains(city)){throw invalid_argument{"you don't have the right card"};}

    if(current_==city){throw invalid_argument{"you are already here"};}

    cards_.erase(city); //throws the card
    current_=city; // update the current city

    return *this;
  }

  // Uses the card of the city the player is currently in to fly anywhere.
  // The card is then thrown.
  Player& Player::fly_charter(City city_){

    if(!cards_.contains(current_)){throw invalid_argument{"you don't have the right card"};}

    if(current_==city_){throw invalid_argument{"you are already here"};}

    cards_.erase(current_);//throws the card
    current_=city_; // update the current city

    return *this;
  }

  // If there is a Research Station in the city the player is currently in, then he can fly to any other
  // city which also has a Research Station.
  Player& Player::fly_shuttle(City city_){
    if(current_==city_){throw invalid_argument{"you are already here"};}

    if(board_.checkStation(current_) && board_.checkStation(city_)) {
      current_=city_;
    }else{
      throw invalid_argument{"there is no station"};
    }

    return *this;
  }

  // Builds a Research Station in the city the player is currently in by using the card of this current city.
  // The card is then thrown.
  Player& Player::build(){
    if(!cards_.contains(current_)){throw invalid_argument{"you don't have the right card"};}

    board_.insertStation(current_); // builds a RS in current city
    cards_.erase(current_); // throws the right card

  return *this;
  }

  // Discovers a cure for a disease of a certain color.
  // To do this, you must be in a city that has a research station, and throw 5 colored cards of the disease.
  // The color of the city they are in does not matter.
  Player& Player::discover_cure(Color color_){
        if(!board_.checkStation(current_)){throw invalid_argument{"no research station"};}

        int cnt=0;
        //counts the number of cards in hand
        for(const auto & card : cards_){
          if(color_ == color_city[card]){
            ++cnt;
          }
        }

        const int num_of_cards = 5;
        
        //checks if there are at least 5 cards in hand
        if(cnt<num_of_cards){throw invalid_argument{"you have less than 5 cards"};}
        cnt = 1;

        //throw 5 cards
        for(auto k = cards_.begin(); k != cards_.end(); cnt++){
            if(cnt == num_of_cards) { break; } // stop at 5 cards thrown
            if(color_ == color_city[*k]) {k = cards_.erase(k);} // throw a card
            else {
                k++;
            }
        }

        // add the discoverd cure to the board
        board_.insertDiscoverCure(color_);
    return *this;
  }

  // Reduces the level of the disease in the current city by 1.
  // 1-If a cure for the disease has already been discovered in the color of the city, then the disease level is
  // reduced to 0.
  // 2- If there is no infection at all in the city (disease level already at 0) then throws exception
  Player& Player::treat(City city_){
    if(current_!=city_){throw invalid_argument{"you are not here"};}
    if(board_[city_]==0){throw invalid_argument{"level of disease already equals to zero"};}

    if(board_.checkDiscoverCure(city_)){
      board_[city_]=0; // if there's a cure then reset level to zero
    }else{
      board_[city_]--; //else if there's no cure just decrease it by one
    }

    return *this;
  }

  // Returns player's role
  string Player::role(){
    return role_;
  }

  // Provides a random city card to the player.
  // There is only a single card for each city.
  // Thus, if we try to provide a card that is already in the hand of another player then
  // there won't be any change. -There is no need to check the correctness of this method: no need to check if
  // the card picked is indeed still in the deck, nor that the card was given twice. This method always succeeds
  Player& Player::take_card(City city_){
    cards_.insert(city_);
    return *this;
  }
}
