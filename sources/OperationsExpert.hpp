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
 *  An Operations Expert can build a Research Station in the city he currently is without needing the proper card *
**/

namespace pandemic{
  class OperationsExpert : public Player{
    private:

    public:

    //Constructor using Initialization List
    OperationsExpert(Board& board,City city) : Player(board,city,"OperationsExpert"){}

    //Special build method which doesn't need to throw the proper card after building the Research Station
    Player& build();
  };
}
