#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <fstream>

//enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};  // the problems i've had with the password is probably me using code im not very familiar with for eksample (enum)
//eDirecton dir;

void passwordMap();
//void pinput();
//void Logic();

const int width = 4;
const int height = 4;
int x = 0;
int y = 0;


char psboard[width][height] = {
               { 'a', 'b', 'c', 'd' },
               { 'e', 'f', 'g', 'h' },
               { 'i', 'j', 'k', 'l' },
               { 'm', 'n', 'o', 'p' }
};

void passwordMap() {

    for (int i = 0; i < width; i++) {
        std::cout << "\n";
        for (int j = 0; j < height; j++) {
            
            std::cout << "|" << psboard[i][j];

        }
    }
}

void readFromFile() {

}

void Move() {
    char pmark = '#';
    int save=0;
    std::string Passcode[20];
    std::string code = "dddsssaaa";
    char movement;

    while (1) {
        psboard[x][y] = pmark;
        std::cout << "\n---------\n";
        passwordMap();
        std::cout << "\n";
        std::cin >> movement;
        if (movement == 'a') {
            y--;
            if (y < 0) {
                y = 0;
            }
            //Passcode[save] = 'a';
            //save++;
        }else if (movement == 'd') {
            y++;
            if (y > 4) {
                y = 4;
            }
            //Passcode[save] = 'd';
            //save++;
        }else if (movement == 'w') {
            x--;
            if (x < 0) {
                x = 0;
            }
            //Passcode[save] = 'w';
            //save++;
        }else if (movement == 's') {
            x++;
            if (x > 4) {
                x = 4;
            }
            //Passcode[save] = 's';
            //save++;
        }
        if (psboard[0][0] == pmark && psboard[0][1] == pmark && psboard[0][2] == pmark && psboard[0][3] == pmark && // i don't know why, but after you have entered the password you have to press 
            psboard[1][3] == pmark && psboard[2][3] == pmark && psboard[3][3] == pmark && psboard[3][2] == pmark && // 'a' one more time to confirm.
            psboard[3][1] == pmark && psboard[3][0] == pmark &&
            psboard[1][0] != pmark && psboard[1][1] != pmark && psboard[1][2] != pmark && psboard[2][0] != pmark &&
            psboard[2][1] != pmark && psboard[2][2] != pmark)
        {
            break;

        }
    } 
}
//void pinput() {            //this was supposed to take the users input and then change the map, but it wouldn't work
//    if (_kbhit()) {        // _kbhit means keyboard hit, wich i think should register that the player is pressing the keyboard but,  i didn't manage to do it 
//        switch (_getch()) {
//        case 'a':
//            dir = LEFT;
//            break;
//        case 'd':
//            dir = RIGHT;
//            break;
//        case 'w':
//            dir = UP;
//            break;
//        case 's':
//            dir = DOWN;
//            break;
//        }
//    }
//}
//void Logic() {            // after reciving a direction from the function above it would then go down here, where it would change the players symbol to form the password.
//    switch (dir) 
//    {
//    case  LEFT:
//        x--;
//        break;
//    case  UP:
//        y--;
//        break;
//    case  RIGHT:
//        x++;
//        break;
//    case  DOWN:
//        y++;
//        break;
//    default:
//        break;
//    }
//}