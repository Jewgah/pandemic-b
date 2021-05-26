/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

//Includes
#include "Dispatcher.hpp"

/**
 *  When a Dispatcher is in a city that has a Research Station.
 * he can fly directly to any destination without needing the proper card
 **/

namespace pandemic {

// Special fly_direct method that allows a dispatcher to fly directly to any city without needing the proper
// card, only when the current city he is in has a Research Station
Player& Dispatcher::fly_direct(City city){

        if(current_==city) {throw invalid_argument{"you already here"};}

        //if there is a RS then fly
        if(!board_.checkStation(current_)) {return Player::fly_direct(city);}

        current_=city; // update current_ city

        return *this;
}
}
