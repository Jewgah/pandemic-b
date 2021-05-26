/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Include
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"


/**
 *  A Medic reduces the level of a disease to 0 when he treats it.
 *  Moreover, if a cure has already been discovered for a disease, the Medic
 *  Automatically reduces the level of the disease to 0 just by being in the city,
 *  Without needing to treat it.
**/

namespace pandemic{

  class Medic : public Player{
    private:
      void update();

    public:
    //Constructor using Initialization List
    Medic(Board& board,City city) : Player(board,city,"Medic"){}

    // Special method that reduces the level of disease to 0.
    Player& treat(City city) override;


    Player& fly_direct(City city) override;
    Player& drive(City city) override;
    Player& fly_charter(City city) override;
    Player& fly_shuttle(City city) override;
  };
}
