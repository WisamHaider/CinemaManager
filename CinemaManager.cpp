//
// Created by Wisam Haider on 11/06/2026.
//

#include "CinemaManager.h"
#include <iostream>
using namespace std;


CinemaManager::CinemaManager()
{
    addDefaultFilms();
    initializeScreens();
}

void CinemaManager::addDefaultFilms()
{
    films.push_back(Film("Avengers Endgame", "The final battle against Thanos", "Action",
        "12A", 181, "Robert Downey Jr.", "Marvel Studios", "26/04/2019"));

    films.push_back(Film("Interstellar", "A journey through space and time", "Space",
        "12A", 169, "Matthew McConaughey", "Warner Bros", "07/11/2014"));

    films.push_back(Film("Batman", "The Dark Knight rises", "Action",
        "15", 176, "Christian Bale", "Warner Bros", "20/07/2012"));
}

void CinemaManager::displayFilms()
{
    cout << "Available Films\n\n";

    for (int i = 0; i < films.size(); i++)
    {
        cout << "\n" << i + 1 << ". " << films[i].getTitle() << endl;
        cout << "   Genre: " << films[i].getGenre() << " | Certificate: " << films[i].getCertificate() << endl;
        cout << "   Runtime: " << films[i].getLength() << " mins | Star: " << films[i].getMainStar() << endl;
    }
}

void CinemaManager::createBooking()
{
    displayFilms();

    cout << "\nSelect film: ";
    int filmChoice = getValidIntInput(1, films.size());

    for (int i = 0; i < screens.size(); i++)
    {
        if (screens[i].getScreenNo() == filmChoice)
        {
            screens[i].displayScreenInfo();
            break;
        }
    }

    cin.ignore();

    string customerName;
    cout << "Customer name: ";
    getline(cin, customerName);

    string bookingDate;
    cout << "Booking date: ";
    getline(cin, bookingDate);

    string bookingTime;
    cout << "Booking time: ";
    getline(cin, bookingTime);

    cout << "\nAdult tickets: ";
    int adultTickets = getValidIntInput(0, 100);

    cout << "Child tickets: ";
    int childTickets = getValidIntInput(0, 100);

    cout << "Student tickets: ";
    int studentTickets = getValidIntInput(0, 100);

    cout << "Senior tickets: ";
    int seniorTickets = getValidIntInput(0, 100);

    cin.ignore();

    string paymentMethod;
    cout << "\nPayment method (cash/card): ";
    cin >> paymentMethod;

    while (paymentMethod != "cash" && paymentMethod != "card")
    {
        cout << "Invalid payment type. Please enter 'cash' or 'card': ";
        cin >> paymentMethod;
    }

    Booking booking(customerName, films[filmChoice - 1].getTitle(), bookingDate,
                   bookingTime, adultTickets, childTickets, studentTickets, seniorTickets, paymentMethod);

    double total = booking.calculateTotal();

    cout << "\nBooking Summary" << endl;

    cout << "Customer: " << booking.getCustomerName() << endl;
    cout << "Film: " << booking.getFilmTitle() << endl;
    cout << "Date: " << booking.getBookingDate() << endl;
    cout << "Time: " << booking.getBookingTime() << endl;

    cout << "Total Cost: " << total << endl;

    if (paymentMethod == "cash")
    {
        cout << "Cash received: ";
        double cashPaid = getValidDoubleInput();

        while (cashPaid < total)
        {
            cout << "Insufficient cash. Enter amount again: ";
            cashPaid = getValidDoubleInput();
        }

        cout << "Change: " << cashPaid - total << endl;
    }
    else if (paymentMethod == "card")
    {
        string cardNumber;
        string cvc;
        string expiry;

        cout << "Card Number: ";
        cin >> cardNumber;

        cout << "CVC: ";
        cin >> cvc;

        cout << "Expiry Date: ";
        cin >> expiry;

        cout << "Card payment approved.\n";
    }

    cout << "\nBooking completed successfully.\n";
}
Film* CinemaManager::getFilmByTitle(string title)
{
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].getTitle() == title)
            return &films[i];
    }
    return nullptr;
}

void CinemaManager::initializeScreens()
{
    screens.push_back(Screen(1, "Standard", 100));
    screens.push_back(Screen(2, "IMAX", 80));
    screens.push_back(Screen(3, "Premium IMAX", 60));
}

void CinemaManager::displayAllScreens()
{
    cout << "\nCinema Screens" << endl;

    for (int i = 0; i < screens.size(); i++)
        screens[i].displayScreenInfo();
}

void CinemaManager::allocateFilmToScreen(int screenNo, Film* film)
{
    for (int i = 0; i < screens.size(); i++)
    {
        if (screens[i].getScreenNo() == screenNo)
        {
            screens[i].allocateFilm(film);
            return;
        }
    }
    cout << "Screen not found :(" << endl;
}

int CinemaManager::getValidIntInput(int min, int max)
{
    int value;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
    }
    return value;
}

double CinemaManager::getValidDoubleInput()
{
    double value;
    while (!(cin >> value) || value < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a valid amount: ";
    }
    return value;
}