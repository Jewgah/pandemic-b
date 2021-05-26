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
 *  A Field Doctor can treat diseases not only in the city he is in but also in all the nearby ones,
 *  without needing the proper card.
**/

namespace pandemic{

  class FieldDoctor : public Player{

    public:
    // Constructor using Initialization List
    FieldDoctor(Board& board,City city) : Player(board,city,"FieldDoctor"){}

    // Special treat method than can treat a disease not only in current city but also in nearby ones.
    Player& treat(City city);
  };
}
