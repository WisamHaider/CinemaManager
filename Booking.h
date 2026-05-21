//
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

#endif