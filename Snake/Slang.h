//
// Created by ruben on 27/03/2020.
//

#ifndef SNAKE_SLANG_H
#define SNAKE_SLANG_H


class Slang {private:
    int lengte;
    int snelheid;
    int locatieX;
    int locatieY;

public:
    Slang() {
        Slang::lengte = 2;
        Slang::snelheid = 1;
        Slang::locatieX = 7;
        Slang::locatieY = 7;
    }

    Slang(int lengte, int snelheid, int locatieX, int locatieY){
        Slang::lengte = lengte;
        Slang::snelheid = snelheid;
        Slang::locatieX = locatieX;
        Slang::locatieY = locatieY;
    }

    void setLengte(int lengte) {
        Slang::lengte = lengte;
    }

    void setSnelheid(int snelheid) {
        Slang::snelheid = snelheid;
    }

    void setLocatieX(int locatieX) {
        Slang::locatieX = locatieX;
    }

    void setLocatieY(int locatieY) {
        Slang::locatieY = locatieY;
    }

    int getLengte() const {
        return lengte-1;
    }

    int getSnelheid() const {
        return snelheid;
    }

    int getLocatieX() const {
        return locatieX;
    }

    int getLocatieY() const {
        return locatieY;
    }

};


#endif //SNAKE_SLANG_H
