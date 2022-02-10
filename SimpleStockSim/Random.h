#pragma once

#include <iostream>
#include <string>
#include <random>

int RandomNumber(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); //range
    return dist6(rng);
}



//bool rand? b       
