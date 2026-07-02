//
// Created by Wisam Haider on 14/06/2026.
//

#include "Screen.h"
#include <iostream>

using namespace std;

// Default Constructor
Screen::Screen(){
    screenNo = 0;
    facility = "";
    maxSeats = 0;
    availableSeats = 0;
    currentFilm = nullptr;
}

// Parameterized Constructor
Screen::Screen(int no, string fac, int max){
    screenNo = no;
    facility = fac;
    maxSeats = max;
    availableSeats = max;
    currentFilm = nullptr;
}

// Getters
int Screen::getScreenNo(){
    return screenNo;
}

string Screen::getFacility(){
    return facility;
}

int Screen::getMaxSeats(){
    return maxSeats;
}

int Screen::getAvailableSeats(){
    return availableSeats;
}

Film* Screen::getCurrentFilm(){
    return currentFilm;
}

vector<string> Screen::getShowtimes(){
    return showtimes;
}

// Setters
void Screen::setScreenNo(int no){
    screenNo = no;
}

void Screen::setFacility(string fac){
    facility = fac;
}

void Screen::setCurrentFilm(Film* film){
    currentFilm = film;
}

void Screen::setAvailableSeats(int seats){
    availableSeats = seats;
}

// Allocate film to screen and calculate showtimes
void Screen::allocateFilm(Film* film){
    currentFilm = film;
    availableSeats = maxSeats; // Reset available seats
    calculateShowtimes();
}

// Calculate showtimes based on film length
void Screen::calculateShowtimes(){
    showtimes.clear();

    if (currentFilm == nullptr) return;

    int filmLength = currentFilm->getLength();
    int timePerShowing = filmLength + 25; // 25 min gap
    int cinemaOpenTime = 10 * 60; // 10:00 AM in minutes
    int earliestShowTime = 10 * 60 + 15; // 10:15 AM in minutes
    int cinemaCloseTime = 23 * 60 + 30; // 23:30 (11:30 PM) in minutes
    int startTime = earliestShowTime;

    int currentTime = startTime;

    while (currentTime + filmLength <= cinemaCloseTime){
        int hours = currentTime / 60;
        int minutes = currentTime % 60;

        string timeStr = "";
        if (hours < 10) timeStr += "0";
        timeStr += to_string(hours) + ":";
        if (minutes < 10) timeStr += "0";
        timeStr += to_string(minutes);

        showtimes.push_back(timeStr);
        currentTime += timePerShowing;
    }
}

// Display screen information
void Screen::displayScreenInfo(){
    cout << "\nScreen " << screenNo << endl;
    cout << "Facility: " << facility << endl;
    cout << "Max Seats: " << maxSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;

    if (currentFilm != nullptr){
        cout << "Current Film: " << currentFilm->getTitle() << endl;
        cout << "Showtimes: ";
        for (int i = 0; i < showtimes.size(); i++){
            cout << showtimes[i];
            if (i < showtimes.size() - 1) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "No film scheduled" << endl;
    }
}

// Book seats
void Screen::bookSeats(int numSeats){
    if (numSeats <= availableSeats){
        availableSeats -= numSeats;
    } else {
        cout << "Not enough seats available!" << endl;
    }
}

// Release seats (cancellation)
void Screen::releaseSeats(int numSeats){
    if (availableSeats + numSeats <= maxSeats){
        availableSeats += numSeats;
    }
}