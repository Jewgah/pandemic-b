/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"


/**
 *  A Virologist can treat a disease not only in the city he is in, but also in any city by using
 *  The proper card.
**/

namespace pandemic{

  class Virologist : public Player{

    public:
    //Constructor using Initialization List
    Virologist(Board& board,City city) : Player(board,city,"Virologist"){}

    // A special method allowing to treat a disease regardless of the city the Virologist is in
    // By using the proper card.
    Player& treat(City city);
  };
}
