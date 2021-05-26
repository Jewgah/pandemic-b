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
 *  A Scientist can discover a cure by using only n cards instead of 5 (n is passed as parameter in the constructor)
**/

namespace pandemic{

  class Scientist : public Player{
    
    int n; // private

    public:
    //Constructor using Initialization List
    Scientist(Board& board,City city,int num) : Player(board,city,"Scientist"),n(num){}

    // A special method to discover a cure by using only n cards instead of 5
    Player& discover_cure(Color color);
  };
}
