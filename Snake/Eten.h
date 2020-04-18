//
// Created by ruben on 27/03/2020.
//

#ifndef SNAKE_ETEN_H
#define SNAKE_ETEN_H
#include <cstdlib>
#include <ctime>


class Eten {
    private:
        int locatieX, locatieY;
    public:
        Eten() {
            unsigned seed = time(0);
            srand(seed);
            int random = rand() % 14 + 1;

            locatieX = random;

            unsigned seed2 = time(0);
            srand(seed);
            int random2 = rand() % 14 + 1;

            locatieY = random2;
        }

    int getLocatieX() const {
        return locatieX;
    }

    int getLocatieY() const {
        return locatieY;
    }

};


#endif //SNAKE_ETEN_H
