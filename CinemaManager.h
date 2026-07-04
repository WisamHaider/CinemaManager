//
// Created by Wisam Haider on 11/06/2026.
//

#ifndef INC_453STAGES_CINEMAMANAGER_H
#define INC_453STAGES_CINEMAMANAGER_H

#include <vector>
#include "Film.h"
#include "Screen.h"
#include "Booking.h"
#include "FileManager.h"
#include "Validation.h"

using namespace std;

class CinemaManager
{
private:
    vector<Film> films;
    vector<Screen> screens;
    vector<Booking> bookingHistory;
    FileManager fileManager;

    int getValidIntInput(int min, int max);
    double getValidDoubleInput();
    string getValidStringInput();

public:
    CinemaManager();

    // Film Management
    void addDefaultFilms();
    void displayFilms();
    Film* getFilmByTitle(string title);

    // Screen Management
    void initializeScreens();
    void scheduleFilmsToScreens();
    void displayScreensForFilm(string filmTitle);
    void displayAllScreens();

    // Booking Management
    void createBooking();
    void saveBookingToHistory(Booking booking);
    void displayBookingHistory();
    void searchBookingsByName(string name);
    void searchBookingsByFilm(string film);
    void searchBookingsByDate(string date);

    // Manager Functions
    void managerAddNewFilm();
    void managerCreateWeeklySchedule();
    void displayMainMenu();
    void displayStaffMenu();
    void displayManagerMenu();

    void displayScheduleFromFile();
};

#endif