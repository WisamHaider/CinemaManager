//
// Created by Wisam Haider on 11/06/2026.
//

#include "CinemaManager.h"
#include <iostream>
using namespace std;


CinemaManager::CinemaManager()
{
    addDefaultFilms();
}

void CinemaManager::addDefaultFilms()
{
    films.push_back(Film("Avengers Endgame", "Action", 181));

    films.push_back(Film("Interstellar", "Space", 169));

    films.push_back(Film("Batman", "Action", 176));
}

void CinemaManager::displayFilms()
{
    cout << "Available Films\n\n";

    for (int i = 0; i < films.size(); i++)
    {
        cout << i + 1 << ". "
             << films[i].getTitle()
             << " | Genre: "
             << films[i].getGenre()
             << " | Runtime: "
             << films[i].getLength()
             << " mins\n";
    }
}

void CinemaManager::createBooking()
{
    int filmChoice;

    string customerName;
    string bookingDate;
    string bookingTime;

    int adultTickets = 0;
    int childTickets = 0;
    int studentTickets = 0;
    int seniorTickets = 0;

    string paymentMethod;

    displayFilms();

    cout << "\nSelect film: ";
    while (!(cin >> filmChoice) || filmChoice < 1 || filmChoice > films.size())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid film selection. Try again: ";
    }

    cin.ignore();

    cout << "Customer name: ";
    getline(cin, customerName);

    cout << "Booking date: ";
    getline(cin, bookingDate);

    cout << "Booking time: ";
    getline(cin, bookingTime);

    cout << "\nAdult tickets: ";
    while (!(cin >> adultTickets) || adultTickets < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Adult tickets: ";
    }

    cout << "Child tickets: ";
    while (!(cin >> childTickets) || childTickets < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Child tickets: ";
    }

    cout << "Student tickets: ";
    while (!(cin >> studentTickets) || studentTickets < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Student tickets: ";
    }

    cout << "Senior tickets: ";
    while (!(cin >> seniorTickets) || seniorTickets < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Senior tickets: ";
    }

    cin.ignore();

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

    cout << "\nBooking Summary\n";

    cout << "Customer: " << booking.getCustomerName() << endl;
    cout << "Film: " << booking.getFilmTitle() << endl;
    cout << "Date: " << booking.getBookingDate() << endl;
    cout << "Time: " << booking.getBookingTime() << endl;

    cout << "Total Cost: " << total << endl;

    if (paymentMethod == "cash")
    {
        double cashPaid;

        cout << "Cash received: ";
        while (!(cin >> cashPaid) || cashPaid < 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Cash received: £";
        }

        while (cashPaid < total)
        {
            cout << "Insufficient cash.\n";
            cout << "Enter cash amount again: £";
            cin >> cashPaid;
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