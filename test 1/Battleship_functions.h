#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

const int rows = 6;
const int columns = 6;

char board[rows][columns];
char Pboard[rows][columns];

int maxships = 11; // here is the max ships that both AI and player can have

void Clear();
void makeEmptyBoard();
void Pshow();
void setships();
int Numofship();
bool Attack(int x, int y);

void Clear() { // resets board
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            board[i][j] = '0';
            Pboard[i][j] = '0';

        }
    }
}

void makeEmptyBoard() { // creates the board
    for (int M = 0; M < rows; M++)
    {
        for (int N = 0; N < columns; N++)
        {
            std::cout << "|" << board[M][N];
        }
        std::cout << std::endl;
    }
}

int Numofship() { // adds ships
    int c = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            if (board[i][j] == 'S') {
                c++;
            }

        }
    }
    return c;
}

void setships() { //places ships
    int s = 0;
    while (s < maxships) {
        int x = rand() % rows;
        int y = rand() % columns;
        if (board[x][y] != 'S') {
            s++;
            board[x][y] = 'S';
        }
    }
}

bool Attack(int x, int y) {
    if (board[x][y] == 'S') {
        board[x][y] = 'h';
        Pboard[x][y] = 'h'; 
        return true;
    }
    else if (board[x][y] == '0') {
        board[x][y] = 'm';
        Pboard[x][y] = 'm';
        return(false);
    }
    return false;
}

void Pshow() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << "|" << Pboard[i][j];
        }
        std::cout << std::endl;
    }
}
