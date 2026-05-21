# IY453 Software Design and Implementation

## Contents:

- Introduction

- Analysis and Design
  
  - First Stage: Outline program specification.
  
  - Second Stage: Indentify inputs, output, and processes.
  
  - Third Stage: Algorithm.

- References

## Introduction

The aim of the program is to create a cinema booking system made for the staff, to put very simply it will be used to handle the booking, the movie schedule and generate reports for the managers and staff at the cinema. The system will be written in C++17 or later and feature memory saved in csv files locally with a simple GUI.

#### First Stage:

###### Core program functions:

- Handle ticket booking:
  
  - Take information such as the ticket type, (adult, child, student, senior), film name, time booked.

- Cinema room and seating handling:
  
  - After information is taken properly display the available seats (allow selection) and displayed within the corresponding screen respective of the film.

- Allow managers to enter film details and generate a weekly schedule:
  
  - Ensure the system allows the manager to pick and choose the times within the time the cinema is open.

- Memory:
  
  - Save the schedule of each week, and save the bookings by all the customers, along with that allow customers to search from the schedule so they can find the film and at what time they would like to choose.

###### System Limitations and rules

**Passenger types**: There are 4 types, adult, student, senior and child.

**Screens**: There are only 5 screens of varying number of seatings.

**Gaps**: There will be a 25 minute gap between each movie to clean.

**Schedule**: Movies can only show within the open times of the cinema from 10 - 23:30 and the first showing can be at 10:15.

**Prices and movies**: Set from a given data set.

#### Second stage:

![](C:\Users\Wisam%20Haider\AppData\Roaming\marktext\images\2026-05-21-10-13-24-2026-05-16-14-43-51-IPO.png)

#### Third stage:

IN PROGRESS



<style>
</style>

# Appendix Code listing

**Main.cpp**

**#include
<iostream>  
#include <vector>  
#include "Film.h"  
#include "Booking.h"  

using namespace std;  

void displayFilms(vector<Film>& films)  
{  
    cout << "Available Films
\n\n";  

    for (int i = 0; i < films.size();
i++)  
    {  
        cout << i + 1 <<
". "  
             << films[i].getTitle()  
             << " | Genre:
" << films[i].getGenre()  
             << " | Runtime:
" << films[i].getLength()  
             << "
mins\n";  
    }  
}  

int main() {  
    vector<Film> films;  

    films.push_back(Film(  
        "Avengers Endgame",  
        "Action",  
        181  
    ));  

    films.push_back(Film(  
        "Interstellar",  
        "Space",  
        169  
    ));  

    films.push_back(Film(  
        "Batman",  
        "Action",  
        176  
    ));  

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

    cout << "\nSelect film:
";  
    cin >> filmChoice;  

    // Validation  
    while (filmChoice < 1 ||
filmChoice > films.size())  
    {  
        cout << "Invalid film
selection. Try again: ";  
        cin >> filmChoice;  
    }  

    cin.ignore();  

    cout << "Customer name:
";  
    getline(cin, customerName);  

    cout << "Booking date:
";  
    getline(cin, bookingDate);  

    cout << "Booking time:
";  
    getline(cin, bookingTime);  

    cout << "\nAdult tickets:
";  
    cin >> adultTickets;  

    cout << "Child tickets:
";  
    cin >> childTickets;  

    cout << "Student tickets:
";  
    cin >> studentTickets;  

    cout << "Senior tickets:
";  
    cin >> seniorTickets;  

    while (adultTickets < 0 ||  
           childTickets < 0 ||  
           studentTickets < 0 ||  
           seniorTickets < 0)  
    {  
        cout << "Ticket
numbers cannot be negative.\n";  

        cout << "Adult
tickets: ";  
        cin >> adultTickets;  

        cout << "Child
tickets: ";  
        cin >> childTickets;  

        cout << "Student
tickets: ";  
        cin >> studentTickets;  

        cout << "Senior
tickets: ";  
        cin >> seniorTickets;  
    }  

    cout << "\nPayment method
(cash/card): ";  
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

    double total =
booking.calculateTotal();  

    cout << "\n===== BOOKING
SUMMARY =====\n";  

    cout << "Customer: "
<< booking.getCustomerName() << endl;  
    cout << "Film: "
<< booking.getFilmTitle() << endl;  
    cout << "Date: "
<< booking.getBookingDate() << endl;  
    cout << "Time: "
<< booking.getBookingTime() << endl;  

    cout << "Total Cost:
£" << total << endl;  

    if (paymentMethod ==
"cash")  
    {  
        double cashPaid;  

        cout << "Cash
received: £";  
        cin >> cashPaid;  

        while (cashPaid < total)  
        {  
            cout <<
"Insufficient cash.\n";  
            cout << "Enter
cash amount again: £";  
            cin >> cashPaid;  
        }  

        cout << "Change:
£" << cashPaid - total << endl;  
    }  
    else if (paymentMethod ==
"card")  
    {  
        string cardNumber;  
        string cvc;  
        string expiry;  

        cout << "Card Number:
";  
        cin >> cardNumber;  

        cout << "CVC: ";  
        cin >> cvc;  

        cout << "Expiry Date:
";  
        cin >> expiry;  

        cout << "Card payment
approved.\n";  
    }  
    else  
    {  
        cout << "Invalid
payment type.\n";  
    }  

    cout << "\nBooking
completed successfully.\n";  

    return 0;  
}**

**Booking.h**

**//  
// Created by Wisam Haider on 21/05/2026.  
//  

#ifndef INC_453STAGES_BOOKING_H  
#define INC_453STAGES_BOOKING_H  

#include <string>  

using namespace std;  

class Booking  
{  
private:  
    string customerName;  
    string filmTitle;  
    string bookingDate;  
    string bookingTime;  

    int adultTickets;  
    int childTickets;  
    int studentTickets;  
    int seniorTickets;  

    string paymentMethod;  

public:  

    // Constructors  

    Booking();  
    Booking(string customer,  
            string film,  
            string date,  
            string time,  
            int adult,  
            int child,  
            int student,  
            int senior,  
            string payment);  

    // Methods  

    double calculateTotal();  

    // Getters  

    string getCustomerName();  
    string getFilmTitle();  
    string getBookingDate();  
    string getBookingTime();  
};  

#endif**

**Booking.cpp**

**//  
// Created by Wisam Haider on 21/05/2026.  
//  

#include "Booking.h"  

// Default Constructor  

Booking::Booking()  
{  
    customerName = "";  
    filmTitle = "";  
    bookingDate = "";  
    bookingTime = "";  

    adultTickets = 0;  
    childTickets = 0;  
    studentTickets = 0;  
    seniorTickets = 0;  

    paymentMethod = "";  
}  

Booking::Booking(string customer,  
                 string film,  
                 string date,  
                 string time,  
                 int adult,  
                 int child,  
                 int student,  
                 int senior,  
                 string payment)  
{  
    customerName = customer;  
    filmTitle = film;  
    bookingDate = date;  
    bookingTime = time;  

    adultTickets = adult;  
    childTickets = child;  
    studentTickets = student;  
    seniorTickets = senior;  

    paymentMethod = payment;  
}  

// Calculate Total Cost  
double Booking::calculateTotal()  
{  
    double total = 0;  

    total += adultTickets * 9.50;  
    total += childTickets * 5.50;  
    total += studentTickets * 7.00;  
    total += seniorTickets * 6.50;  

    return total;  
}  

// Getters  

string Booking::getCustomerName(){  
    return customerName;  
}  
string Booking::getFilmTitle(){  
    return filmTitle;  
}  
string Booking::getBookingDate(){  
    return bookingDate;  
}  
string Booking::getBookingTime(){  
    return bookingTime;  
}**

**Film.h**

**//  
// Created by Wisam Haider on 21/05/2026.  
//  

#ifndef INC_453STAGES_FILM_H  
#define INC_453STAGES_FILM_H  

#include <string>  

using namespace std;  

class Film  
{  
private:  
    string title;  
    string genre;  
    int length;  

public:  
    // Constructors  

    Film();  
    Film(string t, string g, int l);  

    // Getters  

    string getTitle();  
    string getGenre();  
    int getLength();  

    // Setters  

    void setTitle(string t);  
    void setGenre(string g);  
    void setLength(int l);  
};  

#endif**

**Film.cpp**

**//  
// Created by Wisam Haider on 21/05/2026.  
//  

#include "Film.h"  

// Default Constructor  
Film::Film(){  
    title = "";  
    genre = "";  
    length = 0;  
}  

Film::Film(string t, string g, int l){  
    title = t;  
    genre = g;  
    length = l;  
}  

// Getters  
string Film::getTitle(){  
    return title;  
}  

string Film::getGenre(){  
    return genre;  
}  

int Film::getLength(){  
    return length;  
}  

// Setters  
void Film::setTitle(string t){  
    title = t;  
}  

void Film::setGenre(string g){  
    genre = g;  
}  

void Film::setLength(int l){  
    length = l;  
}**
