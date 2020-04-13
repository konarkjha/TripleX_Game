#include <iostream>
#include <ctime>

int printIntro(int difficulty)
{
    std::cout << "You are a secret agent breaking into a level " << difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
    return 0;
}
int playGame(int difficulty)
{
    srand(time(NULL)); // create new random based on time of day
    printIntro(difficulty);

    int codeA = rand() % difficulty + difficulty;
    int codeB = rand() % difficulty + difficulty;
    int codeC = rand() % difficulty + difficulty;

    const int codeSum = codeA + codeB + codeC;
    const int codeProduct = codeA * codeB * codeC;

    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The code add-up to: " << codeSum << std::endl;
    std::cout << "+ The code multiply to give: " << codeProduct << std::endl;

    int guessA, guessB, guessC;
    std::cin >> guessA >> guessB >> guessC;
    std::cout << "You entered: " << guessA << guessB << guessC;

    int guessSum = guessA + guessB + guessC;
    int guessProduct = guessA * guessB * guessC;
    if (guessSum == codeSum && guessProduct == codeProduct)
    {
        std::cout << "\n\nYou win!\n";
        return true;
    }
    else
    {
        std::cout << "\n\nYou lose!\n";
        return false;
    }
}

int main()
{
    int levelDifficulty = 1;
    int const maxDifficulty = 3;
    while (levelDifficulty <= maxDifficulty)
    {
        bool bLevelComplete = playGame(levelDifficulty);
        std::cin.clear();  //Clears any errors
        std::cin.ignore(); //Clears the buffer

        if (bLevelComplete)
        {
            ++levelDifficulty;
        }
    }
    std::cout << "\n+++ Great work agent! you got all the files! Now get out of there! +++\n";
    return 0;
}