/**
 * Pandemic Game Assignment
 * C++ Course @Ariel_University
 * Part B
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

#pragma once

//includes
#include <unordered_map>

enum Color  {Blue,Yellow,Black,Red};


static std::unordered_map< Color,std::string > convert_color_to_string =
{
        {Color::Blue,"Blue"},{Color::Yellow,"Yellow"},{Color::Black,"Black"},{Color::Red,"Red"}
};
