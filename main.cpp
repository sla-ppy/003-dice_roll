#include <iostream>
#include <random>

int randGen()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 9); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

int main() {
    const int diceRolls = 9;

    int diceRoll[diceRolls];

    for (int i = 0; i < diceRolls; ++i) {
        diceRoll[i] = randGen();
        std::cout << " " << diceRoll[i];
    }

    return 0;
}
