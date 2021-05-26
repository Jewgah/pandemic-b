/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

#include "Board.hpp"
#include <string>

namespace pandemic {

// Return true if given city has a Research Station
bool Board::checkStation(City city){
        return station_research.contains(city);
}

// Builds a Research Station in given city
void Board::insertStation(City city){
        station_research.insert(city);
}

// adds a discovered cure for a given color
void Board::insertDiscoverCure(Color color){
        discover_cure.insert(color);
}

// Return true if there is a discovered cure for a given city (using its color)
bool Board::checkDiscoverCure(City city){
        return discover_cure.contains(color_city.at(city));
}

// Check if two cities are connected
bool Board::checkConnect(City& city1,City& city2){
        return connect_city.at(city1).contains(city2);
}

// Deletes all Research Stations
void Board::remove_stations(){
        station_research.clear();
}


//Removes all the cures that have been discovered so far from the board
//This method is intended for the purpose of writing tests
//It never throws an exception, and there is no need to check it in a special way.
void Board::remove_cures(){
        discover_cure.clear();
}

//returns true if and only if the whole board is clean (no disease on board)
bool Board::is_clean(){
        for(auto & k :disease_level) {
                if(k.second!= 0) {return false;}
        }

        return true;
}

//for tests only, sets all diseases to 0
void Board::remove_disease_level(){
        disease_level.clear();
}

//operator[] overloading: Reads and Updates the level of disease in the given city
int & Board::operator[]( City city ){
        return disease_level[city];
}


//Displays the status of the board including:
// 1- The level of disease in each city
// 2- The cures discovered so far
// 3- The Research Stations built so far
ostream& operator<<(ostream& out,const Board& b){

        out<<"---------------------------------------"<<endl;
        for(const auto & p : b.disease_level) {
                out<< convert_city_to_string[p.first]<<" "<< p.second<<endl;
        }
        out<<"---------------------------------------"<<endl;
        for(const auto & city : b.station_research) {
                out<< convert_city_to_string[city]<<endl;
        }
        out<<"---------------------------------------"<<endl;
        for(const auto & color : b.discover_cure) {
                out<< convert_color_to_string[color]<<endl;
        }
        return out;
}

}
