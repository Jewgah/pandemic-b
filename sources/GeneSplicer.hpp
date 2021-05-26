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
#include "Board.hpp"
#include "City.hpp"

/**
 *  A Gene Splicer can discover a cure by using any 5 cards, not necessarily of the same disease's color.
**/

namespace pandemic{

  class GeneSplicer : public Player{
    private:

    public:
    // Constructor using Initialization List
    GeneSplicer(Board& board,City current) : Player(board,current,"GeneSplicer"){}

    // A special method allowing the discovery of a cure by using any 5 cards, not necessarily of the same disease's color
    Player& discover_cure(Color color);
  };
}
