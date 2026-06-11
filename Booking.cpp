//
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

Booking::Booking(string customer,string film,string date,string time,int adult,
    int child,int student,int senior,string payment)
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
}