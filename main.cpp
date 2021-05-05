#include <iostream>
#include <random>
#include <array>

int randGen()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 9); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

int main() {
    const int numOfRolls = 9;

    std::array<int, numOfRolls> diceRolls{0, 0, 0, 0, 0, 0, 0, 0, 0,};

    for (auto it = diceRolls.begin(); it != diceRolls.end(); it++) {
        *it = randGen();
        std::cout << " " << *it;
    }

    return 0;
}