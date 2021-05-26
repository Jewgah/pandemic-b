/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

#pragma once

//Includes
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"


#include <stdexcept>
#include <set>

using namespace std;

namespace pandemic{
  class Player{

    protected:
        Board& board_;
        City current_;
        string role_;
        set<City> cards_;

    public:
      //Player Constructor as Initialization List
      Player(Board& board_,City current_,string role_):board_(board_),current_(current_),role_(role_){}

      virtual Player& drive(City city_);
      virtual Player& fly_direct(City city_);
      virtual Player& fly_shuttle(City city_);
      virtual Player& fly_charter(City city_);
      virtual Player& treat(City city_);
      virtual Player& build();
      virtual Player& discover_cure(Color color_);
      
      Player& take_card(City city_);

      //Special Player's role
      string role();

  };
}
