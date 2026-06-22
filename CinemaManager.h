//
// Created by Wisam Haider on 11/06/2026.
//

#ifndef INC_453STAGES_CINEMAMANAGER_H
#define INC_453STAGES_CINEMAMANAGER_H

#include <vector>
#include "Film.h"
#include "screen.h"
#include "Booking.h"

using namespace std;

class CinemaManager
{
private:
    vector<Film> films;
    vector<Screen> screens;

    int getValidIntInput(int min, int max);
    double getValidDoubleInput();
public:
    CinemaManager();

    void addDefaultFilms();
    void displayFilms();
    Film* getFilmByTitle(string title);

    void initializeScreens();
    void displayAllScreens();
    void allocateFilmToScreen(int screenNo, Film* film);

    void createBooking();
};

#endif
