#pragma once




char AIboard[rows][columns];



void AIClear();
void makeAIBoard();
bool AIattack();
void AIsetships();
int AINumofship();

void AIClear() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            AIboard[i][j] = '0';
            

        }
    }
}
void makeAIBoard() {
    for (int M = 0; M < rows; M++)
    {
        for (int N = 0; N < columns; N++)
        {
            std::cout << "|" << AIboard[M][N];
        }
        std::cout << std::endl;
    }
}

void AIsetships() {
    int s = 0;
    while (s < maxships) {
        int x = rand() % rows;   // the AI attacks a random location
        int y = rand() % columns;
        if (AIboard[x][y] != 'S') {
            s++;
            AIboard[x][y] = 'S';
        }
    }
}

bool AIattack() {
    int x = rand() % rows;
    int y = rand() % columns;
    if (AIboard[x][y] == 'S') {
        AIboard[x][y] = 'h';
        return true;
    }
    else if (AIboard[x][y] == '0') {
        AIboard[x][y] = 'm';
        
        return(false);
    }
    return false;
}

int AINumofship() {
    int c = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            if (AIboard[i][j] == 'S') {
                c++;
            }

        }
    }
    return c;
}