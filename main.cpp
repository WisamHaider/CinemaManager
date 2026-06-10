#include <iostream>
#include <vector>
#include "Film.h"
#include "Booking.h"

using namespace std;

void displayFilms(vector<Film>& films)
{
    cout << "Available Films \n\n";

    for (int i = 0; i < films.size(); i++)
    {
        cout << i + 1 << ". "<< films[i].getTitle() << " | Genre: " << films[i].getGenre()
             << " | Runtime: " << films[i].getLength() << " mins\n";
    }
}

int main() {
    vector<Film> films;

    films.push_back(Film("Avengers Endgame","Action",181));

    films.push_back(Film("Interstellar","Space",169));

    films.push_back(Film("Batman","Action",176));

    int filmChoice;
    string customerName;
    string bookingDate;
    string bookingTime;

    int adultTickets;
    int childTickets;
    int studentTickets;
    int seniorTickets;

    string paymentMethod;


    displayFilms(films);

    cout << "\nSelect film: ";
    cin >> filmChoice;

    // Validation
    while (filmChoice < 1 || filmChoice > films.size())
    {
        cout << "Invalid film selection. Try again: ";cin >> filmChoice;
    }

    cin.ignore();

    cout << "Customer name: ";
    getline(cin, customerName);

    cout << "Booking date: ";
    getline(cin, bookingDate);

    cout << "Booking time: ";
    getline(cin, bookingTime);

    cout << "\nAdult tickets: ";
    cin >> adultTickets;

    cout << "Child tickets: ";
    cin >> childTickets;

    cout << "Student tickets: ";
    cin >> studentTickets;

    cout << "Senior tickets: ";
    cin >> seniorTickets;


    while (adultTickets < 0 ||childTickets < 0 ||studentTickets < 0 ||seniorTickets < 0)
    {
        cout << "Ticket numbers cannot be negative.\n";

        cout << "Adult tickets: ";
        cin >> adultTickets;

        cout << "Child tickets: ";
        cin >> childTickets;

        cout << "Student tickets: ";
        cin >> studentTickets;

        cout << "Senior tickets: ";
        cin >> seniorTickets;
    }

    cout << "\nPayment method (cash/card): ";
    cin >> paymentMethod;

    Booking booking(
        customerName,
        films[filmChoice - 1].getTitle(),
        bookingDate,
        bookingTime,
        adultTickets,
        childTickets,
        studentTickets,
        seniorTickets,
        paymentMethod
    );

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

        cout << "Cash received: £";
        cin >> cashPaid;

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
    else
    {
        cout << "Invalid payment type.\n";
    }

    cout << "\nBooking completed successfully.\n";

    return 0;
}