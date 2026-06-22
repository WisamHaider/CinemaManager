//
// Created by Wisam Haider on 11/06/2026.
//

#ifndef INC_453STAGES_CINEMAMANAGER_H
#define INC_453STAGES_CINEMAMANAGER_H

#include <vector>
#include "Film.h"
#include "Booking.h"

using namespace std;

class CinemaManager
{
private:
    vector<Film> films;

public:
    CinemaManager();

    void addDefaultFilms();

    void displayFilms();

    void createBooking();
};

#endif
