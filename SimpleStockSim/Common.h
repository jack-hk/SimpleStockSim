#pragma once

#include "Minerals.h"
#include "Random.h"
#include <string>

int stock1(STOCK1_VALUE);
int stock2(STOCK2_VALUE);
int stock3(STOCK3_VALUE);
int stocks[3] = { stock1, stock2, stock3 };

int inflateChanceTemp(5), deflateChanceTemp(5);

bool lastRollInflate = false;

void PrintDebug(std::string msg) {
    std::cout << msg << std::endl;
}


void SimulateStocks() {
    
    for (size_t i = 0; i < sizeof(stocks) / sizeof(stocks[0]); i++)
    {
        if (RandomNumber(1, 11) < inflateChanceTemp) {    //base 50%, temp change
            int RandA = RandomNumber(1, 10);
            if (lastRollInflate == true) {
                inflateChanceBase = inflateChanceTemp;
            }

            if (RandA == 1 || RandA == 2) { //const 20%
                stocks[i] += RandomNumber(1, 15);
                PrintDebug("S chance inflate");
            }
            else if (RandA == 3 || RandA == 4 || RandA == 5) { //const 30%
                stocks[i] += RandomNumber(1, 45);
                PrintDebug("M chance inflate");
            }
            else if (RandA == 6 || RandA == 7 || RandA == 8 || RandA == 9 || RandA == 10) { //const 50%
                stocks[i] += RandomNumber(1, 80);
                PrintDebug("B chance inflate");
            }
            else {
                std::cout << "Error: Out of Rand Range!";
            }
            lastRollInflate = true;
            std::cout << stocks[i] << std::endl;
        }

        else if (RandomNumber(1, 10) > deflateChanceTemp) {    //base 50%, temp change
            int RandB = RandomNumber(1, 10);
            if (lastRollInflate == false) {
                deflateChanceBase = deflateChanceTemp;
            }

            if (RandB == 1 || RandB == 2) { //const 20%
                stocks[i] -= RandomNumber(1, 15);
                PrintDebug("S chance deflate");
            }
            else if (RandB == 3 || RandB == 4 || RandB == 5) { //const 30%
                stocks[i] -= RandomNumber(1, 45);
                PrintDebug("M chance deflate");
            }
            else if (RandB == 6 || RandB == 7 || RandB == 8 || RandB == 9 || RandB == 10) { //const 50%
                stocks[i] -= RandomNumber(1, 80);
                PrintDebug("B chance deflate");
            }
            else {
                std::cout << "Error: Out of Rand Range!";
            }
            lastRollInflate = false;
            std::cout << stocks[i] << std::endl;
        }
    }
}

void UpdateChart() {
    while (true) {
        std::string Input = "";
        std::cin >> Input;
        SimulateStocks();
        std::cout << std::endl << "Inflate chance:" << inflateChanceTemp;
        std::cout << std::endl << "Deflate chance:" << deflateChanceTemp;
    }
}

