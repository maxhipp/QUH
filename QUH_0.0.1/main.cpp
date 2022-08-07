/*
    -----------------------------------------------------------------------------------
    QUH by Max Hipp 2022
    -----------------------------------------------------------------------------------
    Move all numbers to the marked spot!


    TODO:
    Basic:
     - square with x fields in each direction
     - numbers from 1 to x
     - different actions based on two numbers next to each other
     - odd or even, primes, size difference, same number
    Advanced:
     - graphical user interface instead of console appilcation
     - levels with obstacles you need to move around
     - time mode
    Exquisit:
     - multiplayer mode
    -----------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <iostream>

using namespace std;

struct game {
    int pos1 = 11;
    int pos2 = 22;
    int dif = 11;
    bool run = true;
    bool state = false;
    int quh[8][8];
}game;

void initializeQuh() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            do
            {
                game.quh[i][j] = rand() % 10;
            } while (game.quh[i][j] == 0);
        }
    }
}

void printQuh() {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << " " << game.quh[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void step() {
    cout << "\n";
    
    cout << "\n";
}

bool checkPrime(int num) {
    int pd = game.quh[num / 10][num % 10];
    if (pd == 2 | pd == 3 | pd == 5 | pd == 7 )
    {
        cout << "prime ";
        return true;
    }
    return false;
}

bool checkOdd(int num) {
    if (game.quh[num / 10][num % 10] % 2 == 1)
    {
        cout << "odd ";
        return true;
    }
    else
    {
        cout << "even ";
        return false;
    }
}

bool checkSame(int num1, int num2) {
    if (game.quh[num1 / 10][num1 % 10] == game.quh[num2 / 10][num2 % 10])
    {
        cout << "same ";
        return true;
    }
    return false;
}

void playQuh() {
    do
    {
        cout << "First position: ";
        cin >> game.pos1 >> game.pos2;
        cout << game.pos1 << " | " << game.pos2 << "\n";
        game.dif = game.pos1 - game.pos2;
        switch (game.dif)
        {
        case 1: cout << "case 1\n";
            game.state = true;
            break;
        case 10: cout << "case 10\n";
            game.state = true;
            break;
        case -1: cout << "case -1\n";
           game.state = true;
            break;
        case -10: cout << "case -10\n";
            game.state = true;
            break;
        default: cout << "Invalid numbers! Please try again.\n";
            game.state = false;
            break;
        }
    } while (game.state == false);
    checkOdd(game.pos1);
    checkOdd(game.pos2);
    cout << "\n";
}

int main()
{
    cout << "Starting...\n";
    initializeQuh();
    cout << "Loaded...\n";
    printQuh();
    cout << "Please make your first move by typing the coordinates of the two numbers in the console (e.g.: 43 44).\nPlease note that the numbers have to be next to each other vertically or horizontally.\n";
    while (game.run == true)
    {
        playQuh();
    }
    cout << "\n\n";
    return 0;
}
