#include <iostream>
#include <cstdlib>
#include <ctime>

void printAsciiArt() {
    std::cout << "   ________                                   ________                    " << std::endl;                  
    std::cout << "  /  _____/ __ __   ____   ______ ______     /  _____/_____    _____   ____  " << std::endl;
    std::cout << " /   \\  ___|  |  \\_/ __ \\ /  ___//  ___/    /   \\  ___\\__  \\  /     \\_/ __ \\ " << std::endl;
    std::cout << " \\    \\_\\  \\  |  /\\  ___/ \\___ \\ \\___ \\     \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << std::endl;
    std::cout << "  \\______  /____/  \\___  >____  >____  >     \\______  (____  /__|_|  /\\___  > " << std::endl;
    std::cout << "         \\/            \\/     \\/     \\/             \\/     \\/      \\/     \\/  " << std::endl;
}

int main() {

    //
    srand(static_cast<unsigned int>(time(nullptr)));

    //generate the number to be guessed
    //for simplicity consider the range to be between 1 and 100
    int secretNumber = rand() % 100 + 1;

    //initialize the attempt value to zero
    int attempts  = 0;


    printAsciiArt();

    //Main Logic of the game
    while (true) {
        std::cout  << "\n";
        std::cout  << "\n";
        
        //Ask the user to input their guess
        int guess;
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> guess;

        std::cout  << "\n";
        std::cout  << "\n";

        //increment the attempts value after each attempt
        attempts++;

        //check if guess is correct
        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number. You took  " << attempts << " attempts. \n";
        }

        //check if guess value is greater than the secret value 
         else if (guess > secretNumber){
            std::cout << "Your guess is higher than the secret number. Try again. \n";
         }

         //guess can only be of lesser value, if it isn't equal or large 
         else{
            std::cout << "Your guess is lower than the secret number. Try again. \n";
         }
    }

    return 0;
}