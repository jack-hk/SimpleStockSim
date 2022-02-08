#pragma once

#include "Minerals.h"
#include "Random.h"

int stock1(STOCK1_VALUE);
int stock2(STOCK2_VALUE);
int stock3(STOCK3_VALUE);
int stocks[3] = { stock1, stock2, stock3 };

void SimulateStocks() {
    for (size_t i = 0; i < sizeof(stocks) / sizeof(stocks[0]); i++)
    {
        if (RandomNumber(1, 2) == 1) { //change to a bool rand
            stocks[i] += RandomNumber(1, 100);
        }
        else {
            stocks[i] -= RandomNumber(1, 100);
        }

        std::cout << stocks[i] << std::endl;
    }
}

void UpdateChart() {
    while (true) {
        std::string Input = "";
        std::cin >> Input;
        SimulateStocks();
    }
}

