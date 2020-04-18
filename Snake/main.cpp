#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Slang.h"
#include "Eten.h"

void drukVeldAf(char veld[15][15]){

    //Bord aanmaken
    for (int x = 0; x < 15; ++x) {
        for (int y = 0; y < 15; ++y) {

            std::cout << veld[x][y] << ' ';
        }

        std::cout << std::endl;
    }

}

void plaatsSlang(char veld[15][15], Slang slang){

    //Slang op bord zetten
    veld[slang.getLocatieX()][slang.getLocatieY()] = 'S';
    veld[slang.getLocatieX()][slang.getLocatieY()-1] = 'S';

}

void verplaatsSlangUp(char veld[15][15], Slang slang){

    veld[slang.getLocatieX()][slang.getLocatieY()] = 'S';

    if (veld[slang.getLocatieX()+1][slang.getLocatieY()-1] != 'X'){
    veld[slang.getLocatieX()+1][slang.getLocatieY()-1] = 'O';}

    if (veld[slang.getLocatieX()+1][slang.getLocatieY()+1] != 'X'){
    veld[slang.getLocatieX()+1][slang.getLocatieY()+1] = 'O';}

    if (veld[slang.getLocatieX()+2][slang.getLocatieY()] != 'X'){
    veld[slang.getLocatieX()+2][slang.getLocatieY()] = 'O';}
}

void verplaatsSlangDown(char veld[15][15], Slang slang){

    veld[slang.getLocatieX()][slang.getLocatieY()] = 'S';

    if (veld[slang.getLocatieX()-1][slang.getLocatieY()-1] != 'X'){
    veld[slang.getLocatieX()-1][slang.getLocatieY()-1] = 'O';}

    if (veld[slang.getLocatieX()-1][slang.getLocatieY()+1] != 'X'){
    veld[slang.getLocatieX()-1][slang.getLocatieY()+1] = 'O';}

    if (veld[slang.getLocatieX()-2][slang.getLocatieY()] != 'X'){
    veld[slang.getLocatieX()-2][slang.getLocatieY()] = 'O';}
}

void verplaatsSlangLeft(char veld[15][15], Slang slang){

    veld[slang.getLocatieX()][slang.getLocatieY()] = 'S';

    if (veld[slang.getLocatieX()-1][slang.getLocatieY()+1] != 'X'){
    veld[slang.getLocatieX()-1][slang.getLocatieY()+1] = 'O';}

    if (veld[slang.getLocatieX()][slang.getLocatieY()+2] != 'X'){
    veld[slang.getLocatieX()][slang.getLocatieY()+2] = 'O';}

    if (veld[slang.getLocatieX()+1][slang.getLocatieY()+1] != 'X'){
    veld[slang.getLocatieX()+1][slang.getLocatieY()+1] = 'O';}

}

void verplaatsSlangRight(char veld[15][15], Slang slang){

    veld[slang.getLocatieX()][slang.getLocatieY()] = 'S';

    if (veld[slang.getLocatieX()][slang.getLocatieY()-2] != 'X'){
    veld[slang.getLocatieX()][slang.getLocatieY()-2] = 'O';}

    if (veld[slang.getLocatieX()+1][slang.getLocatieY()-1] != 'X'){
    veld[slang.getLocatieX()+1][slang.getLocatieY()-1] = 'O';}

    if (veld[slang.getLocatieX()-1][slang.getLocatieY()-1] != 'X') {
    veld[slang.getLocatieX()-1][slang.getLocatieY()-1] = 'O';}
}

void plaatsEten(char veld[15][15], Eten eten){
    veld[eten.getLocatieX()][eten.getLocatieY()] = 'X';
}

int main() {
    Slang slang1 = Slang();

    char veld[15][15];
    for (int x = 0; x < 15; ++x) {
            for (int y = 0; y < 15; ++y) {

                veld[x][y] = 'O';
            }
    }

    plaatsSlang(veld, slang1);

    Eten eten1 = Eten();
    if (eten1.getLocatieY() == 'S' && eten1.getLocatieX() == 'S') {
        eten1 = Eten();
    } else {
        plaatsEten(veld, eten1);
    }

    int score = 0;
    std::cout << "          Score: " << score << std::endl;
    drukVeldAf(veld);

    char keuze;

    while (keuze != 'S'){
        std::cout << "---------------" << std::endl;
        std::cout << "Kies een kant: ";
        std::cin >> keuze;
        std::cout << "---------------" << std::endl;
        switch (keuze){
            case 'u':
                slang1.setLocatieX(slang1.getLocatieX()-1);
                verplaatsSlangUp(veld, slang1);
                break;
            case 'd':
                slang1.setLocatieX(slang1.getLocatieX()+1);
                verplaatsSlangDown(veld, slang1);
                break;
            case 'l':
                slang1.setLocatieY(slang1.getLocatieY()-1);
                verplaatsSlangLeft(veld, slang1);
                break;
            case 'r':
                slang1.setLocatieY(slang1.getLocatieY()+1);
                verplaatsSlangRight(veld, slang1);
                break;
        }

        if (slang1.getLocatieY() == eten1.getLocatieY() && slang1.getLocatieX() == eten1.getLocatieX()){
            score += 10;
            eten1 = Eten();
            if (eten1.getLocatieY() == 'S' && eten1.getLocatieX() == 'S') {
                eten1 = Eten();
            } else {
                plaatsEten(veld, eten1);
            }
        }

        system("cls");
        std::cout << "          Score: " << score << std::endl;
        drukVeldAf(veld);

    }

    return 0;

}
