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
#include <iostream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic{

  class Board{

    private:

      map<City,int> disease_level;
      set<Color> discover_cure;
      set<City> station_research;
      

    public:

      static bool checkConnect(City& city1,City& city2);
      bool checkStation(City city);
      void insertStation(City city);
      void insertDiscoverCure(Color color);
      bool checkDiscoverCure(City city);
      void remove_disease_level();
      void remove_cures();
      void remove_stations();      
      int & operator[]( City city);
      bool is_clean();

      friend ostream& operator<<(ostream& out,const Board& b);
  };
}
