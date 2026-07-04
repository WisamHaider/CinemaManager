#include "CinemaManager.h"
#include <iostream>
#include "FileManager.h"

using namespace std;

int main()
{
    FileManager fileManager;
    CinemaManager cinema;
    cout << "Welcome to Cinema Booking System" << endl;
    bool running = true;
    while (running)
    {
        cinema.displayMainMenu();
        int mainChoice;
        cin >> mainChoice;
        if (mainChoice == 1)
        {
            // Staff Mode
            bool staffRunning = true;
            while (staffRunning)
            {
                cinema.displayStaffMenu();
                int staffChoice;
                cin >> staffChoice;

                if (staffChoice == 1)
                {
                    cinema.createBooking();
                }
                else if (staffChoice == 2)
                {
                    cin.ignore();
                    string name;
                    cout << "Enter customer name: ";
                    getline(cin, name);
                    cinema.searchBookingsByName(name);
                }
                else if (staffChoice == 3)
                {
                    cin.ignore();
                    string film;
                    cout << "Enter film title: ";
                    getline(cin, film);
                    cinema.searchBookingsByFilm(film);
                }
                else if (staffChoice == 4)
                {
                    cin.ignore();
                    string date;
                    cout << "Enter date (DD/MM/YYYY): ";
                    getline(cin, date);
                    cinema.searchBookingsByDate(date);
                }
                else if (staffChoice == 5)
                {
                    cinema.displayBookingHistory();
                }
                else if (staffChoice == 6)
                {
                    staffRunning = false;
                }
                else{cout << "Invalid choice. Please try again." << endl;}
            }
        }
        else if (mainChoice == 2)
        {
            // Manager Mode
            bool managerRunning = true;
            while (managerRunning)
            {
                cinema.displayManagerMenu();
                int managerChoice;
                cin >> managerChoice;

                if (managerChoice == 1)
                {
                    cinema.managerAddNewFilm();
                }
                else if (managerChoice == 2)
                {
                    cinema.managerCreateWeeklySchedule();
                }
                else if (managerChoice == 3)
                {
                    cinema.displayAllScreens();
                    cout << "\n--- Or view saved schedule: ---" << endl;
                    cinema.displayScheduleFromFile();
                }
                else if (managerChoice == 4)
                {
                    cinema.displayBookingHistory();
                    cout << "\n--- Or view bookings from file: ---" << endl;
                    fileManager.displayBookingsFromFile();
                }
                else if (managerChoice == 5)
                {
                    managerRunning = false;
                }
                else
                {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        else if (mainChoice == 3)
        {
            running = false;
            cout << "\nThank you for using Cinema Booking System. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}