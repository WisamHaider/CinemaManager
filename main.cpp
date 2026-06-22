#include "CinemaManager.h"
#include <iostream>

using namespace std;

int main()
{
    CinemaManager cinema;

    cout << "Welcome to Cinema Booking System" << endl;

    // Allocate films to screens
    cinema.allocateFilmToScreen(1, cinema.getFilmByTitle("Avengers Endgame"));
    cinema.allocateFilmToScreen(2, cinema.getFilmByTitle("Interstellar"));
    cinema.allocateFilmToScreen(3, cinema.getFilmByTitle("Batman"));

    // Create a booking
    cinema.createBooking();

    return 0;
}