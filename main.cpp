#include <iostream>
#include <random>
#include <array>

int randGen(int diceSideInput)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, diceSideInput); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

int main() {
    bool rollingDice = true;

    while (rollingDice) {
        system("cls");
        // Get sides of dice for rolls
        int diceSideInput;
        std::cout << "Enter the type of dice you'd like to roll:" << std::endl;
        std::cin >> diceSideInput;

        const int numOfRolls = 1;

        std::array<int, numOfRolls> diceRolls{};

        // Loop through dice rolls
        for (auto it = diceRolls.begin(); it != diceRolls.end(); it++) {
            *it = randGen(diceSideInput);
            std::cout << "Result of the roll: " << *it << std::endl;
        }

        std::string rollAgainInput = "";
        std::cout << "Roll again? Y/N" << std::endl;
        std::cin >> rollAgainInput;

        if (rollAgainInput == "Y" || rollAgainInput == "y") {
            rollingDice = true;
        }
        else if (rollAgainInput == "N" || rollAgainInput == "n") {
            rollingDice = false;
        }
        else {
            std::cout << "Enter a valid option. Y/N" << std::endl;
        }

    }
    return 0;
}