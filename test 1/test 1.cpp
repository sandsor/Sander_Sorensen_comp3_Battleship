
#include "Battleship_functions.h"
#include "BattleshipAi.h"
#include "password.h"



int main()
{

    int input;
    std::cout << "\nwelcome to the program!" << std::endl;
    std::cout << "what do you want to do?" << std::endl;
    std::cout << "Choose between 1 to 3" << std::endl;
    std::cout << "1: Do the password" << std::endl;
    std::cout << "2: Play battleship" << std::endl;
    std::cout << "3: Quit" << std::endl;
    std::cin >> input;
    if (input == 1) 
    {
        std::cout << "The password is [A,B,C,D,H,L,P,O,N,M]" << std::endl;
        std::cout << "After inputing password please press a to confirm" << std::endl;
        Move();
        //pinput();
        //Logic();
    }
    else if (input == 2) {
        srand(time(NULL));

        Clear(); AIClear(); // clears the maps if i would like to reset it in the code, and just dobble checks there is no variables at start
        setships(); AIsetships();  // sets an equal amount of ships on each board
        int pos1, pos2;
        char choise;
        while (1) // i wanted to do a loop with a checkwin instead, but beacuse of the code i wrote, it didn't work and i scrapped it for another solution.
        {
            std::cout << "you shoot here\n";
            Pshow();
            std::cout << "----------------\n";
            std::cout << "AI shoots here\n";
            makeAIBoard();
            std::cout << "you have to hit " << Numofship() << " more ships" << std::endl;   // here i print both player and AI's amount of ships left on board
            std::cout << "Ai has to hit " << AINumofship() << " more ships" << std::endl;   // i allow the player to see the ships the AI has to shoot beacuse that's how battleship usually works 
            std::cout << "-----------------------------" << std::endl;  
            std::cout << "Please input location" << std::endl;
            std::cout << "each row and column is from 0 to 5" << std::endl;
            std::cout << "for eksample (0 0) or (2 5): "; std::cin >> pos1 >> pos2; // gets two inputs and fires at those coordinates
            if (Attack(pos1, pos2)) // registers the attack
            {
                std::cout << "------\n";
                std::cout << "Hit !" << std::endl;
                std::cout << "------\n";
            }
            else
            {
                std::cout << "------------\n";
                std::cout << "Sorry no hit" << std::endl;
                std::cout << "------------\n";
            }
           
            if (0 == Numofship()) {
                break;   // i read online that it was ok to use break if it's used in a short loop where the use of break is obvious.
            }
            AIattack();
            /*system("cls");*/ // can be turned on for less info on screen
            /*std::cout << "Do you want to surrender (y/n)? "; std::cin >> choise;   // you can uncomment this if you just want to see if the program works.
            if (choise == 'y')                                                       // it will alow you to quit the game while playing, i found it annoying since it asks you after every input.
                break;*/
        }
        std::cout << "Game over!" << std::endl;
        makeEmptyBoard();
        system("pause");
    }
    else if (input == 3) {
        std::cout << "now quiting game" << std::endl;
    }
    return(0);
}





