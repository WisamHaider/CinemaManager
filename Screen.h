//
// Created by Wisam Haider on 14/06/2026.
//

#ifndef INC_453STAGES_SCREEN_H
#define INC_453STAGES_SCREEN_H

#include <string>
#include <vector>
#include "Film.h"

using namespace std;

class Screen
{
private:
    int screenNo;
    string facility; // "Standard", "IMAX"
    int maxSeats;
    int availableSeats;
    Film* currentFilm;
    vector<string> showtimes;
    vector<string> showEndTimes;

public:
    // Constructors
    Screen();
    Screen(int no, string fac, int max);

    // Getters
    int getScreenNo();
    string getFacility();
    int getMaxSeats();
    int getAvailableSeats();
    Film* getCurrentFilm();
    vector<string> getShowtimes();
    vector<string> getShowEndTimes();

    // Setters
    void setScreenNo(int no);
    void setFacility(string fac);
    void setCurrentFilm(Film* film);
    void setAvailableSeats(int seats);

    // Methods
    void allocateFilm(Film* film);
    void calculateShowtimes();
    void displayScreenInfo();
    void bookSeats(int numSeats);
    void releaseSeats(int numSeats);
};

#endif
